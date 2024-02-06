#include <Arduino.h>
#include <WiFi.h> // the "official" WiFi library built-in to the Board Package
#include <WiFiClient.h>
#include <OneWire.h>
#include <ArduinoHA.h>
#include <arduino_secrets.h> // contains secret credentials and API keys for Arduino project.
#include <my_config.h>       // contains values I use for all my Arduino projects.
#include <ha_config.h>

// https://github.com/dawidchyrzynski/arduino-home-assistant/blob/main/examples/sensor-integer/sensor-integer.ino

bool exitApp = false;

OneWire ds(TEMPPIN);

// values for the phSensor
double _temperature = 25.0;
double _phValue = 7.0;
double _acidVoltage = 421.0;    // buffer solution 4.0 at 25C
double _neutralVoltage = 315.0; // buffer solution 7.0 at 25C
float averageTDSVoltage = 0;    // store the total value of the sensor since we started
float averageECvalue = 0;       // store the total value of the sensor since we started
int16_t readCount = 0;

char ssid[] = SECRET_SSID; // your network SSID (name)
char pass[] = SECRET_PASS; // your network password (use for WPA, or use as key for WEP)
char mqttUser[] = MQTT_HA_BROKER_USERNAME;
char mqttUserPass[] = MQTT_HA_BROKER_PASSWORD;
char deviceName[] = "Nutrient Tank";
// use your own unique bytes sequence or use mac of WiFi
// f4:12:fa:a0:81:c0
byte myId[] = {0xF4, 0x12, 0xFA, 0xA0, 0x81, 0xC0};
HADevice device(myId, sizeof(myId));

WiFiClient wifiClient;

// assign the device and the sensor to the MQTT client and make the max number of sensors 12
HAMqtt mqtt(wifiClient, device, 12);

// ==================== SENSOR SENSOR DEFINITiON ====================
// A sensor is a prt of this device that measures a physical quantity and converts it into a signal
// The unique ID of the sensor. It needs to be unique in a scope of your device.
HASensorNumber uptimeSensor("ardUptime");
// "myAnalogInput" is unique ID of the sensor. You should define your own ID. (PrecisionP2 is points after the decimal point)
HASensorNumber orbSensor("ORB", HASensorNumber::PrecisionP2);
// setup phSensor
HASensorNumber phSensor("PH", HASensorNumber::PrecisionP1);
// setup temperatureSensor
HASensorNumber temperature("Temperature", HASensorNumber::PrecisionP1);
// setup tdsSensor
HASensorNumber tdsSensor("TDS", HASensorNumber::PrecisionP1);
// setup ecSensor
HASensorNumber ecSensor("EC", HASensorNumber::PrecisionP2);
// setup tankLevelSensor
HABinarySensor tnakLevelSensor("TankLevel");
// setup the buttons for the pumps
HASwitch a1Pump("A1-PUMP");
HASwitch a2Pump("A2-PUMP");
HASwitch phUpPump("PH-UP-PUMP");
HASwitch phDownPump("PH-DOWN-PUMP");

// ==================== END OF THE SENSOR DEFINITiON ====================
// This it the last time the sensors were updated
unsigned long lastUpdateAt = 0;

float getECValue(float temperature)
{
  float _temperatureValue = temperature ? temperature : _temperature;
  float voltage = analogRead(ECPIN) / 1024.0 * 5000; // read the voltage (From https://github.com/DFRobot/DFRobot_EC/blob/master/example/DFRobot_EC_Test/DFRobot_EC_Test.ino)
  DEBUG_PRINT("rawECVoltage: ");
  DEBUG_PRINTLN(voltage);
  // float _ecvalue = 0.0;
  float _kvalue = 1.0;
  float _kvalueLow = 1.0;
  float _kvalueHigh = 1.0;
  // float _voltage = 0.0;
  float _rawEC = 1000 * voltage / ECRES2 / ECREF;
  float valueTemp = valueTemp = _rawEC * _kvalue; // calculate the EC value after automatic shift
  // automatic shift process
  // First Range:(0,2); Second Range:(2,20)
  if (valueTemp > 2.5)
  {
    _kvalue = _kvalueHigh;
  }
  else if (valueTemp < 2.0)
  {
    _kvalue = _kvalueLow;
  }
  float value = _rawEC * _kvalue; // calculate the EC value after automatic shift
  DEBUG_PRINT("ecShiftVoltage: ");
  DEBUG_PRINTLN(value);
  value = value / (1.0 + 0.0185 * (_temperatureValue - 25.0)); // temperature compensation
  DEBUG_PRINT("EC Value after temp comp: ");
  DEBUG_PRINTLN(value);

  return value;
}

