/**
 * @file CpuLoop.cpp
 * @author Nicolas Dimate (https://github.com/junmorenodi99)
 * @brief Implementation of the methods defined in 'CpuLoop.h'
 * @version 0.1
 * @date 2022-03-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "CpuLoop.h"

CpuLoop::CpuLoop(Calibrator &calibratorAtt_):calibratorAtt(calibratorAtt_)
{};

void CpuLoop::runTime(double  duration_ms)
{
    runLoop(calibratorAtt.nLoops(duration_ms));
};



