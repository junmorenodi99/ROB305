/**
 * @file main_td1a.cpp
 * @author Nicolas Dimate (https://github.com/junmorenodi99)
 * @brief Test file for the timerLib library
 * @version 0.1
 * @date 2022-03-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include "timerLib/timerLib.h"
using namespace std;

 
/**
 * @brief main
 * 
 * @return int 
 */

int main(){

    timespec time_1 = {4 , 215}; 
    timespec time_2 = {5 , -125}; 

  //Showing default
  cout << "Initial time_1 value : " << time_1.tv_sec << ", nanosec: " << (double)time_1.tv_nsec << endl;
  cout << "Initial time_2 value : " << time_2.tv_sec << ", nanosec: " << (double)time_2.tv_nsec << endl;
  
  //Testing ms convert
  cout << "Convertion to ms: " << timespec_to_ms(time_1) << " (ms)" << endl;
  
  //Testing the invert convertion
  cout << "Returning to intial value (seconds): " << timespec_from_ms(timespec_to_ms(time_1)).tv_sec << "(s)" << endl;
  cout << "Returning to intial value (nanoseconds): " << (double)timespec_from_ms(timespec_to_ms(time_1)).tv_nsec  << "(ns)" << endl; 

  //Getting real time
  cout << "Real time: " << timespec_now().tv_sec << endl;

  //Negating a time:
  cout << "Negative time in sec:" << timespec_negate(time_2).tv_sec << ", in nano: " << timespec_negate(time_2).tv_nsec << endl;

  //Adding two timers:
  cout << "Adding the two timers, sec: " << timespec_add(time_1, time_2).tv_sec << ", nanosec: " << timespec_add(time_1, time_2).tv_nsec << endl;

  //Subtracting two timers:
  cout << "Subtracting the two timers, sec: " << timespec_subtract(time_1, time_2).tv_sec << ", nanosec: " << timespec_subtract(time_1, time_2).tv_nsec << endl;

  //Time waited
  cout << "Waited time, sec: " << timespec_wait(time_2).tv_sec << ", nanosec: " << timespec_wait(time_2).tv_nsec << endl;

  //Testing Negative Operator:
  cout << "Negative only, sec: " << (-time_1).tv_sec << ", nanosec: " << (-time_1).tv_nsec << endl;

  timespec auxiliarVar;
  auxiliarVar.tv_sec = time_1.tv_sec;
  auxiliarVar.tv_nsec = time_1.tv_nsec;

  // Testing suma operator
  cout << "+= test, sec: " << (auxiliarVar+=time_2).tv_sec << ", nanosec: " << (auxiliarVar+=time_2).tv_nsec << endl;
  
  // Testing subtract operator
  cout << "-= test, sec: " << (auxiliarVar-=time_2).tv_sec << ", nanosec: " << (auxiliarVar-=time_2).tv_nsec << endl;

  // Testing equality operator
  cout << "Equals test: " << (time_1 == time_2) << endl;

  // Testing different operator
  cout << "Different test: " << (time_1 != time_2) << endl;

  // Testing 'greater than' operator
  cout << "Bigger than test: " << (time_1 > time_2) << endl;

  // Testing 'smaller than' operator
  cout << "Smaller than test: " << (time_1 < time_2) << endl;

  return 0;
}