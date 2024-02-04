#include <Arduino.h>
#include <WiFi.h> // the "official" WiFi library built-in to the Board Package
#include <WiFiClient.h>
#include <OneWire.h>
#include <ArduinoHA.h>
#include <arduino_secrets.h> // contains secret credentials and API keys for Arduino project.
#include <my_config.h>       // contains values I use for all my Arduino projects.

// #include <ArduinoHADefines.h>
//  I was thinking this would be seen by the ArduinoHA.cpp code and provide more debug data, but it doesn't seem to do anything.
//  It appears there is no overloading for #define symbols.
// #define ARDUINOHA_DEBUG_PRINT Serial.print
// #define ARDUINOHA_DEBUG_PRINTLN Serial.println
// #define ARDUINOHA_DEBUG

// https://github.com/dawidchyrzynski/arduino-home-assistant/blob/main/examples/sensor-integer/sensor-integer.ino

bool exitApp = false;

#define ANALOG_SUPPLY_VOLTAGE 5.0
#define BROKER_ADDR IPAddress(192, 168, 68, 20)
#define ORPPIN A2 // semsors[2]
#define PHPIN A4  // semsors[0]
#define TEMPPIN 2 // semsors[1]

OneWire ds(TEMPPIN);

// values for the phSensor
double _temperature = 25.0;
double _phValue = 7.0;
double _acidVoltage = 421.0;   // buffer solution 4.0 at 25C
double _neutralVoltage = 315.0; // buffer solution 7.0 at 25C

char ssid[] = SECRET_SSID; // your network SSID (name)
char pass[] = SECRET_PASS; // your network password (use for WPA, or use as key for WEP)
char mqttUser[] = MQTT_HA_BROKER_USERNAME;
char mqttUserPass[] = MQTT_HA_BROKER_PASSWORD;
char deviceName[] = "XXXDevice";
// use your own unique bytes sequence or use mac of WiFi
// f4:12:fa:a0:81:c0
byte myId[] = {0xF4, 0x12, 0xFA, 0xA0, 0x81, 0xC0};
HADevice device(myId, sizeof(myId));

WiFiClient wifiClient;

// assign the device and the sensor to the MQTT client
HAMqtt mqtt(wifiClient, device);

// ==================== SENSOR SENSOR DEFINITiON ====================
// A sensor is a prt of this device that measures a physical quantity and converts it into a signal
// The unique ID of the sensor. It needs to be unique in a scope of your device.
HASensorNumber uptimeSensor("ardUptime");
// "myAnalogInput" is unique ID of the sensor. You should define your own ID. (PrecisionP2 is points after the decimal point)
HASensorNumber orbSensor("ORB", HASensorNumber::PrecisionP2);

HASensorNumber phSensor("PH", HASensorNumber::PrecisionP1);
HASensorNumber temperature("Temperature", HASensorNumber::PrecisionP0);


unsigned long lastUpdateAt = 0;
// ==================== END OF THE DEVICE DEFINITiON ====================

/**
 * @brief  This function is used to get the temperature value from the temperature sensor.
*/
double getValueTemperatureSensor()
{
  //returns the temperature from one DS18S20 in DEG Celsius

  byte data[12];
  byte addr[8];

  if ( !ds.search(addr)) {
      //no more sensors on chain, reset search
      ds.reset_search();
      return -1000;
  }

  if ( OneWire::crc8( addr, 7) != addr[7]) {
      Serial.println("CRC is not valid!");
      return -1000;
  }

  if ( addr[0] != 0x10 && addr[0] != 0x28) {
      Serial.print("Device is not recognized");
      return -1000;
  }

  ds.reset();
  ds.select(addr);
  ds.write(0x44,1); // start conversion, with parasite power on at the end

  byte present = ds.reset();
  ds.select(addr);
  ds.write(0xBE); // Read Scratchpad


  for (int i = 0; i < 9; i++) { // we need 9 bytes
    data[i] = ds.read();
  }

  ds.reset_search();

  byte MSB = data[1];
  byte LSB = data[0];

  float tempRead = ((MSB << 8) | LSB); //using two's compliment
  float TemperatureSum = tempRead / 16;

  return TemperatureSum;

}

