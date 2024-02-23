# Connections

There are a lot of connections in this project.

## Cable 1

Cable 1 is a 7 conductor cable from the Conrtol Board to the Pump Container.

12 V is on this cable to power the verios motors in the Pump Container.

| Item | MACRO | IO PIN | Relay | Relay Pin | CABLE | Color |
|  --- | --- | --- | --- | --- | --- | --- |
| ph Up Pump | PHUP_SOLUTION_PUMP | 8 | 1 | 1 | 1 |RED |
| ph Down Pump | PHDOWN_SOLUTION_PUMP | 9 | 1 | 4 | 1 | GREEN |
| A1 Pump |A1SOLUTION_PUMP | 10 | 2 | 1 | 1 | PURPLE |
| A2 Pump | A2SOLUTION_PUMP | 11 | 2 | 4 | 1 | ORaNGE |
| STIRER 1 Group | SOLUTION_STIRER_1 | 12 | 3 | 1 | 1 | BROWN |
| STIRER 2 Group | SOLUTION_STIRER_2 | 13 | 3 | 4 | 1 | YELLOW |

## Cable 2

Cable 2 supplies 12 V and GND to the the Pump Container.
Other useage of this cable could be made in the future.

## Relays

[Relay connections](/docs/Devices/Relays%20and%20Motor%20Contollers.md)