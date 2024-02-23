# Fermion: 2.0" 320x240 IPS TFT LCD Display with MicroSD Card (Breakout)

[Fermion: 2.0" 320x240 IPS TFT LCD Display with MicroSD Card (Breakout)](https://www.dfrobot.com/product-2071.html)


## Douments

- [Product Wiki page](https://wiki.dfrobot.com/2.0_Inches_320_240_IPS_TFT_LCD_Display_with_MicroSD_Card_Breakout_SKU_DFR0664)
- [Schematics](https://dfimg.dfrobot.com/nobody/wiki/d7f0fc2ba46f98f6579b5010f2272e09.pdf)
- [Dimension Diagram](https://dfimg.dfrobot.com/nobody/wiki/e14554a288328ec2d66625f555ea0102.pdf)
- [Chip Datasheet](https://dfimg.dfrobot.com/nobody/wiki/b1770205edde40407a1c37b4a6c5ffb7.pdf)

## Issues

Try the code on Product Wiki page [basicTest.ino](https://wiki.dfrobot.com/2.0_Inches_320_240_IPS_TFT_LCD_Display_with_MicroSD_Card_Breakout_SKU_DFR0664) @date 2020-01-07

Using Ardunio Version: 2.2.1 Date: 2023-08-31T14:26:39.874Z (4 months ago) CLI Version: 0.34.0

And loading the Library from IDE was version 1.00. Doenlaoded ZIP file from [DFRobot_GDL](https://github.com/DFRobot/DFRobot_GDL) version=1.0.1.

Receive Warning:

``` C++
/Users/jim/Documents/Arduino/sketch_jan8a/sketch_jan8a.ino:384:16: warning: ISO C++ forbids converting a string constant to 'char*' [-Wwrite-strings]
   screen.setTextColor(color+=0x0F00);
```

Some of the Examples simply would not run. Compiled but no display change. 