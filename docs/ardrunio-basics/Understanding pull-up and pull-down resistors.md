# Understanding pull-up and pull-down resistors

Taken from <https://makezine.com/article/technology/arduino/understanding-pullup-and-pulldown-r/>

In digital electronics the engineers use the terms pull-up or pull-down resistor, this is a simple resistor usually between 10k and 100k, to define the input state when no signal source is connected, this way overriding the noise signal, common sense dictates that when you have potentially larger noise then a smaller resistor is needed, but don’t be careless about it, don’t place a 100Ohm resistor because your signal source must be able to “defeat” the pull-up(down) resistor. A rule of thumb is to use at least 10x larger pull-up(down) resistor then your signal source impedance.

The pull-up term is used when the resistor connects the pin to the + and pull-down when connects to the ground, but then which should you choose? Good question, in these days it doesn’t really mater, your application or the pcb design should dictate, the older generation digital IC’s had asymmetrical current sink/source capability, they could sink more current and because of that the pull-up resistor was more common.
