/**
 * @file main_td1a.cpp
 * @author Nicolas Dimate (https://github.com/junmorenodi99)
 * @brief Main function for the creation of a incremental counter using pthread and Mutex
 * @version 0.1
 * @date 2022-03-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <mutex>
#include <time.h>
#include "timerLib/timerLib.h"
#include <string>
using namespace std;


/**
 * @brief Data structure for thread use with Mutex
 * 
 */
struct Data 
{
  int nLoops;
  double pCounter;
  bool isProtected;
  pthread_mutex_t mtx;
};


/**
 * @brief This function must perform a loop incrementing by 1.0 the value of the counter pointed by pCounter
 * it must perform this loop nLoops times. 
 * 
 * @param nLoops 
 * @param pCounter 
 */
void incr(int nLoops, double* pCounter)
{
  for(int i = 0; i < nLoops; ++i)
  {
    *pCounter += 1.0;
  }
}


void* call_incr(void* vThreadData)
{
	Data* pThreadData = (Data*) vThreadData;

  if (pThreadData->isProtected)
  {
    pthread_mutex_lock(&pThreadData->mtx);
    incr(pThreadData->nLoops, (double*) &pThreadData->pCounter);
    pthread_mutex_unlock(&pThreadData->mtx);
  } 
  else
  {
    incr(pThreadData->nLoops, (double*) &pThreadData->pCounter);
  }

	return vThreadData;
}

/**
 * @brief Implementation of the main function, using the created functions.
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char* argv[])
{
  // To measure the execution time
  timespec time_begin; 
  timespec time_end;

  // Exception handling
  if (argc < 3)
  {
    std::cerr << " Please enter the value of: <nLoops> <nTasks> [isProtected ?]" << endl;
    return 1;
  }

  int nLoops = stoi(argv[1]);
  int nTasks = stoi(argv[2]);
  string protedArg = argv[3];
  bool isMutexLock;

  // Determination of protected argument

  if (protedArg == "yes")
  {
    cout << "Status 'protected'" << endl;
    isMutexLock = true;
  }
  else 
  {
    cout << "Status 'unprotected'" << endl;
    isMutexLock = false;
  }

  // Initialization of Mutex
  pthread_mutex_t mutex;
  Data threadData = {nLoops, 0.0, isMutexLock, mutex};
  
  if (isMutexLock) pthread_mutex_init(&threadData.mtx, NULL);

  time_begin = timespec_now(); 

	pthread_t incrementThread[nTasks];

  // Creation and joining of Threads

	for(int i = 0; i<nTasks; i++)
	{
		pthread_create(&incrementThread[i], NULL, call_incr, (void*) &threadData);
    cout << "Thread " << i << " created" << endl;
	}
	
	for(int i = 0; i<nTasks; i++)
	{
		pthread_join(incrementThread[i], NULL); 
    cout << "Thread " << i << " joined" << endl; 
	}

  if (isMutexLock) pthread_mutex_destroy(&threadData.mtx);

  time_end = timespec_now();

  // Visualization of results
  cout << "Final counter value: " << threadData.pCounter << endl;    
  cout << "Execution time: " << (timespec_to_ms(time_end - time_begin)/1000) << " seconds" << endl; 
  
  return 0;
}
