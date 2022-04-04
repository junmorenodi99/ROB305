#ifndef Monitor_h_INCLUDED
#define Monitor_h_INCLUDED


#include <exception>
#include "../Mutex/Mutex.h" 

class Mutex::Monitor
{
    public:
        class TimeoutException : std::exception
        {
            public:         
                const char* TheException() const noexcept;
        };

        void wait();
        bool wait(double timeout_ms);
        void notify();
        void notifyAll() ;
        Mutex& mutex; 
        
    protected: 
        Monitor(Mutex& m);
};


#endif