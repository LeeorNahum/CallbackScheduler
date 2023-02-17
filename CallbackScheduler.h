#ifndef CALLBACKSCHEDULER_H
#define CALLBACKSCHEDULER_H

#ifndef MAX_CALLBACK_ARRAY_SIZE
#define MAX_CALLBACK_ARRAY_SIZE 10
#endif

class CallbackScheduler {
  public:
    using Callback = void (*)();

    static void scheduleCallback(unsigned long callback_time_ms, Callback callback);
    static void update();

  protected:
    struct ScheduledCallback {
      Callback callback;
      unsigned long callback_time_ms;
    };

    static ScheduledCallback callbacks[MAX_CALLBACK_ARRAY_SIZE];
    static unsigned int num_callbacks;
};

#endif