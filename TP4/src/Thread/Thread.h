#ifndef Thread_h_INCLUDED
#define Thread_h_INCLUDED


#include <time.h>
#include "../PosixThread/PosixThread.h"
#include "../timerLib/timerLib.h" 


class Thread: public PosixThread
{
    public:

        Thread();	
        ~Thread();
        void start();
        void sleep_ms(double delay_ms);

        double startTime_ms();
        double stopTime_ms();
        double execTime_ms();

    private: 

        static void* call_run(void* v_thread);
        timespec startTime;
        timespec stopTime;
        bool isStarted = false;

    protected:

        virtual void run() = 0;
};


#endif