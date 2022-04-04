#ifndef Timer_h_INCLUDED
#define Timer_h_INCLUDED

/**
 * @file Timer.h
 * @author Nicolas Dimate (https://github.com/junmorenodi99)
 * @brief Defines the class 'Timer'
 * @version 0.1
 * @date 2022-03-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <iostream>
#include <time.h> 
#include <signal.h>

/**
 * @brief Class implementing a Posix Timer
 * 
 */
class Timer
{
    public:

        /**
         * @brief Construct a new Timer object
         * 
         */
        Timer();

        /**
         * @brief Destroy the Timer object
         * 
         */
        virtual ~Timer();

        /**
         * @brief Start the Posix timer 
         * 
         * @param duration_ms 
         */
        void start(double duration_ms);

        /**
         * @brief  Stop the Posix Timer
         * 
         */
        void stop();

    protected:

        timer_t tid;

        /**
        * @brief Virtual Callback
        * 
        */
        virtual void callback() = 0 ;

    private: 

        /**
        * @brief Call of the handler function
        * 
        * @param si 
        */
        static void call_callback(int ,siginfo_t* si, void*);

};

#endif