/**
 * @file CounterDown.cpp
 * @author Nicolas Dimate (https://github.com/junmorenodi99)
 * @brief Implementation of the methods defined in 'CounterDown.h'
 * @version 0.1
 * @date 2022-03-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <iostream>
#include "CounterDown.h"

using namespace std;

CounterDown::CounterDown(int n)
{
    counter = n;
};

void CounterDown::callback()
{
    if (counter == 0 )
    {
        stop();
    }
    counter--;
    cout << "The counter value is " << counter << endl;
};

int CounterDown::get_counter()
{
    return counter;
};
