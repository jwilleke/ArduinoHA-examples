# I2C SD2405 RTC Module

Used for our [Grow System](https://github.com/users/jwilleke/projects/2) within the [Grow-Tent](https://github.com/jwilleke/Grow-Tent)

> Arduino UNO R4 WiFi (ABX00087) has RTC builtin.

Simple demo and test to make sure the module is working.

[Gravaty:I2C SD2405 RTC Module SKU:DFR0469 Brand:DFRobot](https://www.dfrobot.com/product-1600.html)

## INTRODUCTION

We're glad to introduce a new member in Gravity family: Gravity [I2C](/docs/ardrunio-basics/I2C.md) SD2405 RTC module. This is an extremely accurate I2C real-time clock (RTC) with crystal compensation, inner chargeable battery. The SD2405AL is available in industrial temperature ranges.

The SD2405AL is dual power supply system. When the primary power supply goes down to an assigned value or resumes from low power, the system can switch between the primary power supply and battery automatically. Even there is no external power, it can still work for 5~8 years, 1uA ultra-low power consumption (inner battery, Ta=25°C).

The SD2405AL can generates various periodic interrupt clock pulses lasting for long period (one year), and three alarm interrupts can be made by year, month, date, days of the week, hours, and minutes, seconds. It also provides a selectable 32.768KHz~1Hz clock output for an external MCU. The product incorporates a time trimming circuit that adjusts the clock with higher precision by adjusting any errors in crystal oscillator frequencies based on signals from the CPU. A 12-bytes general SRAM is implemented in the SD2405AL.

Gravity SD2405 RTC can work as data logger, timer alarm clock and other time application. It is an ideal choice for timing project.

Note: __Two versions with or without Weld pins will be shipped randomly.__

## SPECIFICATION

- Operation voltage range:3.3V~5.5V.
- Low-power:typical 1uA (inner battery, Ta=25°C)
- Timing Range: To 2099 (with leap year compensation)
- Accuracy ±5ppm from -40°C to +85°C.
- Fast (400kHz) I2C Interface(4.5~5.5V).
- Real-Time Clock Counts Seconds, Minutes,Hours, Day, Date, Month, and Year with Leap Year Compensation Valid Up to 2100.
- Time-of-Year,Month,Day,Week,Hour,Minute,Second Alarms.
- Programmable Square-Wave Output:32768hz,4096hz...1hz..1/16hz.
- Countdown timer interrupt.
- High precision time trimming circuit.
- 12-hour/24-hour time display selectable
- Dimension: 35.50 * 22.00(mm)/1.4 * 0.87 inches
- Weight: 6g

## DOCUMENTS

- [Product WIKI](https://wiki.dfrobot.com/Gravity__I2C_SD2405_RTC_Module_SKU__DFR0469)
- [GitHub Test Code](https://github.com/jwilleke/Gravity-I2C-SD2405-RTC-Module)
