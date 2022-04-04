#include "SemaphoreConsumer.h"

SemaphoreConsumer::SemaphoreConsumer(Semaphore *semaphore, unsigned maxNum) : Thread(), semaphore(semaphore),counter(0), maxCount(maxNum){};

SemaphoreConsumer::~SemaphoreConsumer(){};

void SemaphoreConsumer::run()
{
  while(semaphore->take(100))
  {
    counter++;
  }
}

unsigned SemaphoreConsumer::getCounter()
{
  return counter;
}