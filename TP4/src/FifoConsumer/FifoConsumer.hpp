#ifndef FifoConsumer_h_INCLUDED
#define FifoConsumer_h_INCLUDED

#include <iostream>
#include <time.h>
#include "../Thread/Thread.h"
#include "../Fifo/Fifo.hpp"

class FifoConsumer :public Thread
{
    private:
        Fifo<int> *fifo;
        unsigned counter = 0;

    public:
        FifoConsumer(Fifo<int> *fifo);
        ~FifoConsumer();
        void run();
        unsigned getCount();
};

FifoConsumer::FifoConsumer(Fifo<int> *fifo): Thread(), fifo(fifo), counter(0){};

FifoConsumer::~FifoConsumer(){};

void FifoConsumer::run()
{
    while(isActive)
    {
        try
        {
            fifo->pop(1000);
            counter++;
        }
        catch(const Fifo<int>::EmptyException& e)
        {
            isActive = false;
        }
    }
}

unsigned FifoConsumer::getCount()
{
    return counter;
};


#endif