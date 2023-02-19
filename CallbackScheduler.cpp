#include "CallbackScheduler.h"

CallbackScheduler::ScheduledCallback CallbackScheduler::callbacks[MAX_CALLBACK_ARRAY_SIZE] = {nullptr};
unsigned int CallbackScheduler::num_callbacks = 0;

void CallbackScheduler::scheduleCallback(unsigned long callback_time_ms, Callback callback) {
  if (num_callbacks >= MAX_CALLBACK_ARRAY_SIZE) {
    return;
  }

  callbacks[num_callbacks].callback_time_ms = millis() + callback_time_ms;
  callbacks[num_callbacks++].callback = callback;
}

void CallbackScheduler::update() {
  unsigned long current_time = millis();

  for (int i = 0; i < num_callbacks;) {
    if (current_time >= callbacks[i].callback_time_ms) {
      callbacks[i].callback();
      num_callbacks--;
      if (i != num_callbacks) {
        callbacks[i] = callbacks[num_callbacks];
      }
    }
    else {
      i++;
    }
  }
}