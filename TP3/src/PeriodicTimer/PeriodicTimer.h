#ifndef PeriodicTimer_h_INCLUDED
#define PeriodicTimer_h_INCLUDED

/**
 * @file PeriodicTimer.h
 * @author Nicolas Dimate (https://github.com/junmorenodi99)
 * @brief Defines the class derivated from Timer
 * @version 0.1
 * @date 2022-03-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include "../Timer/Timer.h"


/**
 * @brief Class PeriodicTimer that implements a periodic timer Posix.
 * 
 */
class PeriodicTimer:public Timer
{
    public: 
        /**
         * @brief Starts the periodic timer Posix
         * 
         * @param duration_ms 
         */
        void start(double duration_ms);
        
};


#endif

