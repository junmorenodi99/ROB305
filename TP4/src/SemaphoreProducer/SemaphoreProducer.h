#ifndef SemaphoreProducer_h_INCLUDED
#define SemaphoreProducer_h_INCLUDED

#include <pthread.h>
#include "../Semaphore/Semaphore.h"
#include "../Thread/Thread.h"

class SemaphoreProducer : public Thread
{
	private:
		Semaphore *semaphore;
		unsigned counter;	
		unsigned maxCount;
			
	public:
		SemaphoreProducer(Semaphore *semaphore, unsigned maxNum);
		~SemaphoreProducer();
		void run();
		unsigned getCounter();
  
};

#endif