#ifndef Mutex_h_INCLUDED
#define Mutex_h_INCLUDED



#include <pthread.h>
#include <time.h>
#include "../timerLib/timerLib.h"


class Mutex
{
    public:
        class Lock;
        class Monitor;

        Mutex();
        ~Mutex();

    private:
        pthread_mutex_t posixId;
        pthread_cond_t posixCondId;

        void lock();
        bool lock(double timeout_ms);
        void unlock();
};

#endif