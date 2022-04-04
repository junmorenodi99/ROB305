#ifndef PosixThread_h_INCLUDED
#define PosixThread_h_INCLUDED


#include <iostream>
#include <pthread.h>
#include <exception>
#include "../timerLib/timerLib.h"



class PosixThread
{
    public:
    //Public Atributes
    class Exception: std::exception
    {
        public:         
            const char* TheException() const noexcept;
    };

        PosixThread();	
        PosixThread(pthread_t posixId);
        ~PosixThread();

        void start(void* (*threadFunc) (void*), void* threadArg);	
        void join();
        bool setScheduling(int schedPolicy, int priority);
        bool getScheduling(int* p_schedPolicy, int* p_priority);

    private:
        //Private Atributes
        pthread_t posixId;
        pthread_attr_t posixAttr;

    protected:
    //Protected Atributes
        bool isActive;
};





#endif