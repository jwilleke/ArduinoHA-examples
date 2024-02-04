/**
 * @file  ha_config.h
 * These are values that are generally specific to this project and the associated hardware.
*/
#pragma once

#define SERIAL_BAUD_RATE 115200

#define ANALOG_SUPPLY_VOLTAGE 5.0
#define BROKER_ADDR IPAddress(192, 168, 68, 20)

/*
Hardware ping addreses
Sensor pin settings
*/
#define PHPIN A4  // semsors[0]
#define TDSPIN A1 // semsors[1]
#define DOPIN A5  // not used but is ues in GravityDo,cpp
#define ORPPIN A2 // semsors[2]
#define ECPIN A3  // semsors[3]
#define TEMPPIN 2 // semsors[4]
#define LEVELPIN 3
#define RELAYPIN 4 ??? // not used



//#define DEBUG_PRINT_ENABLED // Comment out this line of code if you don't want to see the debug print

#if defined(DEBUG_PRINT_ENABLED)
  #define DEBUG_INIT() Serial.begin(SERIAL_BAUD_RATE);
  #define DEBUG_PRINT(x) Serial.print(x);
  #define DEBUG_PRINTLN(x) Serial.println(x);
#else
  #define DEBUG_INIT()
  #define DEBUG_PRINTLN(x)
  #define DEBUG_PRINT(x)
#endif
