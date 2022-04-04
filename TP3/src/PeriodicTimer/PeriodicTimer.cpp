/**
 * @file PeriodicTimer.cpp
 * @author Nicolas Dimate (https://github.com/junmorenodi99)
 * @brief Implementation of the methods defined in 'PeriodicTimer.h'
 * @version 0.1
 * @date 2022-03-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "PeriodicTimer.h"
#include "../timerLib/timerLib.h"


void PeriodicTimer::start(double  duration_ms)
{
  itimerspec its;
  its.it_value = timespec_from_ms(duration_ms);
  its.it_interval = its.it_value;
  timer_settime(tid, 0, &its, NULL);
  
};
