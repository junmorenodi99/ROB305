#include <iostream>
#include <time.h>
#include <string>
#include <pthread.h>
#include <vector>

#include "PosixThread/PosixThread.h"
#include "Thread/Thread.h"
#include "timerLib/timerLib.h"
#include "CounterThread/CounterThread.h"


using namespace std;
 
int main(int argc, char **argv)
{
    // To measure the execution time
   	timespec time_begin;
    timespec time_end; 

    if (argc < 4)
    {
        std::cerr << " Please enter the value of: <nLoops> <nTasks> <schedPolicy>" << endl;
        return 1;
    }

    int schedPolicy;
    unsigned int nLoops = stoi(argv[1]);
    int nTasks = stoi(argv[2]);
    string scheduling = argv[3];

    if(scheduling == "SCHED_RR")
    {
        schedPolicy = 2;
        cout << "scheduling set as SCHED_RR" << endl;
    }
    else if( scheduling =="SCHED_FIFO" )
    {
        schedPolicy = 1;
        cout << "scheduling set as SCHED_FIFO" << endl;
    }
    else
    {
        // Default SCHED_OTHER
        schedPolicy = 0;
        cout << "scheduling set as SCHED_OTHER" << endl;
    }

    struct sched_param schedParam;
    schedParam.sched_priority = sched_get_priority_max(schedPolicy);
    pthread_setschedparam(pthread_self(), schedPolicy, &schedParam);

    Data threadData = {nLoops, 0.0, SCHED_OTHER};
    time_begin = timespec_now();
    CounterThread* incrementThread[nTasks];

    for (int i=0;i<nTasks;i++)
    {
        incrementThread[i] = new CounterThread(&threadData);
        cout<< "Thread "<< i << "created" << endl;
    }

    for (int i=0; i<nTasks; ++i) 
    {
        incrementThread[i]->start();
    }

    for (int i=0; i<nTasks; ++i)
    { 
        incrementThread[i]->join();
        cout << "Thread " << i << " joined" << endl;
    };

    time_end = timespec_now();

    cout << "Final counter value: " << threadData.pCounter << endl;    
    cout << "Execution time: " << (timespec_to_ms(time_end - time_begin)/1000) << " seconds" << endl; 
    
    return 0;

}
