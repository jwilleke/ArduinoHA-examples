//Virtual Items
Number Irrigation_Curr "Automatic irrigation status: [MAP(irrigation_zone.map):%s]"
Switch Irrigation_Manual "Irrigation state [%s]"
Switch Irrigation_Auto
Switch Irrigation_Start "Manual Start" ["Switchable"]
Switch Irrigation_Start_2
Switch Irrigation_Start_3

Group:Switch:OR(ON,OFF) gIrrigation "Irrigation is currently [%s]"
Group:Number:SUM gIrrigation_Times "Total Irrigation Time is [%d mins]"
Number Water_Use "Estimate water use is [%d L]"

// Pump
Switch Irrigation_Pump1    "Irrigation Pump"  (gIrrigation) {channel="shelly:shellyrgbw2-white:6ea784:channel4#brightness"}

// Valves
Switch Irrigation_Zone_1     "Zone 1 Valve"    (gIrrigation)  {channel="shelly:shellyrgbw2-white:6ea784:channel1#brightness"}
Number Irrigation_Zone_1_Time (gIrrigation_Times)
Switch Irrigation_Zone_1_Auto "Zone 1 Auto"

Switch Irrigation_Zone_2     "Zone 2 Valve"     (gIrrigation) {channel="shelly:shellyrgbw2-white:6ea784:channel2#brightness"}
Number Irrigation_Zone_2_Time (gIrrigation_Times)
Switch Irrigation_Zone_2_Auto "Zone 2 Auto"

Switch Irrigation_Zone_3     "Zone 3 Valve"     (gIrrigation) {channel="shelly:shellyrgbw2-white:6ea784:channel3#brightness"}
Number Irrigation_Zone_3_Time (gIrrigation_Times)
Switch Irrigation_Zone_3_Auto "Zone 3 Auto"

``` yaml
meg.payload = {
  "mode": "color',
  "red": 0,
  "green" : 0,
  "blue" : 0,
  "white" : 0,
  "effect": 3,
  "turn": "on"
}
return msg;
```

{"payload":"off","data":{"entity_id":"switch.nutrient_tank_stirer_1","old_state":{"entity_id":"switch.nutrient_tank_stirer_1","state":"on","attributes":{"device_class":"switch","icon":"mdi:pot-mix","friendly_name":"Nutrient Tank Stirer 1"},"last_changed":"2024-03-23T12:57:05.270112+00:00","last_updated":"2024-03-23T12:57:05.270112+00:00","context":{"id":"01HSNP5Q7612PVJ4X9JNWRBRHA","parent_id":null,"user_id":"59569fa4a26444a3a755e1a9122c0139"}},"new_state":{"entity_id":"switch.nutrient_tank_stirer_1","state":"off","attributes":{"device_class":"switch","icon":"mdi:pot-mix","friendly_name":"Nutrient Tank Stirer 1"},"last_changed":"2024-03-23T12:57:06.906290+00:00","last_updated":"2024-03-23T12:57:06.906290+00:00","context":{"id":"01HSNP5RYCBHY4DYJ2KTKY4H1N","parent_id":null,"user_id":"59569fa4a26444a3a755e1a9122c0139"},"timeSinceChangedMs":8}},"topic":"switch.nutrient_tank_stirer_1","_msgid":"deaf0e480854df15"}