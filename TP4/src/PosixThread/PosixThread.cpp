#include "PosixThread.h"

PosixThread::PosixThread()
{
  this -> posixId = 0; 
  //Diapo 21
  pthread_attr_t posixAttr;
  pthread_attr_init(&posixAttr);
  pthread_attr_setinheritsched(&posixAttr, PTHREAD_EXPLICIT_SCHED);
  pthread_attr_setschedpolicy(&posixAttr, SCHED_OTHER);

  sched_param schedParams;
  schedParams.sched_priority = 0;
  pthread_attr_setschedparam(&posixAttr, &schedParams);
};	

PosixThread::PosixThread(pthread_t posixId_v): posixId(posixId_v)
{
  pthread_attr_init(&posixAttr);
  pthread_attr_setinheritsched(&posixAttr, PTHREAD_EXPLICIT_SCHED);

  sched_param schedParam;
  int policy= 0;

  int param = pthread_getschedparam(this -> posixId, &policy, &schedParam);

  if(param != 0)
  {
    throw PosixThread::Exception();
  }
  else
  {
    this -> isActive = true;
    pthread_attr_setschedpolicy(&posixAttr, policy);
    pthread_attr_setschedparam(&posixAttr, &schedParam); 
  }
};

  PosixThread::~PosixThread()
  {
    pthread_attr_destroy(&posixAttr);
  };

	void PosixThread::start(void*(*threadFunc)(void*), void* threadArg)
  {
    pthread_create(&posixId, &posixAttr, threadFunc, threadArg);
    isActive =true;
  };

	void PosixThread::join()
  {
    pthread_join(posixId, NULL);
  };

 
bool PosixThread::getScheduling(int* p_schedPolicy, int* p_priority)
{
  struct sched_param schedParam;
  *p_priority = schedParam.sched_priority ;

  if(isActive)
  {
    pthread_getschedparam(posixId, p_schedPolicy, &schedParam);
  }
  else
  {
    pthread_attr_getschedpolicy(&posixAttr, p_schedPolicy);
    pthread_attr_getschedparam(&posixAttr, &schedParam);   
  }
  return isActive;
}
  
bool PosixThread::setScheduling(int schedPolicy, int priority)
{
  // Diapo 22
  struct sched_param schedParam;
  schedParam.sched_priority = priority;

  if(isActive)
  {
    pthread_setschedparam(posixId, schedPolicy, &schedParam);
  }
  else
  {
    pthread_attr_setschedpolicy(&posixAttr, schedPolicy);
    pthread_attr_setschedparam(&posixAttr, &schedParam);
  }
  return isActive;
}


const char *PosixThread::Exception::TheException() const noexcept
{
  return "The Thread doesn't exist!\n";
}

