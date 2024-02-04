# Using Arduino and Home Assistant

[home-assistant-integration](https://www.arduino.cc/reference/en/libraries/home-assistant-integration/)

[Github](https://github.com/dawidchyrzynski/arduino-home-assistant/tree/main)

[Github Issues](https://github.com/jwilleke/ArduinoHA-examples/issues/)

## ArduinoHA

### HADevice

HADevice represents the physical device where the library is installed.
Logically it’s a group of types like sensors, switches, lights and so on. In the Home Assistant, it’s listed with properties that may be configured using the library’s API.

Each property except the unique ID is optional. Setting optional properties increases flash and RAM usage so it’s not recommended to set them on lower-spec MCUs. The supported properties are:

- unique ID*
- name
- software version
- manufacturer
- model

HADevice unique ID needs to be unique in a scope of a Home Assistant instance. The safest solution is to use the MAC address of an Ethernet or Wi-Fi chip but you can also implement your own solution.

```c++
// use your own unique bytes sequence or use mac of WiFi
byte myId[] = {0x00, 0x10, 0xFA, 0x6E, 0x38, 0x4A};
HADevice device(myId, sizeof(myId));

void setup() {
    device.setName("Bedroom Light Controller");
    device.setSoftwareVersion("1.0.0");
    device.setManufacturer("Developer Corp.");
    device.setModel("ABC-123");
    // ...
    device.enableSharedAvailability();
    device.setAvailability(false); // changes default state to offline
    // MQTT LWT
    device.enableLastWill();
    // Discovery
    mqtt.setDiscoveryPrefix("homeassistant");
    mqtt.setDataPrefix("aha");
}
```

### Availability reporting

Home Assistant allows to track online/offline states of devices and device types. In this way controls available in the panel will be displayed as disabled if a device is offline.

The library allows to expose state of the entire device (i.e. shared availability) or specific type (sensor, switch, light, etc.). By default this feature is not enabled to save resources (RAM and flash) but you can easily turn it on as shown below.

#### Shared availability

It is highly recommend to use shared availability feature as it allows to utilize MQTT LWT. Basically, shared availability allows to control availability of all types related to a specific device. For example: if your device has 5 switches and 2 buttons you can control their availability in the HA panel using a single method call.

See example above showing how to enable shared availability of the device. By default, the device is considered online but you can control its state manually using HADevice::setAvailability(bool online) method. In most cases you won’t need to control availability manually as the library takes care of availability as long as the device is powered on.

#### MQTT LWT

When LWT feature is enabled the device becomes offline in the HA panel even if you cut off power supply. This solution is implemented by MQTT broker that automatically publishes the message when the TCP connection to the device is lost.

### Discovery

The library automatically maintains connection to the MQTT broker and takes care of the discovery process. Each device type that you create (sensor, switch, light, fan, etc.) is automatically registered in MQTT manager. Whenever connection with the MQTT broker is acquired the configuration of all device types is pushed to the Home Assistant.

In some cases you may need to change prefix of MQTT topics. There are two types of topics utilized by the library:

- discovery topic - used for publishing device types’ configuration (default: homeassistant)
- data topic - used for publishing states, data, etc. (default: aha)

### Sensor Types (Device types)

In the library, HABaseDeviceType is the type of Sensor(s) which are attached to Your physical device (for example ESP-01 board) can have multiple sensor types (device types) assigned.

Represents a single entity in the Home Assistant panel. Registering a new device type requires some flash and RAM memory to be utilized. On less powerful units like Arduino Uno, you may quickly hit the limit of resources, so keeping the device simple is recommended. Hitting the resource limit will result in random reboots of the device.

[Device types API](https://github.com/dawidchyrzynski/arduino-home-assistant/tree/main/src/device-types) describes the current "Sensor Types" supported.

By default, the maximum number of device types is 6.

```c++
// change the number of Device Types
HAMqtt mqtt(client, device, 12); // <------------ 12 is a new limit of device types
```
