# ArduinoTools
Useful code for Arduino development

## Installation
To use, copy directory including ArduinoTools.h and ArduinoTools.cpp to libraries directory.
Example usage in Examples directory.

## Tick
A simple way to introduce periodic functions without using interrupts. 
There are 3 parameters:
1) tick_cbfun
- function to be called
2) interval
- time in milliseconds between each called
3) lifetime
- time in milliseconds before the tick_cbfun is no longer called
