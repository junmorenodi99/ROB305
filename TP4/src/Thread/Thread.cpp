#include "Thread.h"

Thread::Thread(){};	

Thread::~Thread(){};

void Thread::start()
{
    if(!isActive){	
        startTime = timespec_now();
        PosixThread::start(call_run, (void*) this);
        stopTime = timespec_now();

        isStarted = true;
    }
}        


void Thread::sleep_ms(double delay_ms)
{
  timespec_wait(timespec_from_ms(delay_ms));
};

double Thread::startTime_ms()
{
    return timespec_to_ms(startTime);
};

double Thread::stopTime_ms()
{
    return timespec_to_ms(stopTime);
};

double Thread::execTime_ms()
{
    return timespec_to_ms(stopTime)-timespec_to_ms(startTime);
};
 
void* Thread::call_run(void* v_thread)
{
    Thread* thread = (Thread*) v_thread;
    thread->run();
    return (void*) thread;
};