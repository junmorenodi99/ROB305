/**
 * @file main_td1c.cpp
 * @author Nicolas Dimate (https://github.com/junmorenodi99)
 * @brief Implements the calib() function that aims to estimate the coefficients 
 * of an affine function relating the number of loops to the time spent.
 * @version 0.1
 * @date 2022-03-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <time.h>
#include <climits>
#include <signal.h>

#include "timerLib/timerLib.h"

using namespace std;

/**
 * @brief Declaration of the structure containing the parameters of the linear estimation function 
 * 
 */
struct coef
{
    double a;
    double b;
};

/**
 * @brief Function that performs an increment of 1 by a counter associated 
 * to the dotted variable ' pCounter' a number of times 'nLoop'.  
 *
 * @param nLoops 
 * @param pCounter 
 * @param pStop 
 * @return unsigned int 
 */
unsigned int incr(unsigned int nLoops, volatile double* pCounter, volatile bool* pStop)
{
    unsigned int iLoop=0;
    for(iLoop=0 ; iLoop < nLoops ; ++iLoop)
    {
        if (*pStop)
            break;
        *pCounter += 1.0;
    }
    return iLoop;
}

/**
 * @brief Function that increments the counter 
 * 
 * @param si 
 */
void myHandler(int, siginfo_t* si, void*)
{
    *((bool*)si->si_value.sival_ptr) = true;
    std::cout << "'stop' is set to true" <<  std::endl;
}

/**
 * @brief POSIX timer implementation for the measurement of nLoops 
 * 
 * @param sec 
 * @return double 
 */
double setIncrement(time_t sec)
{
    volatile bool stop = false;
    unsigned int nLoops = UINT_MAX;
    volatile double counter = 0.0;

    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = myHandler;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGRTMIN, &sa, nullptr);

    struct sigevent sev;
    sev.sigev_notify = SIGEV_SIGNAL;
    sev.sigev_signo = SIGRTMIN;
    sev.sigev_value.sival_ptr = (void*) &stop;

    timer_t tid;
    timer_create(CLOCK_REALTIME, &sev, &tid);
    itimerspec its;
    its.it_value.tv_sec = sec;
    its.it_value.tv_nsec = 0;
    its.it_interval.tv_sec = 0;
    its.it_interval.tv_nsec = 0; 
    timer_settime(tid, 0, &its, nullptr);

    unsigned int iLoop = incr(nLoops, &counter, &stop);

    cout << "Counter value for " << sec << " seconds : " << counter << endl; 

    timer_delete(tid);
	
	return (double) iLoop;
}


/**
 * @brief Function that sets the values of a and b by measuring 
 * the iLoop value for 4 seconds and for 6 seconds.
 * 
 * @return coef 
 */
coef calib()
{
    coef params;
    std::cout << "Calibration working" << std::endl;
    double iLoop_4sec = setIncrement((time_t) 4);
    double iLoop_6sec = setIncrement((time_t) 6);

    /*!< Estimating the coefficients */
    params.a = (iLoop_6sec - iLoop_4sec)/(6 - 4);
    params.b = (iLoop_6sec - params.a*6);

    return params;
}

/**
 * @brief Implementation of the main function, using the created functions.
 * 
 * @return int 
 */
int main()
{	
	
    timespec time_begin, time_end;

    coef params = calib();

    cout << "Calculated parameters: a = " << params.a << " and b = " << params.b << endl;
	int timeVar = 9;

    cout << "Checking the parameters for a " <<  timeVar  << " (s) timer: " << endl;
	
    time_begin = timespec_now();
    double coefCal = setIncrement((time_t) timeVar);
    time_end = timespec_now();

    cout << "Time needed : " << (timespec_to_ms((const timespec) ((time_end - time_begin)))/1000) << "seconds" << endl; 
    cout << "iLoop directed obtained = " << coefCal << endl; 

    double coefCalFunction = params.a*timeVar + params.b;
    cout << "iLoop directed by the function= " << coefCalFunction << endl; 
    cout << "Accuracy: " << (1-(abs(coefCal - coefCalFunction) /coefCal))*100 << "%" << endl;

    return 0;
}