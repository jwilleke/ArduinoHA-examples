# Inter-Integrated Circuit (I2C) Protocol

Allows the communication between devices or sensors connected via Two Wire Interface Bus.

## Introduction

A good way of adding complexity of features to your projects without adding complexity of wiring, is to make use of the Inter-integrated circuit (I2C) protocol. The I2C protocol is supported on all Arduino boards. It allows you to connect several peripheral devices, such as sensors, displays, motor drivers, and so on, with only a few wires. Giving you lots of flexibility and speeding up your prototyping, without an abundancy of wires. Keep reading to learn about how it works, how it is implemented into different standards, as well as how to use the Wire Library to build your own I2C devices.

## Arduino I2C Pins

Below is a table that lists the different board form factors and what pins are for I2C.

|Form factor | SDA | SCL | SDA1 | SCL1 | SDA2 | SCL2 |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | 
| UNO | SDA/A4 | SCL/A5 | - | - | - | - |
| Nano | A4 | A5 | - | - | - | - |
| MKR | D11 | D12 | - | - | - | - |
| GIGA | D20 | D21 | D102 | D101 | D9 | D8
| Mega & Due | D20 | D21 | - | - | - | - |

## I2C Wiring

Below you'll find a couple ways to wire I2C breakout modules. Which way is best depends on each module, and your needs.

Breakout Boards
Some brekout board modules let you wire them directly, with bare wires on a breadboard. To connect a module like this to your Arduino board, connect it as follows:

- VCC* - 5V/3V3 pin (depending on breakout module)
- GND* - GND
- SDA - SDA
- SCL - SCL

*Pin name might vary depending on what module, VCC might be named "VIN", "+", etc. GND might be named "-".

Here's an example of how you might connect a sensor to an UNO R4 WiFi:

## I2C - Wire Library

IC2 uses the [Wire.h library]() for most projects.

The Wire library implementation uses a 32 byte buffer, therefore any communication should be within this limit. Exceeding bytes in a single transmission will just be dropped.

To use this library:

``` c++
#include <Wire.h>
```

## Documentation

[More Details](https://docs.arduino.cc/learn/communication/wire#what-is-i2c)
