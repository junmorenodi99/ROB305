#include <time.h>
#include <iostream>
#include <pthread.h>
#include <vector>
#include <string>

#include "Semaphore/Semaphore.h"
#include "timerLib/timerLib.h"
#include "SemaphoreConsumer/SemaphoreConsumer.h"
#include "SemaphoreProducer/SemaphoreProducer.h"

using namespace std;

int main(int argc, char **argv)
{
    timespec time_begin;
    timespec time_end; 
    Semaphore semaphore;

    if (argc < 4)
    {
        std::cerr << " Please enter the value of: <nProd> <nCons> <nItems>" << endl;
        return 1;
    }
    
    int nProd = stoi(argv[1]);
    int nCons = stoi(argv[2]);
    int nItems = stoi(argv[3]);
    
    unsigned prodQuantity = 0;
    unsigned consQuantity = 0;
    

    time_begin = timespec_now();


    SemaphoreProducer *producerVect[nProd];
    SemaphoreConsumer *consumerVect[nCons];

  // Create producers
  for (int i=0; i<nProd; i++)
  {
    producerVect[i] = new SemaphoreProducer(&semaphore, nItems);
  }
  
  // Create consumers
  for (int i=0; i<nCons; i++)
  {
    consumerVect[i] = new SemaphoreConsumer(&semaphore, (int) nItems*nProd/nCons);
  }

  for (int i = 0; i < nProd; i++)
  {
    producerVect[i] -> start();
    cout << "Producer Thread " << i << " created" << endl;
  }

  for (int i = 0; i < nCons; i++)
  {
    consumerVect[i] -> start();
    cout << "Consumer Thread " << i << " created" << endl;
  }

  for (int i = 0; i < nCons; i++)
  {
    consumerVect[i] -> join();
    consQuantity += consumerVect[i] -> getCounter();
		cout << "Consumer Thread  " << i << " joined" << endl;
  }

  for (int i = 0; i < nCons; i++)
  {
    producerVect[i] -> join();
    prodQuantity += producerVect[i] -> getCounter();
		cout << "Producer Thread  " << i << " joined" << endl;
  }
  
  time_end = timespec_now();

  cout <<"\n"<< endl;
  cout << "Total quantity of produced tokens : " << prodQuantity << endl;
  cout << "Total quantity of consumed tokens : " << consQuantity << endl; 
  cout << "Time needed: " << (timespec_to_ms(time_end - time_begin)/1000) << " seconds" << endl; 

  return 0;
}