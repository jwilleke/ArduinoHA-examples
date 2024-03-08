# 1-Waire Protocol

1-Wire communication is a protocol operating through one wire between the controller device and the peripheral device. This article covers the basics of using the 1-Wire protocol with an Arduino with the help of the OneWire library. The following sections provide information about the 1-Wire protocol, interface, power, addressing devices, reading devices and finally a short glimpse into the library's history.

Dallas Semiconductor (now Maxim) produces a family of devices that are controlled through a proprietary 1-Wire protocol. There are no fees for programmers using the Dallas 1-Wire (trademark) drivers.

On a 1-Wire network, which Dallas has dubbed a "MicroLan" (trademark), a single controller device communicates with one or more 1-Wire peripheral devices over a single data line, which can also be used to provide power to the peripheral devices. (Devices drawing power from the 1-wire bus are said to be operating in parasitic power mode.) Tom Boyd's guide to 1-Wire may tell you more than you want to know, but it may also answer questions and inspire interest.

The 1-Wire temperature sensors have become particularly popular, because they're inexpensive and easy to use, providing calibrated digital temperature readings directly. They are more tolerant of long wires between sensor and Arduino. The sample code below demonstrates how to interface with a 1-Wire device using Jim Studt's OneWire Arduino library, with the DS18S20 digital thermometer as an example. Many 1-Wire chips can operate in both parasitic and normal power modes.

## 1-Wire Interfaces

Here's a summary of why daisy chaining works with 1-wire:

### Shared data line

Unlike traditional communication protocols that require dedicated I/O pins for each device, 1-wire devices utilize a single data line for communication. This shared bus, called the 1-wire bus, allows connection of multiple devices to a single digital IO pin.

### Unique addressing

Each 1-wire device has a unique 64-bit address. This address enables the master device (like your Arduino) to identify and communicate with specific devices on the shared bus.

### Master-slave communication

The master device initiates communication by sending a command and specifying the desired address on the bus. Only the targeted device with the matching address responds, while other devices on the bus remain inactive. This ensures communication efficiency and avoids conflicts.

Therefore, you can connect multiple compatible 1-wire devices in a daisy chain fashion to the same digital I/O pin. The code using the OneWire library can communicate with each device individually by addressing them on the shared bus.

### Dedicated Bus Controller

Dallas/Maxim and a number of other companies manufacture dedicated bus controller for read/write and management of 1-Wire networks. Most of these are listed [here](http://owfs.org/index.php?page=bus-masters)

These devices are specifically designed and optimized to read and write efficiently to 1-Wire devices and networks. Similar to UART/USART controller, they handle clocked operations natively with the use of a buffer, offloading the processing load from the host processor (e.g., sensor gateway or microcontroller) thereby increasing accuracy . External pull-up resistors are also often not required.

Many of the chips provide error-handling that specifically deals with loss of signal integrity, level variation, reflections, and other bus issues that may cause problems, particularly on large networks. Many of the devices have additional features, and are offered on a large variety of interfaces. They range in price from $1 to $30.

Another key advantage is support of , a read/write file system with vast device support for 1-Wire controller that exposes many native functions for a wide variety of 1-Wire device types.

### UART/USART controller

Most UART/USARTs are perfectly capable of sustained speeds well in excess of the 15.4kbps required of the 1-Wire bus in standard mode. More important, the clock and buffering is handled separately, again offloading it from the main process of the microcontroller or main processor. This implementation is discussed [here](http://www.maximintegrated.com/en/app-notes/index.mvp/id/214)

### Bitbanging approaches

Where native buffering/clock management is not available, 1-Wire may be implemented on a general purpose IO (GPIO) pin, where manual toggle of the pin state is used to emulate a UART/USART with reconstruction of the signal from the received data. These are typically much less processor-efficient, and directly impact and are directly impacted by other processes on the processor shared with other system processes.

On Arduino and other compatible chips, this may be done with the OneWire library.

On single-board computers such as the Raspberry Pi, 1-Wire network read is often possible using kernel drivers that offer native support. The w1-gpio, w1-gpio-therm, and w1-gpio-custom kernel mods are included in the most recent distributions of Raspbian and are quite popular, as they allow interfacing with a subset of 1-Wire device with no additional hardware. Currently, however, they have limited device support, and have bus size limitations in software.

## Power Modes

### Parasite power mode

When operating in parasite power mode, only two wires are required: one data wire, and one ground. In this mode, the power line must be connected to ground, per the datasheet. At the controller, a 4.7k pull-up resistor must be connected to the 1-wire bus. When the line is in a "high" state, the device pulls current to charge an internal capacitor.

This current is usually very small, but may go as high as 1.5 mA when doing a temperature conversion or writing EEPROM. When a peripheral device is performing one of these operations, the bus controller must keep the bus pulled high to provide power until the operation is complete; a delay of 750ms is required for a DS18S20 temperature conversion. The controller can't do anything during this time, like issuing commands to other devices, or polling for the peripheral's operation to be completed. To support this, the OneWire library makes it possible to have the bus held high after the data is written.

### Normal Power mode

Normal Power mode makes use of an external power supply, three wires are required:

- the bus wire (data transfer)
- ground
- power  

The 4.7k pull-up resistor is still required on the bus wire. As the bus is free for data transfer, the microcontroller can continually poll the state of a device doing a conversion. This way, a conversion request can finish as soon as the device reports being done, as opposed to having to wait for conversion time (dependent on device function and resolution) in "parasite" power mode.

[For more details on 1-Wire](https://docs.arduino.cc/learn/communication/one-wire)
