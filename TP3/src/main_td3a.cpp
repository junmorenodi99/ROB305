/**
 * @file main_td3a.cpp
 * @author Nicolas Dimate (https://github.com/junmorenodi99)
 * @brief Main function for testing the Chrono class created
 * @version 0.1
 * @date 2022-03-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <iostream>
#include "timerLib/timerLib.h"
#include "ChronoLib/ChronoLib.h"
#include <string>

using namespace std;
 
/**
 * @brief The main function implementing the test for the Chrono Class
 * 
 * @return int 
 */
int main(){

    Chrono chrono1; 

    cout << "The value the start is : "  <<  chrono1.startTime() << " \n"  <<endl;
    cout << "The  Chrono is active : "  <<  chrono1.isActive() << " \n"  <<endl;
    cout << "The lap value in this moment is : "  <<  chrono1.lap() << " \n"  <<endl;
    cout << "We stop the chrono " << " \n"  <<endl;

    chrono1.stop();

    cout << "The value the stoptime is : "  <<  chrono1.stopTime() << " \n"  <<endl;
    cout << "We restart the chrono " << " \n"  <<endl;

    chrono1.restart();
    
    cout << "We keep counting " << " \n"  <<endl;
    cout << "We keep counting " << " \n"  <<endl;
    cout << "We stop the chrono " << " \n"  <<endl;

    chrono1.stop();

    cout << "The lap value in this moment is : "  <<  chrono1.lap() << " \n"  <<endl;

    return 0;

}
