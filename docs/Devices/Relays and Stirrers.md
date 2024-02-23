# Relays and Motor Contollers

## Physical Actuators

Motor and solinoids

- ph Up Motor
- ph Down Motor
- A1 Solution
- A2 Solution
- Nutrient Tank Circulation - AC using IP Addressable Switch in home assistant
- Srirrer for ph Up Motor (Should be PWM)
- Srirrer for ph Down Motor (Should be PWM)
- Srirrer for A1 Solution (Should be PWM)
- Srirrer for A2 Solution (Should be PWM)
- Nutriant Tank fill valve
- Areation for Nutrient Tank - AC using IP Addressable Switch in home assistant

### relay Operation

![Relay](/resources/relay-dual-5vcoil.jpg)

> NOTE: the relays I got were duals and had no power indication but surface mount LEDs to indicate Relay when coil powered.

> Appears that these expect VCC to be common source for relay coils.

#### Coil Side

![Relay](/resources/relay-dual-wiring-nutrient-tank.jpg)

PINS J1

- VCC - VCC for Relay One Not Sure??? Does nothing??
- VCC - Common to J2 VCC
- GND - GND

PINS J2

- GND - GND
- IN1 - When GND the relay ONE is on.
- IN2 - When GND the relay TWO is on.
- VCC - Voltage to power coil 5V

## Contact Side

Each relay is noted as K1 or K2 at the top.

![Relay](/resources/relay-dual-5vcoil.jpg)

- NO - Normally Open
- Common - (Wiper)
- NC - Normally Closed

### Fan Connector pinouts

![fan](/resources/fan-4-wire-conn.png)

| Pin | Function | Wire color |
| ---- | ---- | ---- |
| 1 | GND | Black |
| 2 | 12V | Yellow |
| 3 | Sense (tach) | Green |
| 4 | Control (PWM) | Blue |

Pin one is marked by "key" closest to edge.


## PWM Control

https://fdossena.com/?p=ArduinoFanControl/i.md

[My Arduino fourms post](https://forum.arduino.cc/t/uno-r4-wifi-pwm-sense-control-of-fan/1227139?u=jwilleke)