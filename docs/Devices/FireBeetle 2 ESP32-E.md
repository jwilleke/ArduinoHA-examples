# FireBeetle 2 ESP32-E

We used: [FireBeetle 2 ESP32-E IoT Microcontroller (Supports Wi-Fi & Bluetooth)](https://www.dfrobot.com/product-2195.html)

Used for our [Grow System](https://github.com/users/jwilleke/projects/2) within the [Grow-Tent](https://github.com/jwilleke/Grow-Tent)

The Firebeetle is used to monitor the soil planted plants and monitors:

- Soil Moisture
- Humidity and temperature of the "grow tent"

If too dry, then water is added to the individual plants.

If humidity is too low then mist is spread into the tent.

If temperature is adjusted by either add heat or turning on a fan.


![FireBeetle 2 ESP32-E Overview](/resources/FireBeetle-2-ESP32-E-Overview.jpg)

## Features

- Compatible with DFRobot FireBeetle V2 Series
- Small Size of 25.4×60 mm
- ESP32 Dual-core low power maincontroller, WiFi+BT4.0
- GDI Display Port, esay to connect
- Onboard Charging Circuit and PH2.0 li-ion Battery Port

## Specifications

- Operating Voltage: 3.3V
- Input Voltage: 3.3V-5.5V (Support USB Charging)
- Processor: Tensilica LX6 dual-core processor (One for high-speed connection; one for independent application development)
- Main Frequency: 240MHz
- SRAM: 520KB
- Flash: 32Mbit
- Wi-Fi Standard: FCC/CE/TELEC/KCC
- Wi-Fi Protocol: 802.11 b/g/n/d/e/i/k/r (802.11n，speed up to 150 Mbps), A-MPDU and A-MSDU Aggregation, support 0.4us guard interval)
- Frequency Range: 2.4-2.5 GHz
- Bluetooth Protocol: Bluetooth v4.2 BR/EDR and BLE standard compliant
- Bluetooth Audio: CVSD and SBC audio
- On-chip Clock: 40MHz crystal, 32.768KHz crystal
- Digital I/O x18
- Analog Input x11
- SPI x1
- IIC x1
- I2S x1
- RGB_LED: WS2812
- Connector: FireBeetle V2 series compatible
- Operating Temperature: -20℃ to +85℃
- Module Size: 25.4 × 60(mm)
- Mount Hole Size: M2, diameter 2.0mm
- Weight: 13g

## FireBeetle 2 ESP32-E Connections

![FireBeetle 2 ESP32-E Connections](/resources/FireBeetle-2-ESP32-E-connections.png)

- ① USB Interface Program download and power supply, 4.75V-5.5V compatible
- ② Charging Indicator Red LED for indicating charging status: 1. Off when fully charged or not charged; 2. On when charging; 3. Quick flash when powered by USB, and no battery connected.
- ③ User Button Controlled by pin IO27/D4
- ④ Li-ion Battery Port Support 3.5V-4.2V
- ⑤ Onboard RGB Light WS2812 RGB LED, controlled by pin IO5/D8
- ⑥ Onboard LED LED controlled by pin IO2/D9
- ⑦ Reset Button Press to reset program
- ⑧ Low-power Solder Jumper Pad Designed for low power mode and default to be connected. Slightly cut off the thin wire with a knife to disconnect it. When disconnected, static power consumption can be reduced by 500 μA. The power consumption can be reduced to 13 μA after controlling the maincontroller to enter the sleep mode through the program. Note: when the pad is disconnected, you can only drive RGB LED light via the USB Power supply.
- ⑨ GDI DFRobot dedicated Display interface. Refer to the GDI part of this page.
- ⑩ ESP32-E Chip [ESP32-WROOM-32E](https://www.espressif.com/sites/default/files/documentation/esp32-wroom-32e_esp32-wroom-32ue_datasheet_en.pdf)

## FireBeetle 2 ESP32-E Pinouts

![FireBeetle 2 ESP32-E Connections](/resources/FireBeetle-2-ESP32-E-pinouts.png)

| Categroy| Description |
| ---- | ---- |
| Control|FireBeetle enable/reset pins
| Touch | Pin with capacitive touch function
| Analog | Analog pin
| Port PIN | Default physical pin number of the chip, which can be used to directly control the corresponding pin
| Arduino IDE | In Arduino IDE, the pin numbers have been remapped by FireBeetle, and you can directly use this symbol to control the corresponding pin
| RTC PIN | FireBeetle 2 ESP32-E supports low power function, and in Deep-sleep mode, only RTC pin keeps working and can be used as a wave-up source. When RTC pin is used as an output pin, it keeps outputting level value when the chip is in Deep-sleep mode, while as an input pin, it can wake up the chip from Deep-sleep.
| GND | Common ground for all power supplies and logics
| Power | When powered by 5V-USB, VCC outputs about 4.7V and 3V3 outputs 3.3V; When powered by 4V li-ion battery, VCC outputs about 4V and 3V3 outputs 3.3V(Actual measurement)

### GPIOs

FireBeetle 2 ESP32-E has up to 24 physical GPIOs, which are mainly for connecting peripherals like sensors, actuators, etc. Meanwhile, these IO pins can be multiplexed for other functions such as UART, SPI, I2C and so on. The table below provides users with a detailed description of FireBeetle 2 ESP32-E GPIO.

| Pin Number | Name | Function | ADC | Communication | Remark |
| ---- | ---- | ---- | ---- | ---- | ---- |
| GPIO 0 | 0/D5 | Used as input or output | ADC2_CH1 |  | Occupied when using USB transmission
| GPIO 1 | 1/TXD | Used as input or output |  | UART0_TX | Occupied when using USB power supply and serial printing
| GPIO 2 | 2/D9 | Used as input or output | ADC2_CH2 |  | For controlling onboard LED by outputting digital signal
| GPIO 3 | 3/RXD | Used as input or output |  | UART0_RX | Occupied when using USB power supply and serial printing
| GPIO 4 | 4/D12 | Used as input or output | ADC2_CH0 |  |
| GPIO 5 | 5/D8 | RGB Light WS2812 RGB LED |  |  | For controlling onboard RGB Light WS2812 RGB LED, controlled by pin IO5/D8
| GPIO 12 | 12/D13 | Used as input or output | ADC2_CH5 |  |
| GPIO 13 | 13/D7 | Used as input or output | ADC2_CH4 |  |
| GPIO 14 | 14/D6 | Used as input or output | ADC2_CH6 |  |
| GPIO 15 | 15/A4 | Used as input or output | ADC2_CH3 |  |
| GPIO 16 | 16/D11 | Used as input or output |  |  |
| GPIO 17 | 17/D10 | Used as input or output |  |  |
| GPIO 18 | 18/SCK | Used as input or output |  | SPI_SCK |
| GPIO 19 | 19/MISO | Used as input or output |  | SPI_MISO |
| GPIO 21 | 21/SDA | Used as input or output |  | I2C_SDA |
| GPIO 22 | 22/SCL | Used as input or output |  | I2C_SCL |
| GPIO 23 | 23/MOSI | Used as input or output |  | SPI_MOSI |
| GPIO 25 | 25/D2 | Used as input or output | ADC2_CH8 |  | DAC_1（Range: 0-255; Output Voltage: 0-3.3V）
| GPIO 26 | 26/D3 | Used as input or output | ADC2_CH9 |  | DAC_2（Range: 0-255; Output Voltage: 0-3.3V）
| GPIO 34 | 34/A2 | Used as input only | ADC1_CH6 |  |
| GPIO 35 | 35/A3 | Used as input only | ADC1_CH7 |  |
| GPIO 36 | 36/A0 | Used as input only |  |  |
| GPIO 39 | 39/A1 | Used as input only

> NOTE:

- It is recommended not to multiplex the pin IO0/D5, IO1/TXD and IO3/RX since they will be occupied when using USB-related function.
- IO34-39 are for input only.
- FireBeetle 2 ESP32-E has two 8-bit DAC channel that converts 2-way digital signal to 2 analog voltage outputs. Two channels can work independently. DAC circuit is composed of built-in resistors in series and a buffer. The two DACs can be used as reference voltage.

## PINs

The FireBeetle 2 ESP32-E has five analog input pins labelled:

- A0 - GPIO36
- A1 - GPIO39
- A2 - GPIO34
- A3  _GPIO32
- A4 - GPIO35

These pins have:

- built-in 12-bit ADC
- a maximum output of 4095, but they can only measure voltages up to around 2.5V instead of the full 3.3V supply voltage.

You can us A5 and A6 pins for other purposes by setting the pin mode:

- A5 - GPIO21
- A6 - GPIO33

``` c++
pinMode(21, OUTPUT); // Set A5 (GPIO21) to output mode
pinMode(22, INPUT); // Set A6 (GPIO32) to input mode
```

Then, you can use these pins for digital I/O, SPI, I2C, or other communication protocols depending on your project requirements.
Remember:

- Ensure your external devices and sensors match the voltage range of the ADC (around 2.5V).
- When using A5 and A6 as GPIOs, you won't be able to use them for analog input anymore.
- Use the appropriate functions and libraries in your code based on your chosen programming language and functionalities.


## Seeking Help

[Fire Beetle ESP32-E UPLOAD Problems MAC](https://forum.arduino.cc/t/fire-beetle-esp32-e-upload-problems-mac/1202674)

## ESPHome Setup

The original intention with the FireBeetle 2 ESP32-E in the Grow-System was to use it as a sensor to report to Home Assitant for Soil Moisture and any of the other more mobile sensors.

The config files for FireBeetle2-ESP32-E in ESPHome [ESPHome/FireBeetle2-ESP32-E-config.yaml](../../ESPHome/FireBeetle2-ESP32-E-config.yaml)

## Other Documentation

- [esphome-air-sensors](https://github.com/makertut/esphome-air-sensors/blob/main/README.md)
- [DIY Home Assistant Air Quality Sensor - espHome custom sensor](https://youtu.be/ZAFYBPJMd2M?si=BpSB7AJZu1RAp9Ug)
- [everything-presence-one-st.yaml](https://github.com/EverythingSmartHome/everything-presence-one/blob/main/everything-presence-one-st.yaml)
- [ESP32-WROOM-32E Chip Datasheet](https://www.espressif.com/sites/default/files/documentation/esp32-wroom-32e_esp32-wroom-32ue_datasheet_en.pdf)