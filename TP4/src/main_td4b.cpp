#include <iostream>
#include <pthread.h>
#include <vector>

#include "timerLib/timerLib.h"
#include "Lock/Lock.h"
#include "CounterThread/CounterThread.h"
#include "CounterMutex/CounterMutex.h"




using namespace std;
 
int main(int argc, char **argv)
{
    // To measure the execution time
   	timespec time_begin;
    timespec time_end; 
    Mutex mutex;

    if (argc < 4)
    {
        std::cerr << " Please enter the value of: <nLoops> <nTasks> <schedPolicy>" << endl;
        return 1;
    }
    
    unsigned int nLoops = stoi(argv[1]);
    int nTasks = stoi(argv[2]);
    string scheduling = argv[3];

    if(scheduling == "SCHED_RR")
    {
        cout << "scheduling set as SCHED_RR" << endl;
    }
    else if( scheduling =="SCHED_FIFO" )
    {
        cout << "scheduling set as SCHED_FIFO" << endl;
    }
    else
    {
        // Default SCHED_OTHER
        cout << "scheduling set as SCHED_OTHER" << endl;
    }

    time_begin = timespec_now();

    Data threadData = {nLoops, 0.0, SCHED_OTHER};
    CounterMutex* incrementThread[nTasks];

    for (int i=0;i<nTasks;i++)
    {
        incrementThread[i] = new CounterMutex(&threadData, mutex);
    }

    for (int i=0; i<nTasks; ++i) 
    {
        incrementThread[i]->start();
        cout<< "Thread "<< i << "created" << endl;
    }
    
    for (int i=0; i<nTasks; ++i){ 
        incrementThread[i]->join();
        cout << "Thread " << i << " joined" << endl;
    }

    time_end = timespec_now();

    cout << "Final counter value: " << threadData.pCounter << endl;    
    cout << "Execution time: " << (timespec_to_ms(time_end - time_begin)/1000) << " seconds" << endl; 
    
return 0; 
}