/**
 * @file CpuLoop.cpp
 * @author Nicolas Dimate (https://github.com/junmorenodi99)
 * @brief Implementation of the methods defined in 'Looper.h'
 * @version 0.1
 * @date 2022-03-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <iostream>
#include "Looper.h" 


double Looper::runLoop(double nLoops )
{
    doStop = false;

    for(iLoop=0;iLoop<nLoops;iLoop++)
    {
        if(doStop)
        {
            break;
        }
    }
    return iLoop;
};

double Looper::getSample()
{
    return iLoop;
};

double Looper::stopLoop()
{
    doStop = true;
    return iLoop;
};
