#ifndef CounterMutex_h_INCLUDED
#define CounterMutex_h_INCLUDED

#include <iostream>
#include <time.h> 
#include "../CounterThread/CounterThread.h" 
#include "../Lock/Lock.h"

class CounterMutex : public Thread
{
private:
    Data* data;
    Mutex& mutex;
public:
    CounterMutex(Data* data, Mutex& mutex);
    void run();
};

#endif