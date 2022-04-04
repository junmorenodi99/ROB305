#ifndef SemaphoreConsumer_h_INCLUDED
#define SemaphoreConsumer_h_INCLUDED

#include <pthread.h>
#include "../Semaphore/Semaphore.h"
#include "../Thread/Thread.h"

class SemaphoreConsumer : public Thread
{
private:
	Semaphore *semaphore;
	unsigned counter;	
	unsigned maxCount;    
	
public:
	SemaphoreConsumer(Semaphore *semaphore, unsigned  maxNum);
	~SemaphoreConsumer();
	void run();
	unsigned getCounter();

};

#endif