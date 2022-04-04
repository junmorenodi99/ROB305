#ifndef CpuLoop_h_INCLUDED
#define CpuLoop_h_INCLUDED

/**
 * @file CpuLoop.h
 * @author Nicolas Dimate (https://github.com/junmorenodi99)
 * @brief Defines the class CpuLoop derivated from Looper. Allows to obtain a calibration given a defined time.
 * @version 0.1
 * @date 2022-03-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <iostream>
#include "../Calibrator/Calibrator.h"
#include "../Looper/Looper.h"


class CpuLoop:public Looper
{

private : 
    /**
     * @brief Calibrator Object
     * 
     */
    Calibrator calibratorAtt;

public:

    /**
     * @brief Construct a new Cpu Loop object
     * 
     * @param calibratorAtt 
     */
    CpuLoop(Calibrator& calibratorAtt);

    /**
     * @brief Executes a looper object in a specified time
     * 
     * @param duration_ms 
     */
    void runTime(double  duration_ms);

};

#endif