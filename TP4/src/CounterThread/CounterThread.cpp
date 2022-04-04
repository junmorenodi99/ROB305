#include "CounterThread.h"



CounterThread::CounterThread(Data* data): data(data){
    int schedPriority = 0;  // Put a number between 1 and 99  
    if(data->schedPolicy == SCHED_OTHER)
        schedPriority = 0;
    
    setScheduling(data->schedPolicy, schedPriority);
};
// CounterThread::~CounterThread(){};

void CounterThread::run(){
    unsigned int i = 0;
    while (i < data->nLoops)
    {
        data -> pCounter += 1.0;
        i++;
    }  
};
