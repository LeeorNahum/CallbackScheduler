# CallbackScheduler

An Arduino library for scheduling callbacks to run after a certain amount of time.

## Description

This library enables you to schedule callbacks to be executed at a specific time in the future. It provides an easy way to add time-sensitive functionality to your sketches. You can specify the exact amount of time until a callback function should be executed which will be handled by the library.

## Usage

Here is an example of how to use the CallbackScheduler library:

``` C++
#include <CallbackScheduler.h>

void setup() {
  CallbackScheduler::addCallback(callback1, 1000);
  CallbackScheduler::addCallback(callback2, 2000);
}

void loop() {
  CallbackScheduler::update();
}

void callback1() {
  Serial.println("Callback 1 called!");
}

void callback2() {
  Serial.println("Callback 2 called!");
}
```
