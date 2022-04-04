/**
 * @file main_td3c.cpp
 * @author Nicolas Dimate (https://github.com/junmorenodi99)
 * @brief Main function for testing the calibration with implemented classes
 * @version 0.1
 * @date 2022-03-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <time.h>
#include "Calibrator/Calibrator.h"
#include "CpuLoop/CpuLoop.h"
#include "ChronoLib/ChronoLib.h"
#include "timerLib/timerLib.h" 
#include "Timer/Timer.h" 
#include "Looper/Looper.h" 
#include "PeriodicTimer/PeriodicTimer.h" 

using namespace std;


/**
 * @brief 
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(){

    //Declaracion de parametros 

    double samplingPeriod_ms = 10.0;
    unsigned int nSamples = 1000;
    double duration_ms = 7000.0;
    

    Calibrator calibrator(samplingPeriod_ms, nSamples);

    cout << "Calibrator time " << samplingPeriod_ms*nSamples << " (ms)" <<  endl;  
    cout << "Expected Chrono Time " << duration_ms/1.0 << " (ms)" <<  endl; 

    // Testing the estimation

    CpuLoop loop = CpuLoop(calibrator);
    Chrono chrono; 

    // Running Timer with the estimated number of Loops    
    loop.runTime(duration_ms);
    chrono.stop();

    cout << "Real Chrono Time " << chrono.lap() << " (ms)" <<  endl; 

    return 0;

}

