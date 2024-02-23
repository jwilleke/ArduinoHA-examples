# DFR0762-IO-shield

Specially designed for FireBeetle 2 series, this Gravity IO expansion shield offers various ports including digital, analog, I2C, UART, SPI, etc. Also, it comes with power input socket for connecting external power supply as well as EN pin for cutting off the power supply to main-board. The Gravity IO shield allows a convenient connection between DFRobot Gravity sensors and FireBeetle 2 series, no soldering required.

Used for our [Grow System](https://github.com/users/jwilleke/projects/2) within the [Grow-Tent](https://github.com/jwilleke/Grow-Tent)

![DFR0762-IO-shield](/resources/DFR0762-IO-shield.png)


## Features

- Support FireBeetle 2.0 series mainboards, including M0 and ESP32-E.
- Support the pin sequence of Gravity series products.
- Support in-line SD card module.
- Support GDI display interface
- Support external power socket
- EN pin mainboard power switch

## Specifications

- 12 groups of digital ports
- 5 groups of analog ports
- 3 groups of I2C ports in parallel
- 1 group of UART ports
- 1 group of SPI ports
- 1 group of sp ports
- GDI display interface
- External power supply cable socket
- EN jumper wire
- Dimension: 60 mm×25.4 mm/2.36×1.00"
- Fixed Hole Diameter: 2.0 mm/0.08"

## Digital ports

This IO expansion shield provides 12 groups of digital ports including 0~13 except 4 and 8, which can be used directly by IO number.

Note: When ESP32 uses pins in the Arduino environment, you need to use Dx such as D0 instead of directly using IO number 0, or use IO number corresponding to the mainboard.

![Digital ports](/resources/DFR0762-IO-shield-digital.png)

## Analog ports

This IO expansion shield provides 5 groups of analog ports including A0~A4, which can be used directly by IO number.

![Analog ports](/resources/DFR0762-IO-shield-analog.png)

## I2C ports

This shield provides 3 groups of I2C ports in parallel.

![Analog ports](/resources/DFR0762-IO-shield-ic2.png)

## UART ports

This shield provides 1 group of UART ports. R corresponds to pin 0, T to pin 1. When using UART, please do not use pin 0 and pin 1.

![UART ports](/resources/DFR0762-IO-shield-uart.png)

## SPI ports

This shield provides 1 group of SPI ports, supporing to use SD card module in-line, and SS is connected to pin 6.

![SPI ports](/resources//DFR0762-IO-shield-spi.png)

## SP pin

The SP pin presents different functions on different mainboards, representing NC, RXD, TXD, A5 on M0, and I2C on ESP32-E.

![SP pin](/resources/DFR0762-IO-shield-sp.png)

## GDI display interface

This interface is a DFRobot dedicated GDI, with 18pin-FPC cable connection and single wire connection to the screen, providing you with the simplest way to use the screen.

The following is a list of pins used by the GDI interface:

| FPC PINS Standard | IO Expansion Shield Line Sequence
| ---- | ---- |
VCC display power | 3.3 V
BLK display backlight | 12/D13
GND | GND
SCIK SPI clock | 18/SCK
MOSI SPI host output | 23/MOSI
MISO SPI host input | 19/MISO
DC data/command | 25/D2
RES reset | 26/D3
CS display chip select | 14/D6
SDCS SD card chip select | 13/D7
FCS font library chip select | 0/D5
TCS touch chip select | 4/D12
SCL I2C clock | 22/SCL
SDA I2C data | 21/SDA
INIT initialization | 16/D11
BUSY-TE anti-tear pin | 17/D10
X1 extensible pin 1 | NC
X2 extensible pin 2 | NC

When using the FPC to connect to the screen, configure the corresponding pin number according to the GDL demo, usually only three pins are required for configuring.

Displays supporting GDI:

- 1.54 in 240x240 IPS TFT LCD Display with MicroSD Card
- 2.0 in 320x240 IPS TFT LCD Display with MicroSD Card
- 2.8 in 320x240 TFT LCD Resistive Touchscreen with MicroSD Card Slot
- 3.5 in 480x320 TFT LCD Capacitive Touchscreen with MicroSD Card Slot

For specific usage, please refer to: GDL display wiki: <https://wiki.dfrobot.com/2.0_Inches_320_240_IPS_TFT_LCD_Display_with_MicroSD_Card_Breakout_SKU_DFR0664>

## Power socket and EN switch

![Power socket and EN switch](/resources/power-socket-en.png)

__Note: When VIN is connected to an external power supply, do not connect the main control to other power supply or USB.__

- VIN: Connect to the VCC pin on the mainboard. The terminal is convenient for connecting the spiral battery.
- GND: Common ground
- EN: It can be designed as the maincontroller switch. When EN is grounded, the main controller will stop running.
