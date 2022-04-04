#ifndef ChronoLib_h_INCLUDED
#define ChronoLib_h_INCLUDED

/**
 * @file ChronoLib.h
 * @author Nicolas Dimate (https://github.com/junmorenodi99)
 * @brief Defines the class chrono that uses the 'timerLib' library
 * @version 0.1
 * @date 2022-03-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <time.h> 
#include "../timerLib/timerLib.h"

/**
 * @brief The class chrono that uses the 'timerLib' library
 * 
 */
class Chrono
{
public:

	timespec startTime_;
	timespec stopTime_;

	/**
	 * @brief Construct a new Chrono object with the actual time
	 * 
	 */
	Chrono();
	
	/**
	 * @brief Set the stopTime_ as the actual time
	 * 
	 */
	void stop();

	/**
	 * @brief Restart the chronometre
	 * 
	 */
	void restart();

	/**
	 * @brief Verification of the chronometre status
	 * 
	 * @return true 
	 * @return false 
	 */
	bool isActive();

	/**
	 * @brief  Return the value of startTime_ in ms
	 * 
	 * @return double 
	 */
	double startTime();

	/**
	 * @brief Return the value of stopTime_ in ms
	 * 
	 * @return double 
	 */
	double stopTime();

	/**
	 * @brief if the stopwatch is not active, it allows to obtain the duration of 
	 * the interval between a startTime_ and a stopTime_. If the counter is active, 
	 * it allows to obtain the time between a startTime_ and the current time.
	 * 
	 * @return double 
	 */
	double lap();

};

#endif