/**
 * @brief  This function is used to get the TDS value from the TDS sensor
 * @param temperature The temperature value to be used for the TDS sensor compensationCoefficient

*/
double getTDSValue(float temperature)
{
  float rawReadVoltage = analogRead(TDSPIN);
  // calculate the average value of the sensor since we started
  averageTDSVoltage = (averageTDSVoltage + rawReadVoltage) / readCount;
  // temperature compensation formula: fFinalResult(25^C) = fFinalResult(current)/(1.0+0.02*(fTP-25.0));
  float compensationCoefficient = 1.0 + 0.02 * (temperature - 25.0);
  // temperature compensation
  float compensationVolatge = averageTDSVoltage / compensationCoefficient;
  // convert voltage value to tds value
  float tdsValue = (133.42 * compensationVolatge * compensationVolatge * compensationVolatge - 255.86 * compensationVolatge * compensationVolatge + 857.39 * compensationVolatge) * 0.5;
  return tdsValue;
}

/**
 * @brief  This function is used to get the temperature value from the temperature sensor.
 */
double getValueTemperatureSensor()
{
  // returns the temperature from one DS18S20 in DEG Celsius

  byte data[12];
  byte addr[8];

  if (!ds.search(addr))
  {
    // no more sensors on chain, reset search
    ds.reset_search();
    return -1000;
  }

  if (OneWire::crc8(addr, 7) != addr[7])
  {
    Serial.println("CRC is not valid!");
    return -1000;
  }

  if (addr[0] != 0x10 && addr[0] != 0x28)
  {
    DEBUG_PRINT("Device is not recognized");
    return -1000;
  }

  ds.reset();
  ds.select(addr);
  ds.write(0x44, 1); // start conversion, with parasite power on at the end

  byte present = ds.reset();
  ds.select(addr);
  ds.write(0xBE); // Read Scratchpad

  for (int i = 0; i < 9; i++)
  { // we need 9 bytes
    data[i] = ds.read();
  }

  ds.reset_search();

  byte MSB = data[1];
  byte LSB = data[0];

  float tempRead = ((MSB << 8) | LSB); // using two's compliment
  float TemperatureSum = tempRead / 16;

  return TemperatureSum;
}

/**
 * @brief  This function is used to control the pump
 * @param myswitch The switch that is being controlled
 * @param state The state of the switch
 * @param mcuPin The pin that the pump is connected to
 */
void switchControl(HASwitch myswitch, bool state, int mcuPin)
{
  if (state) // HA said turn on
  {
    DEBUG_PRINT("Turning ON Switch: ");
    DEBUG_PRINTLN(myswitch.getName());
    DEBUG_PRINT("Setting Switch state: (1=ON=HIGH=TRUE) ");
    DEBUG_PRINTLN(state);
    digitalWrite(mcuPin, LOW);
    myswitch.setState(state);
    delay(PUMP_RUNTIME);
    DEBUG_PRINT("Turning OFF Switch: ");
    DEBUG_PRINTLN(myswitch.getName());
    DEBUG_PRINT("Setting Switch state: (0=OFF=LOW=FALSE) ");
    DEBUG_PRINTLN(state);

    digitalWrite(mcuPin, HIGH);
    myswitch.setState(LOW);
  }
  else // off
  {
    DEBUG_PRINT("Turning OFF Switch: ");
    DEBUG_PRINTLN(myswitch.getName());
    DEBUG_PRINT("Setting Switch state: (0=OFF=LOW=FALSE) ");
    DEBUG_PRINTLN(state);
    digitalWrite(mcuPin, HIGH);
    myswitch.setState(LOW);
  }
}

/**
 * @brief  This function is used to handle the switch commands from the Home Assistant
 * @param state The state of the switch
 * @param sender is a pointer to the switch that sent the command
 * When 1 comes in the state is ON and when 0 comes in the state is OFF
 */
void onSwitchCommand(bool state, HASwitch *sender)
{
  if (state) // 1=ON in HA
  {
    sender->setState(state); // report state back to the Home Assistant
    if (sender == &a1Pump)
    {
      switchControl(a1Pump, state, A1SOLUTION);
    }
    else if (sender == &a2Pump)
    {
      switchControl(a2Pump, state, A2SOLUTION);
    }
    else if (sender == &phUpPump)
    {
      switchControl(phUpPump, state, PHUP_SOLUTION);
    }
    else if (sender == &phDownPump)
    {
      switchControl(phDownPump, state, PHDOWN_SOLUTION);
    }
    else
    {
      Serial.println("Unknown switch");
    }
  }
  else
  {
    // turn off the pump
    if (sender == &a1Pump)
    {
      switchControl(a1Pump, state, A1SOLUTION);
    }
    else if (sender == &a2Pump)
    {
      switchControl(a2Pump, state, A2SOLUTION);
    }
    else if (sender == &phUpPump)
    {
      switchControl(phUpPump, state, PHUP_SOLUTION);
    }
    else if (sender == &phDownPump)
    {
      switchControl(phDownPump, state, PHDOWN_SOLUTION);
    }
  } // state on - off
} // swtich callback
/**
 *  @brief  This function is used to get the pH value from the pH sensor.
 */
