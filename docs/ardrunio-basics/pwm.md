# PWM (Pulse Width Modulation)

PWM literally means, that an analog value is being MODULATED on a __digital signal__.

In essence this is the opposite of modulation schemes like AM. Suppose you have an analog signal that you want to send to an actuator. However, the microcontroller platform you’re using is a MOSFET based, digital one. Thus, in order to attain your desired output, you will have to Simulate an analog signal by switching your output on and off very quickly.

> Remember: PWM can only mimic and simulate the effects of a pure analog signal, it can never perform pure digital to analog conversion (which generally requires some active components like capacitors and inductors). However, for most applications, a PWM signal is good enough.

## How does the arduino perform PWM?

The Arduino uno has a ?? MHz crystal oscillator. This means that its internal clock timing is: 1/16 x 10 $^6$ = 62.5 nSec.

This means, that theoretically, an Arduino’s clock switches on and off once every 62.5 nSec.

On the Uno, pin 5 and 6 can produce a PWM signal with 980 hertz, that means a complete signal cycle in 1020.4 microseconds. This means that the registers are set to divide the total clock rate by approximately 16,326 (this of course, will be a multiple of many registers instead of a single number). Thus, you can have a minimum on-time of 1020.4 uSec / 2 = 510.2 uSec , and a minimum off-time of 510.2 uSec.

Now you can produce signals that turn on and off quick enough to give the appearance of being analog signals. In other words, if you want to run an LED at 50% speed, you’ll give it a signal of 50% duty cycle. However, if your signal has a frequency of let’s say 1 hertz, you’ll be able to visibly witness the LED turning on and off by your naked eyes. What’s the solution you ask? Well, you hack human anatomy of course. While there’s still debate on the sampling rate of the human eye and the brain, it is well known that the humans perceive flickering above 300 Hz (on the safe side. This can be as low as 60 Hz, hence you never thought that those old incandescent bulbs were flickering the whole time, or that retro CRT was refreshing itself continuously) as a mere dimmed, constant source of light. And the PWM on the Arduino can produce signals at 980 Hertz, so by cranking up the frequency, you produce a mirage of a continuously dim LED, working at 50% capacity. While in reality, that LED is being switched on and off very rapidly. This, my friend, is a crash course on PWM (which is certainly not sufficient enough).

## PwmOut API

[PwmOut API](https://os.mbed.com/docs/mbed-os/v6.16/apis/pwmout.html) to control the frequency and duty cycle of a PWM signal.

- PWM duty-cycle is tyrpically the Pulse Width as (0-100%)
- PWM period 

## PWM Duty Cycle

![PWM Duty Cycle](/resources/Duty_Cycle_Examples.png)

## More information

- [Secrets of Arduino PWM](https://docs.arduino.cc/tutorials/generic/secrets-of-arduino-pwm/)