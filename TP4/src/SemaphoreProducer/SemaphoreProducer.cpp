#include "SemaphoreProducer.h"

SemaphoreProducer::SemaphoreProducer(Semaphore *semaphore, unsigned maxNum): Thread(), semaphore(semaphore), counter(0), maxCount(maxNum){};

SemaphoreProducer::~SemaphoreProducer(){};

void SemaphoreProducer::run()
{
  for(unsigned i = 0; i < maxCount; i++)
  {
    semaphore -> give();
    counter++;
  }
}

unsigned SemaphoreProducer::getCounter()
{
  return counter;
}