#include <Arduino.h>
#include <WiFi.h> // the "official" WiFi library built-in to the Board Package
#include <WiFiClient.h>
// #include <SPI.h>
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

#define BROKER_ADDR IPAddress(192, 168, 68, 20)
// #define BROKER_USERNAME   BROKER_USERNAME // replace with your credentials
// #define BROKER_PASSWORD   BROKER_PASSWORD // replace with your credentials
//  f4:12:fa:a0:81:c0
// byte mac[] = {0xF4, 0x12, 0xFA, 0xA0, 0x81, 0xC0};

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
unsigned long lastUpdateAt = 0;
// ==================== END OF THE DEVICE DEFINITiON ====================

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
  //device.setAvailability(false); // changes default state to offline
  // MQTT LWT
  device.enableLastWill();
  // Discovery
  mqtt.setDiscoveryPrefix("homeassistant");
  mqtt.setDataPrefix("aha");

  // configure sensor (optional)
  uptimeSensor.setIcon("mdi:home");
  uptimeSensor.setName("XXXUptime");
  uptimeSensor.setUnitOfMeasurement("s");

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
  if ((millis() - lastUpdateAt) > 2000)
  { // update in 2s interval
    unsigned long uptimeValue = millis() / 1000;
    uptimeSensor.setValue(uptimeValue);
    lastUpdateAt = millis();
  }

  // You can also change the state at runtime as shown below.
  // This kind of logic can be used if you want to control your light using a button connected to the device.
  // light.setState(true); // use any state you want
}