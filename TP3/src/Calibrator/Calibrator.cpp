/**
 * @file Calibrator.cpp
 * @author Nicolas Dimate (https://github.com/junmorenodi99)
 * @brief Implementation of the methods defined in 'Calibrator.h'
 * @version 0.1
 * @date 2022-03-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include "Calibrator.h"

using namespace std;


Calibrator::Calibrator(double samplingPeriod_ms, unsigned int nSamples):counter(nSamples)
{
  cout << "Start Calibration... \n"  << endl;
 
	PeriodicTimer::start(samplingPeriod_ms);
  looper->runLoop();

  double xSum=0 , xxSum=0, ySum=0, xySum=0;
  for (unsigned int i = 0; i<nSamples; i++)
  {
    xSum += samplingPeriod_ms*i; 
    ySum += samples[i]; 
    xxSum += samplingPeriod_ms*i*samplingPeriod_ms*i;
    xySum += samplingPeriod_ms*i*samples[i];
  }
  a = (xySum - xSum*ySum/nSamples)/( xxSum - xSum*xSum/nSamples);
  b = (xxSum*ySum - xSum*xySum)/(nSamples*xxSum - xSum*xSum);
};

double Calibrator::nLoops(double duration_ms)
{
  return a*duration_ms+b;
};


void Calibrator::callback()
{
  if (counter == 0)
  {
    samples.push_back(looper->stopLoop());
    stop();
  }
  else
  {
    samples.push_back(looper->getSample());
  }
  counter--;
};

