/**
 * @file timerLib.h
 * @author Nicolas Dimate (https://github.com/junmorenodi99)
 * @brief Definition of the methods for 'timespec' operation 
 * @version 0.1
 * @date 2022-03-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef timerLib_h_INCLUDE
#define timerLib_h_INCLUDE

#include <time.h>
#include <unistd.h>


/**
 * @brief Converting timespec to ms
 * 
 * @param time_ts 
 * @return double 
 */
double timespec_to_ms(const timespec& time_ts);

/**
 * @brief Converting ms to timespec
 * 
 * @param time_ms 
 * @return timespec 
 */
timespec timespec_from_ms(double time_ms);

/**
 * @brief Getting Real time
 * 
 * @return timespec 
 */
timespec timespec_now();

/**
 * @brief Get the oposite of the time
 * 
 * @param time_ts 
 * @return timespec 
 */
timespec timespec_negate(const timespec& time_ts);

/**
 * @brief Sum of timespec
 * 
 * @param time1_ts 
 * @param time2_ts 
 * @return timespec 
 */
timespec timespec_add(const timespec& time1_ts, const timespec& time2_ts);

/**
 * @brief Substraction of timespec
 * 
 * @param time1_ts 
 * @param time2_ts 
 * @return timespec 
 */
timespec timespec_subtract(const timespec& time1_ts, const timespec& time2_ts);

/**
 * @brief Suspension of process
 * 
 * @param delay_ts 
 * @return timespec 
 */
timespec timespec_wait(const timespec& delay_ts);

// Declaration of Operators

/**
 * @brief Negative Operator
 * 
 * @param time_ts 
 * @return timespec 
 */
timespec  operator- (const timespec& time_ts);

/**
 * @brief Addition operator 
 * 
 * @param time1_ts 
 * @param time2_ts 
 * @return timespec 
 */
timespec  operator+ (const timespec& time1_ts, const timespec& time2_ts);

/**
 * @brief Substracition operator
 * 
 * @param time1_ts 
 * @param time2_ts 
 * @return timespec 
 */
timespec  operator- (const timespec& time1_ts, const timespec& time2_ts);

/**
 * @brief Addition Assignment
 * 
 * @param time_ts 
 * @param delay_ts 
 * @return timespec& 
 */
timespec& operator+= (timespec& time_ts, const timespec& delay_ts);

/**
 * @brief Substraction Assigment
 * 
 * @param time_ts 
 * @param delay_ts 
 * @return timespec& 
 */
timespec& operator-= (timespec& time_ts, const timespec& delay_ts);

/**
 * @brief Equal Operator
 * 
 * @param time1_ts 
 * @param time2_ts 
 * @return true 
 * @return false 
 */
bool operator== (const timespec& time1_ts, const timespec& time2_ts);

/**
 * @brief Different Operator
 * 
 * @param time1_ts 
 * @param time2_ts 
 * @return true 
 * @return false 
 */
bool operator!= (const timespec& time1_ts, const timespec& time2_ts);

/**
 * @brief Greater Than Operator
 * 
 * @param time1_ts 
 * @param time2_ts 
 * @return true 
 * @return false 
 */
bool operator< (const timespec& time1_ts, const timespec& time2_ts);

/**
 * @brief Smaller Than Operator
 * 
 * @param time1_ts 
 * @param time2_ts 
 * @return true 
 * @return false 
 */
bool operator> (const timespec& time1_ts, const timespec& time2_ts);

#endif