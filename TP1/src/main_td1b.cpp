/**
 * @file main_td1b.cpp
 * @author Nicolas Dimate (https://github.com/junmorenodi99)
 * @brief Main Function for using signal.h and the timer POSIX for implementation a timer of 2Hz that increments a counter  
 * @version 0.1
 * @date 2022-03-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <time.h> 
#include <signal.h>
using namespace std;

/**
 * @brief function that increments the counter 
 * 
 * @param si 
 */
void myHandler(int, siginfo_t* si, void*)
{
    volatile int& count_ref = *((int*) si->si_value.sival_ptr);
    std::cout<<"My Counter :" << count_ref << std::endl;
    count_ref += 1;

}

/**
 * @brief main for the implementation of a POSIX timer with a frequency of 2 Hz that counts up to 15 
 * 
 * @return int 
 */
int main(){

    volatile int counter = 0;
        
    // define the sigaction 
    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = myHandler;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGRTMIN, &sa, nullptr);

  	// define the sigevent
    struct sigevent sev;
    sev.sigev_notify = SIGEV_SIGNAL;
    sev.sigev_signo =  SIGRTMIN;
    sev.sigev_value.sival_ptr = (void*) &counter;

    timer_t tid;
    timer_create(CLOCK_REALTIME, &sev, &tid);
    itimerspec its;

    cout<<"Waiting 2 seconds... \n" << endl;
	
    // launch timer
    its.it_value.tv_sec = 2;
    its.it_value.tv_nsec = 0;
    // Setting Frequecy to 2 Hz
    its.it_interval.tv_sec = 0;
    its.it_interval.tv_nsec = 5e8;  

    timer_settime(tid, 0, &its, nullptr );

    while (counter < 15)
    {
        continue; 
    }

	// destroy the timer
    timer_delete(tid);

    return 0; 
}







