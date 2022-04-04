#include "CounterMutex.h"

CounterMutex::CounterMutex(Data* data, Mutex& m): data(data), mutex(m)
{
    // Put a number between 1 and 99  
    int schedPriority = 0;  
    if(data->schedPolicy == SCHED_OTHER)
        schedPriority = 0;
    
    setScheduling(data->schedPolicy, schedPriority);
};

// CounterMutex::~CounterMutex(){};

void CounterMutex::run()
{
    unsigned int i = 0;
    while (i < data->nLoops)
    {   
        Mutex::Lock lock(mutex);
        data -> pCounter += 1.0;
        lock.~Lock();
        i++;
    }  
};



