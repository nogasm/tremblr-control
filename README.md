# tremblr-control
Simple demo for controlling the f-machine Tremblr with an Arduino and 315MHz transmitter

## Seting up the hardware
Get a FS1000A 315MHz transmitter or similar. They can be had for less than $1. This will send control signals (1-way only) to the tremblr.
Wire it up to your arduino of choice, connecting GND to GND, VCC to 5V, and DATA to an Arduino DIO pin. By default, this sketch uses port 14.

## Running up the software
Install the [rc-switch](https://github.com/sui77/rc-switch) library from the Arduino library manager. If you've used a pin other than #14 for data, change the pin number in the enableTransmit() line of the demo sketch to match.
With the correct board selected, you should be able to build the sketch and upload it to your arduino.
You should have the Tremblr started when you turn on your arduino running the demo. The speed will ramp up, stop, and repeat.

This was tested with a Tremblr V1. It's possible that later versions will use different remote control codes. If this demo does not work for your Tremblr, the control codes (RC_UP, RC_DOWN, etc.) can actually be read off the traces on Tremblr remote PCB, or recorded with a 315MHz reciever. Check the [rc-switch](https://github.com/sui77/rc-switch) repository for details on how to set this up.