/**
 *  @brief  This function is used to get the pH value from the pH sensor.
*/
double getValuePHSensor(float temperature)
{

  double temp = temperature ? temperature: _temperature; 
  float rawReadVoltage = analogRead(PHPIN);
  Serial.print("rawReadVoltage: ");
  Serial.println(rawReadVoltage);
  float slope = (7.0 - 4.0) / ((_neutralVoltage - 1500.0) / 3.0 - (_acidVoltage - 1500.0) / 3.0);
  float intercept = 7.0 - slope * (_neutralVoltage - 1500.0) / 3.0;
  float _phValue = slope * (rawReadVoltage - 1500.0) / 3.0 + intercept; // y = k*x + b

  //* ANALOG_SUPPLY_VOLTAGE / 1023;
  Serial.print("pH Value: ");
  Serial.println(_phValue);
  return _phValue;
}

/**
 *
 */

void printByetArray(byte mac[], int len)
{
  for (int i = len; i > 0; i--)
  {
    if (mac[i] < 16)
    {
      Serial.print("0");
    }
    Serial.print(mac[i], HEX);
    if (i > 0)
    {
      Serial.print(":");
    }
  }
  Serial.println();
}

void printCurrentNet()
{
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print the MAC address of SSID you're attached to:
  byte bssid[6];
  WiFi.BSSID(bssid);
  Serial.print("BSSID: ");
  printByetArray(bssid, 6);

  Serial.print("MAC: ");
  printByetArray(myId, sizeof(myId));

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI): ");
  Serial.println(rssi);

  // print the encryption type:
  byte encryption = WiFi.encryptionType();
  Serial.print("Encryption Type: ");
  Serial.println(encryption, HEX);
  Serial.println();
} // end printCurrentNet

void setup()
{
  Serial.begin(SERIAL_BAUD_RATE);
  Serial.println("Starting setup...");
  Serial.println("DNS and DHCP-based web client test 2024-01-29"); // so I can keep track of what is loaded start the Ethernet connection:connect to wifi

  // WiFi.config(ip, gateway, subnet);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500); // waiting for the connection
  }
  Serial.println();
  Serial.println("Connected to the network");
  printCurrentNet();

  // set device's details (optional)
  device.setSoftwareVersion("1.0.0");
  device.setManufacturer("arduino");
  device.setModel("uno_r4_wifi");
  // ...
  device.enableSharedAvailability();
  // device.setAvailability(false); // changes default state to offline
  //  MQTT LWT (Last Will and Testament) is a feature of the MQTT protocol that allows a client to notify the broker of an ungracefully disconnected client.
  device.enableLastWill();
  // Discovery prefix is used to build the MQTT topic for the discovery messages.
  mqtt.setDiscoveryPrefix("homeassistant"); // this is the default value
  mqtt.setDataPrefix("aha");                // this is the default value

  // configure sensor (optional)
  uptimeSensor.setIcon("mdi:mdi-av-timer");
  uptimeSensor.setName("XXXUptime");
  uptimeSensor.setUnitOfMeasurement("s");
  // orbSensor.setIcon("mdi:home");
  orbSensor.setIcon("mdi:current-dc");
  orbSensor.setName("XXXOrb");
  orbSensor.setUnitOfMeasurement("mv");
  // setup phSensor
  phSensor.setIcon("mdi:oil-temperature");
  phSensor.setName("XXXpH");
  phSensor.setUnitOfMeasurement("pH");
  // setup the device
  temperature.setIcon("mdi:thermometer");
  temperature.setName("Temperature");
  temperature.setUnitOfMeasurement("°C");
  // start the mqtt broker connection
  mqtt.begin(BROKER_ADDR, mqttUser, mqttUserPass);
}

void loop()
{
  if (exitApp)
  {
    Serial.println("Entering empty Loop forever...");
    mqtt.disconnect();
    while (true)
    {
    };
  }
  // Ethernet.maintain();
  mqtt.loop();
  // update the sensor values every 2s
  if ((millis() - lastUpdateAt) > 2000)
  { // update in 2s interval
    unsigned long uptimeValue = millis() / 1000;
    uptimeSensor.setValue(uptimeValue);
    // set orbSensor value
    uint16_t reading = analogRead(ORPPIN);
    orbSensor.setValue(reading);
    // set temperature value
    float tempReading = getValueTemperatureSensor();
    temperature.setValue(tempReading);
    // set phSensor values
    float phReading = getValuePHSensor(tempReading); 
    phSensor.setValue(phReading);

  // reset loop timer
  lastUpdateAt = millis();
  }

  // You can also change the state at runtime as shown below.
  // This kind of logic can be used if you want to control your light using a button connected to the device.
  // light.setState(true); // use any state you want
}