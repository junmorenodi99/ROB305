#ifndef Looper_h_INCLUDED
#define Looper_h_INCLUDED


/**
 * @file Looper.h
 * @author Nicolas Dimate (https://github.com/junmorenodi99)
 * @brief Defines the Looper class
 * @version 0.1
 * @date 2022-03-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <iostream>

/**
 * @brief Defination of Looper class
 * 
 */
class Looper
{
    private: 

        bool doStop;
        double iLoop;

    public: 
        /**
         * @brief Runs a given number of iterations of a loop 
         * 
         * @param nLoops 
         * @return double 
         */
        double runLoop(double nLoops = __DBL_MAX__);

        /**
         * @brief Get the Sample attribute
         * 
         * @return double 
         */
        double getSample();

        /**
         * @brief Stop the looper and return the number of loops executed
         * 
         * @return double 
         */
        double stopLoop();
    
};

#endif


