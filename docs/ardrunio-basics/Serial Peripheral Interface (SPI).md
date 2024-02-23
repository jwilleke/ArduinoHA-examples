# Serial Peripheral Interface (SPI) Communication Protocol

Serial Peripheral Interface (SPI) is a synchronous serial data protocol used by microcontrollers for communicating with one or more peripheral devices quickly over short distances.

Serial Peripheral Interface was developed by Motrorola in the 1980s and offers speed improvments over [IC2](/docs/I2C.md) and [1-Wire](/docs/1-Wire%20Protocol.md)

Controller/peripheral is formerly known as master/slave. Arduino no longer supports the use of this terminology. See the table below to understand the new terminology:

| Master/Slave (OLD) | Controller/Peripheral (NEW) |
| ---- | ---- |
| Master In Slave Out (MISO) | Controller In, Peripheral Out (CIPO) |
| Master Out Slave In (MOSI) | Controller Out Peripheral In (COPI) |
| Slave Select pin (SS) | Chip Select Pin (CS) |

SPI is:

- Synchronous
- Follows a master-slave model, where there is one master device and multiple slave devices
- More than two lines required for implementation
- full-duplex

The hardware connection diagram for SPI is slightly more complicated, and looks something like this:

![SPI Connection](/resources/spi-connection-diagram-01.jpg)

- MOSI (“Master Out Slave In”): Data transmission line from master to slave
- SCK (“Clock”): Clock line defining transmission speed and transmission start/end characteristics
- SS (“Slave Select”): Line for master to select a particular slave to communicate with
- MISO (“Master In Slave Out”): Data transmission line from slave to master

The first feature about SPI to note is that it follows a master-slave model.  This means that the communication relies on defining one device as a master, and other devices as slaves.  This creates a hierarchy between the devices signifying which device is effectively “in control” of the others.  We’ll discuss this master-slave model shortly when we describe what a sample communication between a master and slave device might look like.

We noted earlier that multiple slaves can be connected to a single master device.  The hardware diagram for such a system might look something like this:

![Multiple-slaves connected to a single master](/resources/spi-multiple-slaves-02.jpg)

SPI does not require a separate transmit and receive line for each slave that is connected to the master.  One common receive line (MISO) and one common transmit line (MOSI), along with one common clock (SCK) line are connected between all the slaves and the master.  The master device decides which slave it is communicating with through a separate SS line for each slave.  This means that each additional slave that the master communicates with requires another GPIO pin on the master’s side.

SPI is synchronous, which means that communication between master and slave is closely tied to a clock signal (a square wave of fixed-frequency) defined by the master device.  Here we see one of the direct effects of the master-slave model.  The master device drives the communication by specifying the communication speed through the clock signal, and the slaves respond by communicating at that speed.  This definition of speed works for any communication speed the master decides on (within the maximum speed tolerable by the slave devices).  

In SPI, two specific features of the clock signal determine the start and end of data transmission: the clock polarity (CPOL) and clock phase (CPHA).  CPOL refers to the idle state (either low or high) of the clock signal.  To conserve power, devices will put the clock line at the idle state when not communicating with any slaves, and the two options available for this idle state are either low or high.  CPHA refers to the edge of the clock signal upon which data is captured.  A square wave has two edges (the rising edge and the falling edge), and depending on the CPHA setting, data is captured either on the rising edge or the falling edge.

Now we’ll focus on SPI implementation on the Arduino using the Arduino as the master device (SPI.h).  The SPI digital pin connections for SCK, MOSI, and MISO are predefined on Arduino boards.  For the Arduino Uno, the connections are as follows:

- SCK: GPIO 13 or ICSP 3
- MOSI: GPIO 11 or ICSP 4
- MISO: GPIO 12 or ICSP 1
- SS: GPIO 10

Any digital pin can be also used for the SS pin.  To select the device, this digital pin must be driven low.  

SPI is full-duplex, which means that communication always occurs bidirectionally, even if the application only requires data transfer occur in one direction.  SPI full-duplex data transfer is usually implemented with a shift register. (Check out the appendix for a tutorial on shift registers!)  This means that as each bit is read, the bits before it are shifted over by one place. The foremost bit is subsequently popped off and sent back through the SPI connection to the other device!

## Library

Serial Peripheral Interface (SPI) typically [include the "SPI.h" file](https://github.com/arduino/ArduinoCore-avr/tree/master/libraries/SPI).
