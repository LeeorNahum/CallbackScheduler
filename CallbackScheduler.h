#ifndef CALLBACKSCHEDULER_H
#define CALLBACKSCHEDULER_H

#include <Arduino.h>
#include <vector>

class CallbackScheduler {
  public:
    using Callback = std::function<void()>;
    
    void scheduleCallback(unsigned long callback_duration, Callback callback); // TODO add optional override enum flags which either replace, add (default?), or [dont add if it already exists]
    void update();
    
  private:
    struct ScheduledCallback {
      Callback callback;
      unsigned long callback_duration;
    };
    
    std::vector<ScheduledCallback> callbacks;
};

extern CallbackScheduler Scheduler;

#endif