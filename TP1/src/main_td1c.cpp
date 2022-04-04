/**
 * @file main_td1c.cpp
 * @author Nicolas Dimate (https://github.com/junmorenodi99)
 * @brief Main function to realize the increment without using signal
 * @version 0.1
 * @date 2022-03-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <time.h> 
#include <signal.h>
#include <string> 
#include "timerLib/timerLib.h" 
using namespace std;

/**
 * @brief  This function must perform a loop incrementing by 1.0 the value of the counter pointed by pCounter
            it must perform this loop nLoops times. 
 * 
 * @param nLoops 
 * @param pCounter 
 */

void incr(unsigned int nLoops, double* pCounter){
    unsigned int i = 0 ;
    while(i<nLoops){
        *pCounter += 1.0;
        i++;
        }
}


/**
 * @brief main function 
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */

int main(int argc, char *argv[])
{

    if (argc < 2)
    {
        std::cerr << "Please enter the value of: <nLoops> " << endl;
        return 1;
    }

    // Parameter Initialization
    timespec initial_t, final_t;
    unsigned int nLoop = stoi(argv[1]);
    double counter = 0.0;

    // Calling the void incr() function
    initial_t = timespec_now();
    incr(nLoop, &counter);
    final_t = timespec_now();

    // Results display
    cout << " The final value of the counter is : " << counter << endl;
    cout << " The time of execution is : " << timespec_to_ms(final_t-initial_t)/1e3 << "Sec" << endl;

    return 0; 
}
