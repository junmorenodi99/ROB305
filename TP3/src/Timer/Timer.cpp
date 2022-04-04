/**
 * @file Timer.cpp
 * @author Nicolas Dimate (https://github.com/junmorenodi99)
 * @brief Implementation of the methods defined in 'Timer.h'
 * @version 0.1
 * @date 2022-03-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Timer.h"
#include "../timerLib/timerLib.h"

Timer::Timer(){

    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = call_callback;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGRTMIN, &sa, nullptr);

    struct sigevent sev;
    sev.sigev_notify = SIGEV_SIGNAL;
    sev.sigev_signo =  SIGRTMIN;
    sev.sigev_value.sival_ptr = (void*) this;

    timer_create(CLOCK_REALTIME, &sev, &tid);
};

Timer::~Timer(){
	timer_delete(tid);
};

void Timer::start(double duration_ms){
	
	itimerspec its;

    its.it_value = timespec_from_ms(duration_ms);
    its.it_interval.tv_sec = 1; // 1 hz
    its.it_interval.tv_nsec = 0;
    timer_settime(tid, 0, &its, NULL);
};	


void Timer::stop(){
	itimerspec its;
	its.it_value.tv_sec = 0;
	its.it_value.tv_nsec = 0;
	timer_settime(tid, 0, &its, NULL);
	
};	


void Timer::call_callback(int ,siginfo_t* si, void*){
	Timer& ref = *((Timer*) si->si_value.sival_ptr);
	ref.callback();
};
