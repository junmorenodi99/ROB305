#ifndef Calibrator_h_INCLUDED
#define Calibrator_h_INCLUDED


/**
 * @file Calibrator.h
 * @author Nicolas Dimate (https://github.com/junmorenodi99)
 * @brief Definition of a class derived from PeriodicTimer
 * @version 0.1
 * @date 2022-03-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <vector>
#include "../PeriodicTimer/PeriodicTimer.h"
#include "../Looper/Looper.h"

/**
 * @brief Class derivated from PeriodicTimer
 * 
 */
class Calibrator:public PeriodicTimer
{
private:
	double a; 
	double b; 
	std::vector<double> samples; 
	unsigned int counter; 

public:
	Looper* looper; 

	/**
	 * @brief Construct a new Calibrator object
	 * 
	 * @param samplingPeriod_ms 
	 * @param nSamples 
	 */
	Calibrator(double samplingPeriod_ms, unsigned nSamples);

	/**
	 * @brief Estimates the number of loops
	 * 
	 * @param duration 
	 * @return double 
	 */
	double nLoops(double duration); 


protected:

	/**
	 * @brief Handle Function
	 * 
	 */
	void callback(); 

};

#endif