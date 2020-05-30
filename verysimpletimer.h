/*
Arduino Library for very simple and basic timing function.
All timings are calculated by a given functionparameter time, so this library is internaly not relying on millis(), therefore it can be used during debugging/simulation/componenttest.

GPLv3
by hagre 2019
*/

#ifndef verysimpletimer_h
#define verysimpletimer_h

#include <Arduino.h>

class VerySimpleTimer
{
public:
    VerySimpleTimer();
    void setIntervalMs(uint32_t intervalMs);
    void resetTimingNow (uint32_t nowMs);
    int32_t getStatus (uint32_t nowMs, bool resetOnTrigger = true);
private:
    uint32_t _lasttime = 0;
    uint32_t _interval = 0;
};

#endif
