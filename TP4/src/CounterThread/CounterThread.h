#ifndef CounterThread_h_INCLUDED
#define CounterThread_h_INCLUDED


#include <iostream>
#include <time.h>
#include "../Thread/Thread.h" 


struct Data 
{
  volatile unsigned int nLoops;
  volatile double pCounter;
  int schedPolicy;
};

class CounterThread:public Thread
{
  private:
    Data* data;

  public:
    CounterThread(Data* data);
    void run();
};


#endif