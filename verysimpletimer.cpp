/*
Arduino Library for very simple and basic timing function.
All timings are calculated by a given functionparameter time, so this library is internaly not relying on millis(), therefore it can be used during debugging/simulation/componenttest.

GPLv3
by hagre 2019
*/

#include "verysimpletimer.h"

#include <Arduino.h>

VerySimpleTimer::VerySimpleTimer ( )
{

}

void VerySimpleTimer::setIntervalMs (uint32_t intervalMs)
{
    if (intervalMs == 0){
        intervalMs = 1;
    }
    _interval = intervalMs;
}

void VerySimpleTimer::resetTimingNow (uint32_t nowMs)
{
    _lasttime = nowMs;
}

int32_t VerySimpleTimer::getStatus (uint32_t nowMs, bool resetOnTrigger)
{
    uint32_t actualTimeDifference = nowMs - _lasttime;
    int32_t actualRelativeTimeDifference = actualTimeDifference - _interval;
    if (resetOnTrigger && actualRelativeTimeDifference >= 0){
        resetTimingNow (nowMs);
    }
    return actualRelativeTimeDifference;
}
