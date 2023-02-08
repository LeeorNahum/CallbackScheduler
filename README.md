# CallbackScheduler

An Arduino library for scheduling callbacks to run after a certain amount of time.

## Description

This library enables you to schedule callbacks to be executed at a specific time in the future. It provides an easy way to add time-sensitive functionality to your sketches. You can specify the exact amount of time until a callback function should be executed which will be handled by the library.

## Usage

Here is an example of how to use PinInit:

``` C++
#include <PinInit.h>

#define LED_PIN 13

#define BUTTON_1 2
#define BUTTON_2 3
#define BUTTON_3 4

#define BUTTON_4 5

void setup() {
  PinInit(
    output, LED_PIN,
    input_pullup, BUTTON_1, BUTTON_2, BUTTON_3,
    input, BUTTON_4
  );
}

void loop() {
  // Your code here
}
```
