#ifndef FifoProducer_h_INCLUDED
#define FifoProducer_h_INCLUDED

#include <iostream>
#include <time.h>
#include "../Thread/Thread.h"
#include "../Fifo/Fifo.hpp"

class FifoProducer :public Thread
{
private:
    Fifo<int> *fifo;
    unsigned counter = 0;
    unsigned maxCount;

public:
    FifoProducer(Fifo<int> *fifo, unsigned int numItem);
    ~FifoProducer();
    void run();
    unsigned getCount();
};

FifoProducer::FifoProducer(Fifo<int> *fifo, unsigned int maxNum): Thread(), fifo(fifo), counter(0), maxCount(maxNum){};
FifoProducer::~FifoProducer(){};

void FifoProducer::run()
{
    unsigned i = 0;
    while (i<maxCount)
    {
        fifo->push(i);
        counter++;
        i++;
    }
};

unsigned FifoProducer::getCount()
{
    return counter;
};


#endif