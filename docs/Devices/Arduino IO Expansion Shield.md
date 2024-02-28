# Arduino IO Expansion Shield V7.1 SKU:DFR0265 Brand:DFRobot

[IO Expansion Shield for Arduino V7.1 SKU:DFR0265 Brand:DFRobot](https://www.dfrobot.com/product-1009.html)

Used for our [Grow System](https://github.com/users/jwilleke/projects/2) within the [Nutrient-Tank](https://github.com/jwilleke/Nutrient-Tank)

The IO Expansion Shield for Arduino V7.1 is used on the [Arduino UNO R4 WiFi (ABX00087)](Arduino%20UNO%20R4%20WiFi%20(ABX00087).md)

## INTRODUCTION

If you are worried about the chaotic tangle of wires on a breadboard or intimidated by the trepidation of soldering holes on a perforated board, then you've come to the right place. Gravity, a set of electronic module interface specifications formulated by DFRobot, provides the solution you need. By utilizing the Arduino Gravity IO expansion board in conjunction with Gravity modules, you can effortlessly establish connections with a single cable. Whether analog, digital, or I2C modules, easily identified wiring colors liberate you from the tension that precedes every power-on moment. There is no need for wire strippers or soldering irons to experience the enchantment of Arduino. Furthermore, it is compatible with both the Arduino UNO R3 and Arduino UNO R4.

### Overview

![Overview](/resources/IO%20Expansion%20Shield%20V7-overview.png)

### FEATURES

- 3.3V/5V operating voltage select
- Switch for wireless communication & programme
- More Easily recognitive interfaces
- Colorful header for illustrating digital or analog pins
- Immersion gold surface
- Digital Pins x 14 (contains 6 PWM pins)
- Analog Pins x 6

### SPECIFICATION

- Input Voltage
  - 7-12V, PWR_IN
  - 4.8-6V, SERVO_PWR, depending on your servo
- Compatible module voltage: 5V/3.3V
- Support interface: I2C, SPI, Xbee (Xbee pro), Bluetooth, APC220

### Analog Conntion Diagram

![Analog Conntion Diagram](/resources/IO%20Expansion%20Shield%20V7-Anlog-Sensor_Connection_Diagram.png)

### Digital Conntion Diagram

![Digital Conntion Diagram](/resources/IO%20Expansion%20Shield%20V7-Digitial-Diagram_en.png)

### Schmetic

[Schmetic PDF](/resources/IO%20Expansion%20Shield%20V7-schemetic.pdf)

Special description of the color distinction of pins:

| Color | Function |
| --- | --- |
| Green | Digital Signal |
| Blue | Analog Signal |
| Red | VCC(+) |
| Black | GND(-) |

## Features

Switch to RUN/PROG The new extension board adds a switch to Run and Download the program. When you download the code, please dial it to "PROG". When running, dial it to the "RUN". Users who have used V5 may know that when using XEee these communication modules, because of serial usage conflicts, we need to unplug the communication module to download the code. While in the 7.0 version, we just need to dial the switch.

## Available Power Situations

### Jumper 3.3V/5V

VCC pin voltage is determined by Jumper to choose VCC pins is 5V or 3.3V. Makes it is easy to power sensors that require a 3.3V power supply. If there is no jumper cap, the VCC pin output voltage is 0.

The power supply of the I2C interface on the Shield is ALWAYS 5V.

### 3.3V Output

A stable 3.3V Output pins is maintained regardless of VCC pin voltage.

### PWR_IN External input power supply (6~12V)

External input power supply connected to PWR_IN can range from 6~12V.

### SERVO_PWR (5~12V)

The Independent Servo Power input of the digital pin is connected to SERVO_PWR, and SERVO_PWR supplies 5~12V. After the servo power input interface is powered.

> SERVO_PWR will __only power the D0 to D13 digital pins__, but not the board.

This allow more current to be supplied to the D0 to D13 digital pins when xexcessive use for motors etc.

## Pin header specifications

- xh2.54mm

## RUN/PROG

Switch to RUN/PROG The new extension board adds a switch to Run and Download the program. When you download the code, please dial it to "PROG". When running, dial it to the "RUN". Users who have used V5 may know that when using XEee these communication modules, because of serial usage conflicts, we need to unplug the communication module to download the code.
