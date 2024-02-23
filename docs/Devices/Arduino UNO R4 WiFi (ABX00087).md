# Arduino UNO R4 WiFi (ABX00087)

Arduino UNO R4 WiFi [ABX00087]

Used for our [Grow System](https://github.com/users/jwilleke/projects/2) within the [Nutrient-Tank](https://github.com/jwilleke/Nutrient-Tank)

The Ardunio monitors the "Nurtient tank" and therefore what is fed to the Hydronic gorwth system and is used to monitor the soil planted plants and monitors:

- Water level of "nutriant tank"
- Temperautre of "nutriant tank"
- pH of "nutriant tank"
- EC of "nutriant tank"
- ORB of "nutriant tank"
- Temperautre of "nutriant tank"
- Temperautre of "nutriant tank"

[purchased Nov 29, 2023](https://www.amazon.com/dp/B0C8V88Z9D)

## Overview

- Renesas RA4M1 - ESP32-S3
- Wi-Fi 802.11 b/g/n
- Bluetooth 5.0
- USB-C 2.0
- CAN
- I2C
- SPI
- UART
- Amazon B0C8V88Z9D

- The Arduino UNO R4 WiFi combines the processing power and exciting new peripherals of the RA4M1 microcontroller from Renesas with the wireless connectivity power of the ESP32-S3 from Espressif. On top of this, the UNO R4 WiFi offers an on-board 12x8 LED matrix, Qwiic connector, HID support, VRTC, and OFF pin, covering all potential needs makers will have for their next project.
- Expanded memory and faster clock with extra on-board peripherals: The UNO R4 WiFi empowers you with increased memory and a faster clock speed, enabling more precise calculations, effortless handling of complex projects, and the ability to tackle demanding tasks with ease. Additionally, it introduces a range of on-board peripherals, including a 12-bit DAC, CAN BUS, OP AMP, OFF pin, VRCT pin and Qwiic connector, providing expanded capabilities and design flexibility.
- Hardware compatibility with UNO hardware and larger input voltage range: The UNO R4 WiFi maintains hardware compatibility with the UNO form factor and operates at 5V. It now supports a wider input voltage range, up to 24V, enabling seamless integration with motors, LED strips, and other actuators. This allows for easy porting of projects developed with previous UNO form factor boards and simplifies projects by utilizing a single power source.
- Wi-Fi/Bluetooth and Arduino Cloud compatibility: The UNO R4 WiFi combines an ESP32-S3 coprocessor for seamless Wi-Fi and Bluetooth connectivity. It frees up the RA4M1 microcontroller for other tasks. With built-in Wi-Fi and Bluetooth, makers can create IoT projects, benefiting from standardized APIs and existing projects. The UNO R4 WiFi is fully compatible with Arduino Cloud, allowing remote data storage, interactive dashboards, Over-the-Air uploads, and variable sharing among boards.
- LED matrix creativity: The UNO R4 WiFi boasts a vibrant 12x8 red LED matrix (96 dots) perfect for creative projects, animating visuals or plotting sensor data, all without requiring extra hardware. Users can utilize the provided API and tutorials for manual LED control via sketch code. Access a gallery of pre-made animations and leverage our online tool for easy creation of custom visual effects.

| Board | Arduino UNO REV4 WiFi |
| --- | ----------- |
| Renesas RA4M1 - ESP32-S3 | - |
| Wi-Fi| 802.11 b/g/n |
| Bluetooth | 5.0 |
| USB-C | 2.0 |
| CAN | Yes |
| I2C | Yes |
| SPI | Yes |
| UART | Yes |
| Microcontroller| Renesas RA4M1 (Arm Cortex-M4 with Floating Point Unit) |
| Wireless connectivity | Yes |
| Connectors | USB-C (with HID support) |
| Operational voltage | 5 V (ESP32-S3 is 3.3 V) |
| Voltage range| 6-24 V |
| Memory | 256 kB Flash, 32 kB RAM (RA4M1) - 384 kB ROM, 512 kB SRAM (ESP32-S3) |
| Clock | 48 MHz (RA4M1) - up to 240 MHz (ESP32-S3) |
| Pinout | 14 digital I/O pins <br> 6 analog input pins <br> 1 DAC (12 bit)  <br> 6 PWM  <br> 1 CAN BUS  <br> 1 OP AMP <br> OFF pin  <br> VRTC pin |
| QWIIC connector | Yes |
| Misc | LED matrix (12x8 - red) |

## Other Technical Details

| Title| Description |
| --- | ----------- |
| Brand | Arduino |
| Item model number| ABX00087 |
| Item Weight | 1.41 ounces |
| Product Dimensions | 3.15 x 7.87 x 10.24 inches |
| Item Dimensions LxWxH | 3.15 x 7.87 x 10.24 inches |
| Number of Processors | 1 |
| Manufacturer | Arduino |
| ASIN | B0C8V88Z9D |
| Country of Origin | Italy |
| Date First Available | June 21, 2023 |

## Arduino UNO R4 WiFi (ABX00087) Pins

![Pins](/resources/ardunio-UNO-4-wifi-pinouts-001.png)

### Pin Short List

The UNO R4 WiFi gives you access to many different pins and many of them have special features that will be accounted for in the upcoming sections of this article. Keep reading to learn what you can do with them.

If you just need a quick overview of the pins functionality, this is a full table of all the IO pins on the UNO R4 WiFi.

| Pin | Type | Function |
| --- | ---- | ---- |
| D0 | Digital | UART Receive |
| D1 | Digital | UART Transmit |
| D2 | Digital | GPIO pin, Interrupt |
| D3 | Digital | GPIO pin, Interrupt, [PWM](/docs/ardrunio-basics/pwm.md) |
| D4 | Digital | GPIO pin |
| D5 | Digital | GPIO pin, [PWM](/docs/ardrunio-basics/pwm.md) |
| D6 | Digital | GPIO pin, [PWM](/docs/ardrunio-basics/pwm.md) |
| D7 | Digital | GPIO pin |
| D8 | Digital | GPIO pin |
| D9 | Digital | GPIO pin, [PWM](/docs/ardrunio-basics/pwm.md) |
| D10 | Digital | [SPI (CS)](/docs/ardrunio-basics/%20Serial%20Peripheral%20Interface%20(SPI).md), GPIO pin, [PWM](/docs/ardrunio-basics/pwm.md) |
| D11 | Digital | [SPI (COPI)](/docs/ardrunio-basics/%20Serial%20Peripheral%20Interface%20(SPI).md), GPIO pin, [PWM](/docs/ardrunio-basics/pwm.md) |
| D12 | Digital | [SPI (CIPO)](/docs/ardrunio-basics/%20Serial%20Peripheral%20Interface%20(SPI).md), GPIO pin |
| D13 | Digital | [SPI (SCK)](/docs/ardrunio-basics/%20Serial%20Peripheral%20Interface%20(SPI).md), GPIO pin, Built-in LED |
| A0 | Digital | Analog In, DAC |
| A1 | Analog in | Analog In, OPAMP + |
| A2 | Analog in | Analog In, OPAMP - |
| A3 | Analog in | Analog In, OPAMP OUT |
| A4 | Analog in | Analog In, SDA* |
| A5 | Analog in | Analog In, SCL* |

> A4 and A5 pins are both connected to the same I2C bus.

### Analog Pins

The UNO R4 WiFi has six analog input pins (A0-A5) that can be read by using the analogRead() function.

| Pin | Type | Function |
| ---- | ---- | ---- |
| A0 | Analog | Analog In, DAC |
| A1 | Analog | Analog In, OPAMP + |
| A2 | Analog | Analog In, OPAMP - |
| A3 | Analog | Analog In, OPAMP OUT |
| A4 | Analog | Analog In, SDA* |
| A5 | Analog | Analog In, SCL* |

> A4 and A5 pins are both connected to the same I2C bus.

Typical operation on Analog pins

``` c++
value = analogRead(pin);
```

The default reference voltage of these pins is 5 V, but this can be changed as follows:

``` c++
analogReference(AR_DEFAULT) (Default reference of 5 V)
analogReference(AR_INTERNAL) (Built in reference of 1.5 V.)
```

#### Analog-to-Digital Converter (ADC)

An analog-to-digital converter (ADC) transforms an analog signal to a digital one. The standard resolution on Arduino boards is set to 10-bit (0-1023). The UNO R4 WiFi supports up to 14-bit resolutions, which can provide a more precise value from analog signals.

To update the resolution, you will only need to use the analogReadResolution() command.

To use it, simply include it in your setup(), and use analogRead() to retrieve a value from an analog pin.

The default resolution is set to 10-bit, but can be updated to 12 and 14-bit resolutions. To do so, use the following method in the setup() of your sketch.

``` c++
analogReadResolution(10) (default)
analogReadResolution(12)
analogReadResolution(14)
```

``` c++
void setup(){
  analogReadResolution(14); //change to 14-bit resolution
}

void loop(){
  int reading = analogRead(A3); // returns a value between 0-16383
}
```

### OPAMP Pins

An operational amplifier (OP-AMP) is an integrated circuit (IC) that amplifies the difference in voltage between two inputs. It is so named because it was developed for perform arithmetic operations.

The RA4M1 has an internal OPAMP that is exposed on the UNO R4 WiFi as follows:

| Pin | OPAMP |
| ---- | ---- |
| A1 | OPAMP + |
| A2 | OPAMP - |
| A3 | OPAMP OUT |

### Digital Pins

The UNO R4 WiFi features a total of digital 14 pins. Though some of them serve another purpose and shouldn't be used for GPIO if you have other pins available.

| Pin | Function | Notes |
| ---- | ---- | ---- |
| 0 | RX | Serial communication|
| 1 | TX | Serial communication|
| 2 | GPIO | Digital IO pin|
| 3 | [PWM](/docs/ardrunio-basics/pwm.md) | Digital IO pin, [PWM](/docs/ardrunio-basics/pwm.md)|
| 4 | GPIO | Digital IO pin|
| 5 | [PWM](/docs/ardrunio-basics/pwm.md) | Digital IO pin, [PWM](/docs/ardrunio-basics/pwm.md)|
| 6 | [PWM](/docs/ardrunio-basics/pwm.md) | Digital IO pin, [PWM](/docs/ardrunio-basics/pwm.md)|
| 7 | GPIO | Digital IO pin|
| 8 | GPIO | Digital IO pin|
| 9 | [PWM](/docs/ardrunio-basics/pwm.md) | Digital IO pin, [PWM](/docs/ardrunio-basics/pwm.md)|
| 10 | [PWM](/docs/ardrunio-basics/pwm.md) | Digital IO pin, [PWM](/docs/ardrunio-basics/pwm.md)|
| 11 | [PWM](/docs/ardrunio-basics/pwm.md) | Digital IO pin, [PWM](/docs/ardrunio-basics/pwm.md)|
| 12 | GPIO | Digital IO pin|
| 13 | GPIO | Digital IO pin |

> The reference voltage of all digital pins is 5 V.

### PWM

PWM (Pulse Width Modulation) capability allows a digital pin to emulate analog output by flickering on and off very fast letting you, among other things, dim LEDs connected to digital pins.

The value parameter is used to change the duty cycle but the [PWM](/docs/ardrunio-basics/pwm.md) frequency which is fixed at usually 490 Hz and can not be changed. However, Arduino UNO R4 provides some easy to use PwmOut class which provides more flexibility: The period needs to be defined in microseconds, so if you want to request a defined frequency in hz you can easily calculate this and there is a method to set the duty cycle using percent.

There are three such Timer/Counter registers:

- TCCR0B - 490.20 Hz (the default)
- TCCR1B - 976.56 Hz (the default)
- TCCR2B - 490.20 Hz (the default)

Since there are three different prescalers, the six PWM pins are broken up into three pairs, each pair having its own prescaler. For instance, Arduino pins 6 and 5 are both controlled by TCCR0B, so you can set Arduino pins 6 and 5 to output a PWM signal at one frequency. Arduino pins 9 and 10 are controlled by TCCR1B, so they can be set at a different frequency from pins 6 and 5. Arduino pins 11 and 3 are controlled by TCCR2B, so they may be set at a third frequency. But you can't set different frequencies for pins that are controlled by the sameprescaler (e.g. pins 6 and 5 must be at the same frequency).

The UNO R4 WiFi supports [PWM](/docs/ardrunio-basics/pwm.md) on pins marked with ~ on the headers. Officially supported PWM pins are:

| Pin | RA4M1 | Timer| Prescaler | Frequency |
| ---- | ---- | ---- | ---- | ---- |
| D3 | P105 | GTIOC1A| TCCR2B | 490.20 Hz |
| D5 | P107 | GTIOC0A| TCCR0B | 976.56 Hz |
| D6 | P111 | GTIOC3A| TCCR0B | 976.56 Hz |
| D9 | P303 | GTIOC7B| TCCR1B | 490.20 Hz |
| D10 | P103 | GTIOC2A| TCCR1B | 490.20 Hz |
| D11 | P411 | GTIOC6A| TCCR2B | 490.20 Hz |

> Please note that the following pins are [PWM](/docs/ardrunio-basics/pwm.md) capable but may interfere with other functionalities of the UNO R4 WiFi board. When writing library functions, please do not use this as they are not officially supported [PWM](/docs/ardrunio-basics/pwm.md) pins.

## Built-in LED Matrix

The Built-in LED Matrix on the UNO R4 WiFi is available to use in your program, to display still graphics, animations, or even play games on. The UNO R4 Board Package includes the [Arduino_LED_Matrix library](https://github.com/arduino/ArduinoCore-renesas/tree/main/libraries/Arduino_LED_Matrix) for displaying frames on the matrix.

To learn about the LED matrix in depth, check out the

- [LED Matrix Guide](https://docs.arduino.cc/tutorials/uno-r4-wifi/led-matrix/)
- [Control an 8x8 matrix of LEDs](https://docs.arduino.cc/built-in-examples/display/RowColumnScanning)
- [LED Matrix Editior](https://ledmatrix-editor.arduino.cc/)

``` c++
Arduino_LED_Matrix matrix; // - Initialises a LED matrix.
Arduino_LED_Matrix.load(); // - Loads a frame into the frame buffer. Here's a basic example:

// creates an array of two frames
const uint32_t frames[][4] = {
  {
    0x0,
    0x0,
    0xc00c0000,
    150
  },
  {
    0x0,
    0x1e01,
    0x201201e0,
    150
  }
}
  // loads the frames into the matrix buffer
  matrix.load(frames);
```

## DAC

The UNO R4 WiFi also has a DAC (pin A0) with up to 12-bit resolution, that can act as a genuine analog output pin which means it's even more capable than PWM pins.

``` c++
analogWrite(pin, value);
DAC Pin
DAC Pin
```

This DAC pin has a default write resolution of 8-bits. This means that values that are written to the pin should be between 0-255.

However you may change this write resolution if you need to, to up to 12-bits, and in this case the values you write to the pin should be between 0-4096.

``` c++
analogWriteResolution(12);
```

To learn more about the DAC capabilities of the UNO R4 WiFi, check out the [DAC Guide](https://docs.arduino.cc/tutorials/uno-r4-wifi/dac).

## RTC

A real-time clock (RTC) is used to measure the time, and is useful in any time-tracking applications.

> The UNO R4 WiFi features a VRTC pin, that is used to keep the onboard RTC running, even when the boards power supply is is cut off. In order to use this, apply a voltage in the range of 1.6 - 3.6 V to the VRTC pin.

Below is a minimal example that shows how to obtain the date and time from the RTC:

``` c++
#include "RTC.h"

void setup() {
  Serial.begin(9600);

  RTC.begin();
  RTCTime mytime(30, Month::JUNE, 2023, 13, 37, 00, DayOfWeek::WEDNESDAY, SaveLight::SAVING_TIME_ACTIVE);

  RTC.setTime(mytime);
}

void loop() {
  RTCTime currenttime;

 // Get current time from RTC
  RTC.getTime(currenttime);
  
  // Print out date (DD/MM//YYYY)
  Serial.print(currenttime.getDayOfMonth());
  Serial.print("/");
  Serial.print(Month2int(currenttime.getMonth()));
  Serial.print("/");
  Serial.print(currenttime.getYear());
  Serial.print(" - ");

  // Print time (HH/MM/SS)
  Serial.print(currenttime.getHour());
  Serial.print(":");
  Serial.print(currenttime.getMinutes());
  Serial.print(":");
  Serial.println(currenttime.getSeconds());

  delay(1000);
}
```

To learn more about the RTC capabilities of the UNO R4 WiFi, check out the [RTC Guide](https://docs.arduino.cc/tutorials/uno-r4-wifi/rtc).

## Device on I2C Bus

The number of [I2C](https://github.com/jwilleke/grow-system/blob/master/docs/ardrunio-basics/I2C.md) devices you can have on an Arduino UNO R4 WiFi depends on a few factors:

### Technically

Number of addresses: I2C uses 7-bit addresses, meaning there are 128 theoretical addresses available (0x00 - 0x7F). So, in theory, you could have up to 128 devices on one bus.

### Shared pins

The UNO R4 WiFi has only one I2C bus that shares pins A4 (SDA) and A5 (SCL) with other functionalities. This means conflicting usage can limit the number of devices.

### Power supply

Each device draws power, and exceeding the board's capacity can cause issues.
Data speed and complexity: Sending and receiving data takes time and processing power. Many devices or complex communication can overwhelm the Arduino.
Therefore:

### Additional I2C bus

The UNO R4 WiFi has a second I2C bus connected to the Qwiic connector. Using this can expand your capacity significantly, as long as compatible libraries and connectors are used.
Here are some tips for maximizing your I2C device count

> Quick connector utilizes the Uno secondary I2C bus which uses the [1-Wire](/docs/ardrunio-basics/1-Wire%20Protocol.md) protocol instead of the typical [I2C](https://github.com/jwilleke/grow-system/blob/master/docs/ardrunio-basics/I2C.md) 2-wire prtotocl.

### Realistically

While 128 is the technical limit, having 10-20 devices on a single bus is usually the practical maximum before encountering limitations.

- Use low-power devices.
- Minimize data exchanges and complexity.
- Consider using I2C multiplexers to expand beyond one bus.
- Start with fewer devices and add more as you test and ensure stability.

Ultimately, the best number of devices for your project will depend on your specific needs and the capabilities of your chosen devices. It's always best to test and monitor your setup to ensure it functions smoothly.

## Wi-Fi

Wi-Fi® support is enabled via the built-in WiFiS3 library that is shipped with the Arduino UNO R4 Board Package. Installing the Board Package automatically installs the WiFiS3 library.

[UNO R4 WiFi Network Examples](https://docs.arduino.cc/tutorials/uno-r4-wifi/wifi-examples)

## Arduino UNO R4 WiFi VRTC & OFF Pins

The Arduino UNO R4 WiFi features 2 pins that have not been seen before on UNO boards, the VRTC pin and the OFF pin.

They are used to control some of the boards electrical functions.

- VRTC pin can be used to keep the onboard RTC (Real Time Clock) running even when the boards main power supply is turned off
- OFF pin is used to turn off the board by cutting off the power

This appears to work only from the power jack and not with the USB power.

Appears the VRTC & OFF Pins are __NOT__ exposed to the [IO Expansion Shield for Arduino V7.1](/docs/Devices/IO%20Expansion%20Shield%20for%20Arduino.md)

## Other docunmentation

- [UNO R4 WiFi](https://docs.arduino.cc/hardware/uno-r4-wifi/)

- [Pinout (PDF)](https://docs.arduino.cc/resources/pinouts/ABX00087-full-pinout.pdf)
- [Datasheet (PDF)](https://docs.arduino.cc/resources/datasheets/ABX00087-datasheet.pdf)
- [Schematics (PDF)](https://docs.arduino.cc/resources/schematics/ABX00087-schematics.pdf)
- [Arduino UNO R4 WiFi Cheat Sheet](https://docs.arduino.cc/tutorials/uno-r4-wifi/cheat-sheet/)