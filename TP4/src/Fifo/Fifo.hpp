#ifndef Fifo_hpp_INCLUDED
#define Fifo_hpp_INCLUDED

#include <queue>
#include "../Mutex/Mutex.h"
#include <exception>
#include "../Lock/Lock.h"

template <class T>
class Fifo
{
  public:
    class EmptyException : std::exception
    {
      public:
        const char *TheException() const noexcept;
    };

    void push(T element);
    T pop();
    T pop(double timeout_ms);

  private:
    std::queue<T> elements; 
    Mutex mutex; 

};


template <class T>
void Fifo<T>::push(T element)
{
  Mutex::Lock lock(mutex);
  elements.push(element);
  lock.notify();
  lock.~Lock();
}

template <class T>
T Fifo<T>::pop()
{
  T element = elements.front();
  
  Mutex::Lock lock(mutex);
  // blocked if fifo is empty
  if (elements.empty()) 
	{
		lock.wait();
	}
	else
	{
		elements.pop();
	}	
	lock.notify();
  lock.~Lock();
  return element;
}

template <class T>
T Fifo<T>::pop(double timeout_ms)
{
  T element = elements.front();
  
  Mutex::Lock lock(mutex);
  // blocked if fifo is empty
  if (elements.empty())  
	{
		throw Fifo<T>::EmptyException();
		lock.wait(timeout_ms);
		lock.notify();
    lock.~Lock();
  }    
	else
	{
		elements.pop();
		lock.notify();
    lock.~Lock();
	}
  return element;
}


template <typename T> const char *Fifo<T>::EmptyException::TheException() const noexcept
{
  return "Empty exception \n";
}

#endif