double getValuePHSensor(float temperature)
{

  double temp = temperature ? temperature : _temperature;
  float rawReadVoltage = analogRead(PHPIN);
  DEBUG_PRINT("rawReadVoltage: ");
  DEBUG_PRINTLN(rawReadVoltage);
  float slope = (7.0 - 4.0) / ((_neutralVoltage - 1500.0) / 3.0 - (_acidVoltage - 1500.0) / 3.0);
  float intercept = 7.0 - slope * (_neutralVoltage - 1500.0) / 3.0;
  float _phValue = slope * (rawReadVoltage - 1500.0) / 3.0 + intercept; // y = k*x + b

  //* ANALOG_SUPPLY_VOLTAGE / 1023;
  DEBUG_PRINT("pH Value: ");
  DEBUG_PRINTLN(_phValue);
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
    if (i > 1)
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
  // DEBUG_INIT();
  Serial.begin(SERIAL_BAUD_RATE);
  Serial.println("Starting setup...");
  Serial.println("DNS and DHCP-based web client test 2024-02-04"); // so I can keep track of what is loaded start the Ethernet connection:connect to wifi

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
  device.setName(deviceName);
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
  uptimeSensor.setName("ReadCount");
  uptimeSensor.setUnitOfMeasurement("#");
  // orbSensor.setIcon("mdi:home");
  orbSensor.setIcon("mdi:current-dc");
  orbSensor.setName("ORB");
  orbSensor.setUnitOfMeasurement("mv");
  // setup phSensor
  phSensor.setIcon("mdi:oil-temperature");
  phSensor.setName("pH");
  phSensor.setUnitOfMeasurement("pH");
  // setup the device
  temperature.setIcon("mdi:thermometer");
  temperature.setName("Temperature");
  temperature.setUnitOfMeasurement("°C");
  // setup the tdsSensor
  tdsSensor.setIcon("mdi:water");
  tdsSensor.setName("TDS");
  tdsSensor.setUnitOfMeasurement("ppm");
  // setup the ecSensor
  ecSensor.setIcon("mdi:water");
  ecSensor.setName("EC");
  ecSensor.setUnitOfMeasurement("ms/cm");
  // setup the tankLevelSensor
  tnakLevelSensor.setIcon("mdi:water");
  tnakLevelSensor.setName("Tank Level");
  tnakLevelSensor.setDeviceClass("moisture");
  pinMode(LEVELPIN, INPUT);

  // setup the buttons for the pumps
  a1Pump.setIcon("mdi:water");
  a1Pump.setName("A1 Pump");
  a1Pump.setDeviceClass("switch");
  switchControl(a1Pump, false, A1SOLUTION);
  // handle switch state callback
  a1Pump.onCommand(onSwitchCommand);

  // setup the buttons for the pumps
  a2Pump.setIcon("mdi:water");
  a2Pump.setName("A2 Pump");
  a2Pump.setDeviceClass("switch");
  switchControl(a2Pump, false, A2SOLUTION);
  // handle switch state callback
  a2Pump.onCommand(onSwitchCommand);
  // setup the buttons for the pumps

  phUpPump.setIcon("mdi:water");
  phUpPump.setName("pH UP Pump");
  phUpPump.setDeviceClass("switch");
  switchControl(phUpPump, false, PHUP_SOLUTION);
  // handle switch state callback
  phUpPump.onCommand(onSwitchCommand);
  // setup the buttons for the pumps
  phDownPump.setIcon("mdi:water");
  phDownPump.setName("pH Down Pump");
  phDownPump.setDeviceClass("switch");
  switchControl(phDownPump, false, PHDOWN_SOLUTION);
  // handle switch state callback
  phDownPump.onCommand(onSwitchCommand);

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
    // unsigned long uptimeValue = millis() / 1000;
    readCount++;
    uptimeSensor.setValue(readCount);
    // ignore the imitial readings as it takes time for the sensors to stabilize
    if (readCount > 10)
    {
      // set orbSensor value
      uint16_t reading = analogRead(ORPPIN);
      orbSensor.setValue(reading);
      // set temperature value
      float tempReading = getValueTemperatureSensor();
      temperature.setValue(tempReading);
      // set phSensor values
      float phReading = getValuePHSensor(tempReading);
      phSensor.setValue(phReading);
      // set tdsSensor value
      float tdsReading = getTDSValue(tempReading);
      tdsSensor.setValue(tdsReading);
      // set ecSensor value
      float ecReading = getECValue(tempReading);
      ecSensor.setValue(ecReading);
      // set tankLevelSensor value
      int levelReading = digitalRead(LEVELPIN);
      tnakLevelSensor.setState(levelReading);
    }
    // reset loop timer
    lastUpdateAt = millis();
  }

  // You can also change the state at runtime as shown below.
  // This kind of logic can be used if you want to control your light using a button connected to the device.
  // light.setState(true); // use any state you want
}