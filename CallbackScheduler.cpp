#include "CallbackScheduler.h"

void CallbackScheduler::scheduleCallback(unsigned long callback_duration, Callback callback) {
  ScheduledCallback scheduled;
  scheduled.callback_duration = millis() + callback_duration;
  scheduled.callback = callback;
  
  this->callbacks.push_back(scheduled);
}

void CallbackScheduler::update() {
  if (this->callbacks.empty()) {
    return;
  }
  
  unsigned long current_time = millis();
  
  for (size_t i = 0; i < this->callbacks.size();) {
    if (current_time >= this->callbacks[i].callback_duration) {
      this->callbacks[i].callback();
      this->callbacks.erase(this->callbacks.begin() + i);
    }
    else {
      ++i;
    }
  }
}