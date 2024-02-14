/**
 * @file  ha_config.h
 * These are values that are generally specific to this project and the associated hardware.
*/
#pragma once

#define SERIAL_BAUD_RATE 115200

#define ANALOG_SUPPLY_VOLTAGE 5.0
#define BROKER_ADDR IPAddress(192, 168, 68, 122)


#define MQTT_SENSOR_COUNT 20

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

// Digital I/O pin settings for the pumps fans and valves
//Relay 1
#define PHUP_SOLUTION_PUMP 8
#define PHDOWN_SOLUTION_PUMP 9
//Relay 2
#define A1SOLUTION_PUMP 10
#define A2SOLUTION_PUMP 11
//Relay 3 (Two STIRERs on each set of relay contacts)
#define SOLUTION_STIRER_1 12
#define SOLUTION_STIRER_2 13


#define PUMP_RUNTIME 20000

// EC sesor values
#define EEPROM_write(address, p) {int i = 0; byte *pp = (byte*)&(p);for(; i < sizeof(p); i++) EEPROM.write(address+i, pp[i]);}
#define EEPROM_read(address, p)  {int i = 0; byte *pp = (byte*)&(p);for(; i < sizeof(p); i++) pp[i]=EEPROM.read(address+i);}

#define KVALUEADDR 0x0A    //the start address of the K value stored in the EEPROM
#define ECRES2 820.0
#define ECREF 200.0

#define DEBUG_PRINT_ENABLED // Comment out this line of code if you don't want to see the debug print

#if defined(DEBUG_PRINT_ENABLED)
  #define DEBUG_INIT() Serial.begin(SERIAL_BAUD_RATE);
  #define DEBUG_PRINT(x) Serial.print(x);
  #define DEBUG_PRINTLN(x) Serial.println(x);
#else
  #define DEBUG_INIT()
  #define DEBUG_PRINTLN(x)
  #define DEBUG_PRINT(x)
#endif


