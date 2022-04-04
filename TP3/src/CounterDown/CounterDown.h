#ifndef CounterDown_h_INCLUDED
#define CounterDown_h_INCLUDED

/**
 * @file CounterDown.h
 * @author Nicolas Dimate (https://github.com/junmorenodi99)
 * @brief Defines the class CounterDown derivated from PeriodicTimer 
 * @version 0.1
 * @date 2022-03-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <iostream>
#include "../PeriodicTimer/PeriodicTimer.h"

/**
 * @brief Class CounterDown derivated from PeriodicTimer
 * 
 */
class CounterDown:public PeriodicTimer
{
public: 
    /**
     * @brief Construct a new CounterDown object
     * 
     * @param n 
     */
    CounterDown(int n);

    /**
     * @brief Get the counter attribute
     * 
     * @return int 
     */
    int get_counter();

private:
    int counter;

protected:  
    /**
     * @brief The handle function
     * 
     */
    void callback();
};

#endif


