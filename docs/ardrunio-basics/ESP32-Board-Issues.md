# ESP32-Board-Issues

## Asked on

[FireBeetle 2 ESP32-E Unable to upload on MACOS](https://stackoverflow.com/questions/77710808/firebeetle-2-esp32-e-unable-to-upload-on-macos)

## Components Used

[FireBeetle 2 ESP32-E](https://www.dfrobot.com/product-2231.html)

### Using

- Arduino IDE: v 2.2.1
  - Version: 2.2.1
  - Date: 2023-08-31T14:26:39.874Z
  - CLI Version: 0.34.0

### on

- ProductName:  macOS
- ProductVersion:  14.2
- BuildVersion:  23C64

Board:

[FireBeetle 2 ESP32-E](https://www.dfrobot.com/product-2231.html)

### Also tried with

FireBeetle 2 ESP32-E IoT Microcontroller with Header

## Solution

I reinstalled the [CH340 Driver for MAC](https://dfimg.dfrobot.com/nobody/wiki/c195a13df2a1989d5dc04e76e6bcb701.ZIP)

I had downloaded it from somewhere else and It appears MACOS was not letting it install even though it said it was successful.

```bash
ll /dev/{tty,cu}.* 
crw-rw-rw-  1 root  wheel  0x9000001 Dec 25 04:45 /dev/cu.BLTH
crw-rw-rw-  1 root  wheel  0x9000005 Dec 25 04:29 /dev/cu.Bluetooth-Incoming-Port
crw-rw-rw-  1 root  wheel  0x9000003 Dec 25 04:51 /dev/cu.URT1
crw-rw-rw-  1 root  wheel  0x9000007 Dec 25 04:50 /dev/cu.wchusbserial1470
crw-rw-rw-  1 root  wheel  0x9000000 Dec 25 04:29 /dev/tty.BLTH
crw-rw-rw-  1 root  wheel  0x9000004 Dec 25 04:29 /dev/tty.Bluetooth-Incoming-Port
crw-rw-rw-  1 root  wheel  0x9000002 Dec 25 04:29 /dev/tty.URT1
crw-rw-rw-  1 root  wheel  0x9000006 Dec 25 04:50 /dev/tty.wchusbserial1470 # <=== Now something shows

# Also for https://platformio.org/ users:
pio device list --serial
/dev/cu.URT1
------------
Hardware ID: n/a
Description: n/a

/dev/cu.BLTH
------------
Hardware ID: n/a
Description: n/a

/dev/cu.Bluetooth-Incoming-Port
-------------------------------
Hardware ID: n/a
Description: n/a

/dev/cu.wchusbserial110
-----------------------
Hardware ID: USB VID:PID=1A86:7522 LOCATION=1-1 # <=== Now something shows
Description: USB Serial

```

## Errors

### When trying to upload a project

``` bash
Sketch uses 763364 bytes (58%) of program storage space. Maximum is 1310720 bytes.
Global variables use 33812 bytes (10%) of dynamic memory, leaving 293868 bytes for local variables. Maximum is 327680 bytes.
"/Users/jim/Library/Arduino15/packages/DFRobot/tools/esptool_py/3.0.0/esptool" --chip esp32 --port "/dev/cu.URT1" --baud 115200  --before default_reset --after hard_reset write_flash -z --flash_mode dio --flash_freq 80m --flash_size detect 0xe000 "/Users/jim/Library/Arduino15/packages/DFRobot/hardware/esp32/0.2.1/tools/partitions/boot_app0.bin" 0x1000 "/private/var/folders/97/4ntvdgtn4cg6l3rtf1ld56dw0000gn/T/arduino/sketches/6B93324481AFB3499472EFCECB202409/esp32-wifi.ino.bootloader.bin" 0x10000 "/private/var/folders/97/4ntvdgtn4cg6l3rtf1ld56dw0000gn/T/arduino/sketches/6B93324481AFB3499472EFCECB202409/esp32-wifi.ino.bin" 0x8000 "/private/var/folders/97/4ntvdgtn4cg6l3rtf1ld56dw0000gn/T/arduino/sketches/6B93324481AFB3499472EFCECB202409/esp32-wifi.ino.partitions.bin" 
esptool.py v3.1-dev
Serial port /dev/cu.URT1
Connecting........_____....._____....._____....._____....._____....._____....._____

A fatal error occurred: Failed to connect to ESP32: Timed out waiting for packet header
Failed uploading: uploading error: exit status 2
```

### when asking for board information

``` bash
Native serial port, can't obtain info.
```

Tried different baud rates with the same results.

## What Works

Same setup appears to work fine with Arduino UNO 4 for both getting Baord Infor and uploads.

However I have not been able to upgrade firmware to the board. May or may not be related.

``` bash
ll /dev/{tty,cu}.*
crw-rw-rw-  1 root  wheel  0x9000003 Dec 18 08:30 /dev/cu.BLTH
crw-rw-rw-  1 root  wheel  0x9000005 Dec 18 07:33 /dev/cu.Bluetooth-Incoming-Port
crw-rw-rw-  1 root  wheel  0x9000001 Dec 18 08:40 /dev/cu.URT1
crw-rw-rw-  1 root  wheel  0x9000007 Dec 18 08:42 /dev/cu.usbmodemF412FAA081C02
crw-rw-rw-  1 root  wheel  0x9000002 Dec 18 07:27 /dev/tty.BLTH
crw-rw-rw-  1 root  wheel  0x9000004 Dec 18 07:27 /dev/tty.Bluetooth-Incoming-Port
crw-rw-rw-  1 root  wheel  0x9000000 Dec 18 07:27 /dev/tty.URT1
crw-rw-rw-  1 root  wheel  0x9000006 Dec 18 08:42 /dev/tty.usbmodemF412FAA081C02
```

## What I do See

``` bash
# With nothing connected
ll /dev/{tty,cu}.*
crw-rw-rw-  1 root  wheel  0x9000003 Dec 18 08:15 /dev/cu.BLTH
crw-rw-rw-  1 root  wheel  0x9000005 Dec 18 07:33 /dev/cu.Bluetooth-Incoming-Port
crw-rw-rw-  1 root  wheel  0x9000001 Dec 18 07:47 /dev/cu.URT1 
crw-rw-rw-  1 root  wheel  0x9000002 Dec 18 07:27 /dev/tty.BLTH   
crw-rw-rw-  1 root  wheel  0x9000004 Dec 18 07:27 /dev/tty.Bluetooth-Incoming-Port
crw-rw-rw-  1 root  wheel  0x9000000 Dec 18 07:27 /dev/tty.URT1
```

```bash
# With ardroni UNO WIFI 
ll /dev/{tty,cu}.*
crw-rw-rw-  1 root  wheel  0x9000003 Dec 21 15:32 /dev/cu.BLTH
crw-rw-rw-  1 root  wheel  0x9000005 Dec 21 14:19 /dev/cu.Bluetooth-Incoming-Port
crw-rw-rw-  1 root  wheel  0x9000001 Dec 21 14:41 /dev/cu.URT1
crw-rw-rw-  1 root  wheel  0x9000007 Dec 21 15:32 /dev/cu.usbmodemF412FAA081C02
crw-rw-rw-  1 root  wheel  0x9000002 Dec 21 14:19 /dev/tty.BLTH
crw-rw-rw-  1 root  wheel  0x9000004 Dec 21 14:19 /dev/tty.Bluetooth-Incoming-Port
crw-rw-rw-  1 root  wheel  0x9000000 Dec 21 14:19 /dev/tty.URT1
crw-rw-rw-  1 root  wheel  0x9000006 Dec 21 15:32 /dev/tty.usbmodemF412FAA081C02
```

```bash
# FireBeetle 2 ESP32-E
ll /dev/{tty,cu}.*
crw-rw-rw-  1 root  wheel  0x9000003 Dec 21 15:34 /dev/cu.BLTH
crw-rw-rw-  1 root  wheel  0x9000005 Dec 21 14:19 /dev/cu.Bluetooth-Incoming-Port
crw-rw-rw-  1 root  wheel  0x9000001 Dec 21 14:41 /dev/cu.URT1
crw-rw-rw-  1 root  wheel  0x9000002 Dec 21 14:19 /dev/tty.BLTH
crw-rw-rw-  1 root  wheel  0x9000004 Dec 21 14:19 /dev/tty.Bluetooth-Incoming-Port
crw-rw-rw-  1 root  wheel  0x9000000 Dec 21 14:19 /dev/tty.URT1
```

## What I have tried

Use the "ESP32-S2 Dev Board", got same errors.

Installed the [CH340 Driver for MAC](https://dfimg.dfrobot.com/nobody/wiki/c195a13df2a1989d5dc04e76e6bcb701.ZIP)
No change noted.

## Other Noted Items

- [Comments on DFRbot](https://www.dfrobot.com/product-2231.html#comment-5539242446)
- [FireBeetle 2 ESP32-E wiki](https://wiki.dfrobot.com/FireBeetle_Board_ESP32_E_SKU_DFR0654) Has a lot of details on the board.

## platformio

``` bash
# with ESP32
pio device list --serial
/dev/cu.URT1
------------
Hardware ID: n/a
Description: n/a

/dev/cu.BLTH
------------
Hardware ID: n/a
Description: n/a

/dev/cu.Bluetooth-Incoming-Port
-------------------------------
Hardware ID: n/a
Description: n/a


# With Ardrunio
 pio device list --serial
/dev/cu.URT1
------------
Hardware ID: n/a
Description: n/a

/dev/cu.BLTH
------------
Hardware ID: n/a
Description: n/a

/dev/cu.Bluetooth-Incoming-Port
-------------------------------
Hardware ID: n/a
Description: n/a

/dev/cu.usbmodemF412FAA081C02
-----------------------------
Hardware ID: USB VID:PID=2341:1002 SER=F412FAA081C0 LOCATION=20-7
Description: UNO WiFi R4 CMSIS-DAP
```

## Possible idea of issue

Confirm compatibility: While both DS18S20 and DS18B20 are temperature sensors, they have slight differences. Verify that the Gravity sensor is indeed a DS18B20 (check the product specifications or markings) and adjust the code accordingly. The code currently expects a DS18S20, and you might need to modify the family check or use the DallasTemperature library, which handles both types.

Gravity: Waterproof DS18B20 Temperature Sensor Kit package shows:

- RED: VDD+
- YELLOW: data
- Black: GND
[Firebeetle ESP32-E with Arduino IoT Cloud, a review](https://techexplorations.com/blog/esp32/firebeetle-esp32e-arduinoiotcloud/)

## IO12

On chip, IO12 is pin 14 or GPIO14, ADC2_CH6, TOUCH6, RTC_GPIO16, MTMS, HSPICLK,
HS2_CLK, SD_CLK, EMAC_TXD2

<https://community.platformio.org/t/solved-trouble-uploading-to-esp32-wroom-32d/20507>

The linked issue ESP32DEVKIT V1 - A fatal error occurred: Timed out waiting for packet content · Issue #2415 · espressif/arduino-esp32 · [GitHub 44](https://github.com/espressif/arduino-esp32/issues/2415) says it can be a hardware issue with a too high upload speed or wrong voltage on the important bootstrapping pins 27.

Also, the standard is that there’s an auto-reset circuit where the USB-serial adapter’s RTS/DTR is connected via two transistors to EN and IO0, but you don’t have that hardware. But it also shouldn’t prevent you from uploading.

You can try and reduce the upload speed by writing upload_speed = 115200 in the platformio.ini and retry. You can also try different flash configurations

Thanks Issue is resolved.

I had to do two things.

- IO12 was getting pull high. So I had to cut that track.
- Short the the BOOT PIN and then short the EN pin breifly to GND.

This worked. But I have now realised my mistakes. and will change in next design. THanks for your help

## InstalL CH34X USB-to-SERIAL MACOS DRIVER

Installed and rebooted.

### Verify CH34X is installed

Shows as:

``` bash
USB Serial:

  Product ID: 0x7522
  Vendor ID: 0x1a86  (as inCH34X_DRV_INSTALL_INSTRUCTIONS.pdf) 
  Version: 2.64
  Speed: Up to 12 Mb/s
  Location ID: 0x14700000 / 4
  Current Available (mA): 500
  Extra Operating Current (mA): 0
```

``` bash
ll /Library/Extensions/CH34xVCPDriver.kext
total 0
drwxr-xr-x   3 root  wheel    96B Jan 19  2022 .
drwxr-xr-x  14 root  wheel   448B Dec 25 04:21 ..
drwxr-xr-x   6 root  wheel   192B Jan 19  2022 Contents
```

With device connected.
However does not show in:

```bash
# this Was before
ll /dev/{tty,cu}.*                                 
crw-rw-rw-  1 root  wheel  0x9000001 Dec 25 04:45 /dev/cu.BLTH
crw-rw-rw-  1 root  wheel  0x9000005 Dec 25 04:29 /dev/cu.Bluetooth-Incoming-Port
crw-rw-rw-  1 root  wheel  0x9000003 Dec 25 04:29 /dev/cu.URT1
crw-rw-rw-  1 root  wheel  0x9000000 Dec 25 04:29 /dev/tty.BLTH
crw-rw-rw-  1 root  wheel  0x9000004 Dec 25 04:29 /dev/tty.Bluetooth-Incoming-Port
crw-rw-rw-  1 root  wheel  0x9000002 Dec 25 04:29 /dev/tty.URT1
## Now
ll /dev/{tty,cu}.* 
crw-rw-rw-  1 root  wheel  0x9000001 Dec 25 04:45 /dev/cu.BLTH
crw-rw-rw-  1 root  wheel  0x9000005 Dec 25 04:29 /dev/cu.Bluetooth-Incoming-Port
crw-rw-rw-  1 root  wheel  0x9000003 Dec 25 04:51 /dev/cu.URT1
crw-rw-rw-  1 root  wheel  0x9000007 Dec 25 04:50 /dev/cu.wchusbserial1470
crw-rw-rw-  1 root  wheel  0x9000000 Dec 25 04:29 /dev/tty.BLTH
crw-rw-rw-  1 root  wheel  0x9000004 Dec 25 04:29 /dev/tty.Bluetooth-Incoming-Port
crw-rw-rw-  1 root  wheel  0x9000002 Dec 25 04:29 /dev/tty.URT1
crw-rw-rw-  1 root  wheel  0x9000006 Dec 25 04:50 /dev/tty.wchusbserial1470 # <=== Now something shows

```

```bash
ll /dev/tty* 
crw-rw-rw-  1 root  wheel   0x2000000 Dec 25 04:28 /dev/tty
crw-rw-rw-  1 root  wheel   0x9000000 Dec 25 04:29 /dev/tty.BLTH
crw-rw-rw-  1 root  wheel   0x9000004 Dec 25 04:29 /dev/tty.Bluetooth-Incoming-Port
crw-rw-rw-  1 root  wheel   0x9000002 Dec 25 04:29 /dev/tty.URT1
crw-rw-rw-  1 root  wheel   0x4000000 Dec 25 04:28 /dev/ttyp0
crw-rw-rw-  1 root  wheel   0x4000001 Dec 25 04:28 /dev/ttyp1
crw-rw-rw-  1 root  wheel   0x4000002 Dec 25 04:28 /dev/ttyp2
crw-rw-rw-  1 root  wheel   0x4000003 Dec 25 04:28 /dev/ttyp3
crw-rw-rw-  1 root  wheel   0x4000004 Dec 25 04:28 /dev/ttyp4
crw-rw-rw-  1 root  wheel   0x4000005 Dec 25 04:28 /dev/ttyp5
crw-rw-rw-  1 root  wheel   0x4000006 Dec 25 04:28 /dev/ttyp6
crw-rw-rw-  1 root  wheel   0x4000007 Dec 25 04:28 /dev/ttyp7
crw-rw-rw-  1 root  wheel   0x4000008 Dec 25 04:28 /dev/ttyp8
crw-rw-rw-  1 root  wheel   0x4000009 Dec 25 04:28 /dev/ttyp9
crw-rw-rw-  1 root  wheel   0x400000a Dec 25 04:28 /dev/ttypa
crw-rw-rw-  1 root  wheel   0x400000b Dec 25 04:28 /dev/ttypb
crw-rw-rw-  1 root  wheel   0x400000c Dec 25 04:28 /dev/ttypc
crw-rw-rw-  1 root  wheel   0x400000d Dec 25 04:28 /dev/ttypd
crw-rw-rw-  1 root  wheel   0x400000e Dec 25 04:28 /dev/ttype
crw-rw-rw-  1 root  wheel   0x400000f Dec 25 04:28 /dev/ttypf
crw-rw-rw-  1 root  wheel   0x4000010 Dec 25 04:28 /dev/ttyq0
crw-rw-rw-  1 root  wheel   0x4000011 Dec 25 04:28 /dev/ttyq1
crw-rw-rw-  1 root  wheel   0x4000012 Dec 25 04:28 /dev/ttyq2
crw-rw-rw-  1 root  wheel   0x4000013 Dec 25 04:28 /dev/ttyq3
crw-rw-rw-  1 root  wheel   0x4000014 Dec 25 04:28 /dev/ttyq4
crw-rw-rw-  1 root  wheel   0x4000015 Dec 25 04:28 /dev/ttyq5
crw-rw-rw-  1 root  wheel   0x4000016 Dec 25 04:28 /dev/ttyq6
crw-rw-rw-  1 root  wheel   0x4000017 Dec 25 04:28 /dev/ttyq7
crw-rw-rw-  1 root  wheel   0x4000018 Dec 25 04:28 /dev/ttyq8
crw-rw-rw-  1 root  wheel   0x4000019 Dec 25 04:28 /dev/ttyq9
crw-rw-rw-  1 root  wheel   0x400001a Dec 25 04:28 /dev/ttyqa
crw-rw-rw-  1 root  wheel   0x400001b Dec 25 04:28 /dev/ttyqb
crw-rw-rw-  1 root  wheel   0x400001c Dec 25 04:28 /dev/ttyqc
crw-rw-rw-  1 root  wheel   0x400001d Dec 25 04:28 /dev/ttyqd
crw-rw-rw-  1 root  wheel   0x400001e Dec 25 04:28 /dev/ttyqe
crw-rw-rw-  1 root  wheel   0x400001f Dec 25 04:28 /dev/ttyqf
crw-rw-rw-  1 root  wheel   0x4000020 Dec 25 04:28 /dev/ttyr0
crw-rw-rw-  1 root  wheel   0x4000021 Dec 25 04:28 /dev/ttyr1
crw-rw-rw-  1 root  wheel   0x4000022 Dec 25 04:28 /dev/ttyr2
crw-rw-rw-  1 root  wheel   0x4000023 Dec 25 04:28 /dev/ttyr3
crw-rw-rw-  1 root  wheel   0x4000024 Dec 25 04:28 /dev/ttyr4
crw-rw-rw-  1 root  wheel   0x4000025 Dec 25 04:28 /dev/ttyr5
crw-rw-rw-  1 root  wheel   0x4000026 Dec 25 04:28 /dev/ttyr6
crw-rw-rw-  1 root  wheel   0x4000027 Dec 25 04:28 /dev/ttyr7
crw-rw-rw-  1 root  wheel   0x4000028 Dec 25 04:28 /dev/ttyr8
crw-rw-rw-  1 root  wheel   0x4000029 Dec 25 04:28 /dev/ttyr9
crw-rw-rw-  1 root  wheel   0x400002a Dec 25 04:28 /dev/ttyra
crw-rw-rw-  1 root  wheel   0x400002b Dec 25 04:28 /dev/ttyrb
crw-rw-rw-  1 root  wheel   0x400002c Dec 25 04:28 /dev/ttyrc
crw-rw-rw-  1 root  wheel   0x400002d Dec 25 04:28 /dev/ttyrd
crw-rw-rw-  1 root  wheel   0x400002e Dec 25 04:28 /dev/ttyre
crw-rw-rw-  1 root  wheel   0x400002f Dec 25 04:28 /dev/ttyrf
crw-rw-rw-  1 root  wheel   0x4000030 Dec 25 04:28 /dev/ttys0
crw--w----  1 jim   tty    0x10000000 Dec 25 04:30 /dev/ttys000
crw--w----  1 root  tty    0x10000001 Dec 25 04:32 /dev/ttys001
crw--w----  1 jim   tty    0x10000002 Dec 25 04:32 /dev/ttys002
crw--w----  1 root  tty    0x10000003 Dec 25 04:32 /dev/ttys003
crw--w----  1 jim   tty    0x10000004 Dec 25 04:36 /dev/ttys004
crw-rw-rw-  1 root  wheel   0x4000031 Dec 25 04:28 /dev/ttys1
crw-rw-rw-  1 root  wheel   0x4000032 Dec 25 04:28 /dev/ttys2
crw-rw-rw-  1 root  wheel   0x4000033 Dec 25 04:28 /dev/ttys3
crw-rw-rw-  1 root  wheel   0x4000034 Dec 25 04:28 /dev/ttys4
crw-rw-rw-  1 root  wheel   0x4000035 Dec 25 04:28 /dev/ttys5
crw-rw-rw-  1 root  wheel   0x4000036 Dec 25 04:28 /dev/ttys6
crw-rw-rw-  1 root  wheel   0x4000037 Dec 25 04:28 /dev/ttys7
crw-rw-rw-  1 root  wheel   0x4000038 Dec 25 04:28 /dev/ttys8
crw-rw-rw-  1 root  wheel   0x4000039 Dec 25 04:28 /dev/ttys9
crw-rw-rw-  1 root  wheel   0x400003a Dec 25 04:28 /dev/ttysa
crw-rw-rw-  1 root  wheel   0x400003b Dec 25 04:28 /dev/ttysb
crw-rw-rw-  1 root  wheel   0x400003c Dec 25 04:28 /dev/ttysc
crw-rw-rw-  1 root  wheel   0x400003d Dec 25 04:28 /dev/ttysd
crw-rw-rw-  1 root  wheel   0x400003e Dec 25 04:28 /dev/ttyse
crw-rw-rw-  1 root  wheel   0x400003f Dec 25 04:28 /dev/ttysf
crw-rw-rw-  1 root  wheel   0x4000040 Dec 25 04:28 /dev/ttyt0
crw-rw-rw-  1 root  wheel   0x4000041 Dec 25 04:28 /dev/ttyt1
crw-rw-rw-  1 root  wheel   0x4000042 Dec 25 04:28 /dev/ttyt2
crw-rw-rw-  1 root  wheel   0x4000043 Dec 25 04:28 /dev/ttyt3
crw-rw-rw-  1 root  wheel   0x4000044 Dec 25 04:28 /dev/ttyt4
crw-rw-rw-  1 root  wheel   0x4000045 Dec 25 04:28 /dev/ttyt5
crw-rw-rw-  1 root  wheel   0x4000046 Dec 25 04:28 /dev/ttyt6
crw-rw-rw-  1 root  wheel   0x4000047 Dec 25 04:28 /dev/ttyt7
crw-rw-rw-  1 root  wheel   0x4000048 Dec 25 04:28 /dev/ttyt8
crw-rw-rw-  1 root  wheel   0x4000049 Dec 25 04:28 /dev/ttyt9
crw-rw-rw-  1 root  wheel   0x400004a Dec 25 04:28 /dev/ttyta
crw-rw-rw-  1 root  wheel   0x400004b Dec 25 04:28 /dev/ttytb
crw-rw-rw-  1 root  wheel   0x400004c Dec 25 04:28 /dev/ttytc
crw-rw-rw-  1 root  wheel   0x400004d Dec 25 04:28 /dev/ttytd
crw-rw-rw-  1 root  wheel   0x400004e Dec 25 04:28 /dev/ttyte
crw-rw-rw-  1 root  wheel   0x400004f Dec 25 04:28 /dev/ttytf
crw-rw-rw-  1 root  wheel   0x4000050 Dec 25 04:28 /dev/ttyu0
crw-rw-rw-  1 root  wheel   0x4000051 Dec 25 04:28 /dev/ttyu1
crw-rw-rw-  1 root  wheel   0x4000052 Dec 25 04:28 /dev/ttyu2
crw-rw-rw-  1 root  wheel   0x4000053 Dec 25 04:28 /dev/ttyu3
crw-rw-rw-  1 root  wheel   0x4000054 Dec 25 04:28 /dev/ttyu4
crw-rw-rw-  1 root  wheel   0x4000055 Dec 25 04:28 /dev/ttyu5
crw-rw-rw-  1 root  wheel   0x4000056 Dec 25 04:28 /dev/ttyu6
crw-rw-rw-  1 root  wheel   0x4000057 Dec 25 04:28 /dev/ttyu7
crw-rw-rw-  1 root  wheel   0x4000058 Dec 25 04:28 /dev/ttyu8
crw-rw-rw-  1 root  wheel   0x4000059 Dec 25 04:28 /dev/ttyu9
crw-rw-rw-  1 root  wheel   0x400005a Dec 25 04:28 /dev/ttyua
crw-rw-rw-  1 root  wheel   0x400005b Dec 25 04:28 /dev/ttyub
crw-rw-rw-  1 root  wheel   0x400005c Dec 25 04:28 /dev/ttyuc
crw-rw-rw-  1 root  wheel   0x400005d Dec 25 04:28 /dev/ttyud
crw-rw-rw-  1 root  wheel   0x400005e Dec 25 04:28 /dev/ttyue
crw-rw-rw-  1 root  wheel   0x400005f Dec 25 04:28 /dev/ttyuf
crw-rw-rw-  1 root  wheel   0x4000060 Dec 25 04:28 /dev/ttyv0
crw-rw-rw-  1 root  wheel   0x4000061 Dec 25 04:28 /dev/ttyv1
crw-rw-rw-  1 root  wheel   0x4000062 Dec 25 04:28 /dev/ttyv2
crw-rw-rw-  1 root  wheel   0x4000063 Dec 25 04:28 /dev/ttyv3
crw-rw-rw-  1 root  wheel   0x4000064 Dec 25 04:28 /dev/ttyv4
crw-rw-rw-  1 root  wheel   0x4000065 Dec 25 04:28 /dev/ttyv5
crw-rw-rw-  1 root  wheel   0x4000066 Dec 25 04:28 /dev/ttyv6
crw-rw-rw-  1 root  wheel   0x4000067 Dec 25 04:28 /dev/ttyv7
crw-rw-rw-  1 root  wheel   0x4000068 Dec 25 04:28 /dev/ttyv8
crw-rw-rw-  1 root  wheel   0x4000069 Dec 25 04:28 /dev/ttyv9
crw-rw-rw-  1 root  wheel   0x400006a Dec 25 04:28 /dev/ttyva
crw-rw-rw-  1 root  wheel   0x400006b Dec 25 04:28 /dev/ttyvb
crw-rw-rw-  1 root  wheel   0x400006c Dec 25 04:28 /dev/ttyvc
crw-rw-rw-  1 root  wheel   0x400006d Dec 25 04:28 /dev/ttyvd
crw-rw-rw-  1 root  wheel   0x400006e Dec 25 04:28 /dev/ttyve
crw-rw-rw-  1 root  wheel   0x400006f Dec 25 04:28 /dev/ttyvf
crw-rw-rw-  1 root  wheel   0x4000070 Dec 25 04:28 /dev/ttyw0
crw-rw-rw-  1 root  wheel   0x4000071 Dec 25 04:28 /dev/ttyw1
crw-rw-rw-  1 root  wheel   0x4000072 Dec 25 04:28 /dev/ttyw2
crw-rw-rw-  1 root  wheel   0x4000073 Dec 25 04:28 /dev/ttyw3
crw-rw-rw-  1 root  wheel   0x4000074 Dec 25 04:28 /dev/ttyw4
crw-rw-rw-  1 root  wheel   0x4000075 Dec 25 04:28 /dev/ttyw5
crw-rw-rw-  1 root  wheel   0x4000076 Dec 25 04:28 /dev/ttyw6
crw-rw-rw-  1 root  wheel   0x4000077 Dec 25 04:28 /dev/ttyw7
crw-rw-rw-  1 root  wheel   0x4000078 Dec 25 04:28 /dev/ttyw8
crw-rw-rw-  1 root  wheel   0x4000079 Dec 25 04:28 /dev/ttyw9
crw-rw-rw-  1 root  wheel   0x400007a Dec 25 04:28 /dev/ttywa
crw-rw-rw-  1 root  wheel   0x400007b Dec 25 04:28 /dev/ttywb
crw-rw-rw-  1 root  wheel   0x400007c Dec 25 04:28 /dev/ttywc
crw-rw-rw-  1 root  wheel   0x400007d Dec 25 04:28 /dev/ttywd
crw-rw-rw-  1 root  wheel   0x400007e Dec 25 04:28 /dev/ttywe
crw-rw-rw-  1 root  wheel   0x400007f Dec 25 04:28 /dev/ttywf


```

Or in:

``` bash
/dev % ll tty.wch*
zsh: no matches found: tty.wch*

Or:
/dev/{tty,cu}.*
crw-rw-rw-  1 root  wheel  0x9000001 Dec 25 04:35 /dev/cu.BLTH
crw-rw-rw-  1 root  wheel  0x9000005 Dec 25 04:29 /dev/cu.Bluetooth-Incoming-Port
crw-rw-rw-  1 root  wheel  0x9000003 Dec 25 04:29 /dev/cu.URT1
crw-rw-rw-  1 root  wheel  0x9000000 Dec 25 04:29 /dev/tty.BLTH
crw-rw-rw-  1 root  wheel  0x9000004 Dec 25 04:29 /dev/tty.Bluetooth-Incoming-Port
crw-rw-rw-  1 root  wheel  0x9000002 Dec 25 04:29 /dev/tty.URT1
```
