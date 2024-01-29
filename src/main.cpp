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
byte mac[6];

WiFiClient wifiClient;
HADevice device;

// ==================== SENSOR SENSOR DEFINITiON ====================
// A sensor is a prt of this device that measures a physical quantity and converts it into a signal
#define INPUT_PIN 9

unsigned long lastReadAt = millis();
unsigned long lastAvailabilityToggleAt = millis();
bool lastInputState = false;

// "myInput" is unique ID of the sensor. You should define you own ID.
HABinarySensor sensor("MY_INPUT");

// ==================== END OF THE SENSOR DEFINITiON ====================

// assign the device and the sensor to the MQTT client
HAMqtt mqtt(wifiClient, device);

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

  // Get the MAC adrress of this device
  WiFi.macAddress(mac);
  Serial.print("MAC: ");
  printByetArray(mac, 6);

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
  lastReadAt = millis();
  lastAvailabilityToggleAt = millis();
 // ==================== DEVICE DEFINITiON ====================
  // set device's details (Required)
  device.setName("nTank");
  byte deviceID[] = "001";
  device.setUniqueId(deviceID, 4); // required

  

  
  // set device's details (optional)
  device.setSoftwareVersion("1.0.0");
  device.setManufacturer("JWILLEKE");
    // This method enables availability for all device types registered on the device.
  // For example, if you have 5 sensors on the same device, you can enable
  // shared availability and change availability state of all sensors using
  // single method call "device.setAvailability(false|true)"
  device.enableSharedAvailability();

  // ==================== SENSOR SENSOR DEFINITiON ====================
  pinMode(INPUT_PIN, INPUT_PULLUP);
  lastInputState = digitalRead(INPUT_PIN);
  sensor.setName("XXXXXX-door");
  sensor.setDeviceClass("door"); // optional
  // Opetionsal items for sensor
  // turn on "availability" feature
  // this method also sets initial availability so you can use "true" or "false"
  sensor.setAvailability(false);
  sensor.setCurrentState(lastInputState); // optional
  
  // Optionally, you can enable MQTT LWT feature. If device will lose connection
  // to the broker, all device types related to it will be marked as offline in
  // the Home Assistant Panel.
  device.enableLastWill();

  // mqtt.isConnected() ? Serial.println("true") : Serial.println("false");
  Serial.print("Connecting to MQTT broker at ");
  Serial.println(IPAddress(192, 168, 68, 20));

  bool mbegin = mqtt.begin(IPAddress(192, 168, 68, 20), 1833, mqttUser, mqttUserPass);

  Serial.print("mqtt.begin() returned: ");
  Serial.println(mbegin);

  Serial.println();
  Serial.println("Connected to the MQTT broker");
  Serial.println("Exit setup...");
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
  if ((millis() - lastReadAt) > 30)
  { // read in 30ms interval
    // library produces MQTT message if a new state is different than the previous one
    sensor.setState(digitalRead(INPUT_PIN));
    lastInputState = sensor.getCurrentState();
    lastReadAt = millis();
  }

  if ((millis() - lastAvailabilityToggleAt) > 5000)
  {
    device.setAvailability(!device.isAvailable());
    lastAvailabilityToggleAt = millis();
  }

  // You can also change the state at runtime as shown below.
  // This kind of logic can be used if you want to control your light using a button connected to the device.
  // light.setState(true); // use any state you want
}