# Analog pH Sensor Kit V2

[Gravity: Analog pH Sensor/Meter Kit V2 (Arduino & Raspberry Pi & micro:bit Compatible)](https://www.dfrobot.com/product-1782.html)

Used for our [Grow System](https://github.com/users/jwilleke/projects/2) within the [Nutrient-Tank](https://github.com/jwilleke/Nutrient-Tank)

DFRobot Gravity: Analog pH meter V2 is specifically designed to measure the pH of the solution and reflect the acidity or alkalinity. DFRobot ph sensor is commonly used in various applications such as aquaponics, aquaculture, and environmental water testing.

As an upgraded version of pH meter V1, this product greatly improves the precision and user experience. The onboard voltage regulator chip supports the wide voltage supply of 3.3~5.5V, which is compatible with the 5V and 3.3V main control boards. The output signal filtered by hardware has low jitter. The software library adopts the two-point calibration method, and can automatically identify two standard buffer solutions (4.0 and 7.0), so simple and convenient. You may also check Liquid Sensor Selection Guide to get better familiar with our liquid sensor series.

The sensor can be easily connected to most popular microcontrollers  (such as Arduino), with its Arduino library, you can quickly build a pH meter, plug and play. DFRobot provides a variety of water quality ph analog sensor products, uniform size, and interface, not only meeting the needs of various water quality measuring  but are also suitable for the DIY multi-parameter water quality tester.

The pH is a value that measures the acidity or alkalinity of the solution. It is also called the hydrogen ion concentration index. The pH is a scale of hydrogen ion activity in the solution. The pH has a wide range of uses in medicine, chemistry, and agriculture. Usually, the pH is a number between 0 to 14. Under the thermodynamic standard conditions, pH=7, which means the solution is neutral; pH<7, which means the solution is acidic; pH>7, which means the solution is alkaline.

## Attention

ph probes are prone to damage and deteriation.

1. The BNC connector and the signal conversion board must be kept dry and clean, otherwise, it will affect the input impedance, resulting in an inaccurate measurement. If it is damp, it needs to be dried.
2. The signal conversion board cannot be directly placed on a wet or semiconductor surface, otherwise, it will affect the input impedance, resulting in an inaccurate measurement. It is recommended to use the nylon pillar to fix the signal conversion board, and allow a certain distance between the signal conversion board and the surface.
3. The sensitive glass bubble in the head of the pH probe should avoid touching the hard material. Any damage or scratches will cause the electrode to fail.
4. After completing the measurement, disconnect the pH probe from the signal conversion board. The ph analog sensor probe should not be connected to the signal conversion board without the power supply for a long time.
5. The bottle cap of the probe contains protective liquid (3.3mol/L KCL). Even if the bottle cap is screwed tightly, some protective liquid may still leak around the bottle cap, forming white crystals. But as long as there is still protective liquid in the bottle cap, it will not affect the life and accuracy of the probe. So please use it with confidence. It is recommended that the white crystals be poured back into the protective liquid in the bottle cap.

## FEATURES

- 3.3~5.5V wide voltage input
- Hardware filtered output signal, low jitter
- Gravity connector and BNC connector, plug and play, no welding
- The software library supports two-point calibration and automatically identifies standard buffer solution
- Uniform size and connector, convenient for the design of mechanical structures

## SPECIFICATION

- Signal Conversion Board (Transmitter) V2
- Supply Voltage: 3.3~5.5V
- Output Voltage: 0~3.0V I assume this is the FULL range of output regardless of Supply Voltage?
- Probe Connector: BNC
- Signal Connector: PH2.0-3P
- Measurement Accuracy: ±0.1@25℃
- Dimension: 42mm*32mm/1.66*1.26in

## pH Probe

- Probe Type: Laboratory Grade
- Detection Range: 0~14
- Temperature Range: 5~60°C
- Zero Point: 7±0.5
- Response Time: <2min
- Internal Resistance: <250MΩ
- Probe Life: >0.5 years (depending on the frequency of use)
- Cable Length: 100cm


## Calibration for Gravity: Analog pH Sensor

To ensure accuracy, the probe needs to be calibrated for its first use and after not being used for an extended period of time (once a month ideally). This tutorial uses two-point calibration and therefore requires two standard buffer solutions of 4.0 and 7.0. The following steps show how to operate two-point calibration.

- Upload the sample code to the Arduino board, then open the serial monitor, after you can see the temperature and pH. If you added a temperature sensor, be sure to write the corresponding function and call it.
- Wash the probe with distilled water, then absorb the residual water-drops with paper. Insert the pH probe into the standard buffer solution of 7.0, stir gently, until the values are stable.
- After the values are stable, the first point can be calibrated. Specific steps are as follows:
  - Input enterph command in the serial monitor to enter the calibration mode.
  - Input calph commands in the serial monitor to start the calibration. The program will automatically identify which of the two standard buffer solutions is present: either 4.0 and 7.0. In this step, the standard buffer solution of 7.0 will be identified.
  - After the calibration, input exitph command in the serial monitor to save the relevant parameters and exit the calibration mode. Note: Only after inputing exitph command in the serial monitor can the relevant parameters be saved.
- After the above steps, the first point calibration is completed. The second point calibration will be performed below.
- Wash the probe with distilled water, then absorb the residual water-drops with paper. Insert the pH probe into the standard buffer solution of 4.0, stir gently, until the values are stable.
- After the values are stable, the second point can be calibrated. These steps are the same as the first calibration step. The specific steps are as follows:
  - Input enterph command in the serial monitor to enter the calibration mode.
  - Input calph commands in the serial monitor to start the calibration. The program will automatically identify which of the two standard buffer solutions is present: either 4.0 and 7.0 In this step, the standard buffer solution of 4.0 will be identified.
  - After the calibration, input the exitph command in the serial monitor to save the relevant parameters and exit the calibration mode. Note: Only after inputing exitph command in the serial monitor can the relevant parameters be saved.
- After the above steps, the second point calibration is completed.

After completing the above steps, the two-point calibration is completed, and then the sensor can be used for actual measurement. The relevant parameters in the calibration process have been saved to the __EEPROM__ of the main control board.

### Issues none of these work

enterph
ENTERPH
calph
CALPH
EXITPH
exitph

## Documentation

- [Product wiki](https://wiki.dfrobot.com/Gravity__Analog_pH_Sensor_Meter_Kit_V2_SKU_SEN0161-V2)
- [Calibrating an Analog pH Sensor](https://youtu.be/9EIbTbh80gA?si=rbtrr5lRJBuOabto)
- [DFRobot_PH Library](https://github.com/DFRobot/DFRobot_PH/archive/master.zip) - This is later code than https://github.com/DFRobot/DFRobot_PH/
