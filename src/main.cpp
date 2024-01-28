#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <SPI.h>
// #include <Ethernet.h>
#include <ArduinoHA.h>
#include "arduino_secrets.h"
#include <my_config.h>

#define BROKER_ADDR IPAddress(192,168, 68, 20)
// #define BROKER_USERNAME   BROKER_USERNAME // replace with your credentials
// #define BROKER_PASSWORD   BROKER_PASSWORD // replace with your credentials
//  f4:12:fa:a0:81:c0
byte mac[] = {0xF4, 0x12, 0xFA, 0xA0, 0x81, 0xC0};

char ssid[] = SECRET_SSID; // your network SSID (name)
char pass[] = SECRET_PASS; // your network password (use for WPA, or use as key for WEP)
char mqttUser[] = MQTT_HA_BROKER_USERNAME;
char mqttUserPass[] = MQTT_HA_BROKER_PASSWORD;

WiFiClient client;
HADevice device;
HAMqtt mqtt(client, device);

// HALight::BrightnessFeature enables support for setting brightness of the light.
// HALight::ColorTemperatureFeature enables support for setting color temperature of the light.
// Both features are optional and you can remove them if they're not needed.
// "prettyLight" is unique ID of the light. You should define your own ID.
HALight light("prettyLight", HALight::BrightnessFeature | HALight::ColorTemperatureFeature | HALight::RGBFeature);

void onStateCommand(bool state, HALight *sender)
{
  Serial.print("State: ");
  Serial.println(state);

  sender->setState(state); // report state back to the Home Assistant
}

void onBrightnessCommand(uint8_t brightness, HALight *sender)
{
  Serial.print("Brightness: ");
  Serial.println(brightness);

  sender->setBrightness(brightness); // report brightness back to the Home Assistant
}

void onColorTemperatureCommand(uint16_t temperature, HALight *sender)
{
  Serial.print("Color temperature: ");
  Serial.println(temperature);

  sender->setColorTemperature(temperature); // report color temperature back to the Home Assistant
}

void onRGBColorCommand(HALight::RGBColor color, HALight *sender)
{
  Serial.print("Red: ");
  Serial.println(color.red);
  Serial.print("Green: ");
  Serial.println(color.green);
  Serial.print("Blue: ");
  Serial.println(color.blue);

  sender->setRGBColor(color); // report color back to the Home Assistant
}

void setup()
{
  Serial.begin(SERIAL_BAUD_RATE);
  Serial.println("Starting setup...");
  Serial.println("DNS and DHCP-based web client test 2024-01-28"); // so I can keep track of what is loaded start the Ethernet connection:connect to wifi
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500); // waiting for the connection
  }
  Serial.println();
  Serial.println("Connected to the network");
  Serial.println();

  // set device's details (optional)
  device.setName("ntank");
  device.setSoftwareVersion("1.0.0");
    // Unique ID must be set!
    byte mac[6];
    WiFi.macAddress(mac);
    device.setUniqueId(mac, sizeof(mac));

  // configure light (optional)
  light.setName("XXXXXX-YYYY");

  // Optionally you can set retain flag for the HA commands
  // light.setRetain(true);

  // Maximum brightness level can be changed as follows:
  // light.setBrightnessScale(50);

  // Optionally you can enable optimistic mode for the HALight.
  // In this mode you won't need to report state back to the HA when commands are executed.
  // light.setOptimistic(true);

  // Color temperature range (optional)
  // light.setMinMireds(50);
  // light.setMaxMireds(200);

  // handle light states
  light.onStateCommand(onStateCommand);
  light.onBrightnessCommand(onBrightnessCommand);             // optional
  light.onColorTemperatureCommand(onColorTemperatureCommand); // optional
  light.onRGBColorCommand(onRGBColorCommand);                 // optional

  //mqtt.begin(IPAddress(192,168, 68, 20), MQTT_HA_BROKER_USERNAME, MQTT_HA_BROKER_PASSWORD);
  //mqtt.begin("192.168.68.20", MQTT_HA_BROKER_USERNAME, MQTT_HA_BROKER_PASSWORD);
  
  //mqtt.isConnected() ? Serial.println("true") : Serial.println("false");
   mqtt.begin(IPAddress(192,168,68,20), mqttUser, mqttUserPass);
  Serial.print("Waiting for mqtt to connect ");
  while (!mqtt.isConnected())
  {
    Serial.print(".");
    delay(5000); // waiting for the connection
  }
  Serial.println();
  Serial.println("Connected to the MQtt broker");
  Serial.println("Exit setup...");
}

void loop()
{
  // Ethernet.maintain();
  mqtt.loop();

  // You can also change the state at runtime as shown below.
  // This kind of logic can be used if you want to control your light using a button connected to the device.
  // light.setState(true); // use any state you want
}