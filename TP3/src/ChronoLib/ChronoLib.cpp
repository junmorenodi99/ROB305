/**
 * @file ChronoLib.h
 * @author Nicolas Dimate (https://github.com/junmorenodi99)
 * @brief Implementation of the methods defined in 'Chrono.h'
 * @version 0.1
 * @date 2022-03-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "ChronoLib.h"

Chrono::Chrono(){
    startTime_ = timespec_now();
    stopTime_ = timespec_from_ms(0.0);
};

void Chrono::stop(){
    stopTime_ = timespec_now();
};

void Chrono::restart(){
    startTime_ = timespec_now();
    stopTime_ = timespec_from_ms(0.0);	 
};

bool Chrono::isActive(){ 
   return stopTime() == 0;
};

double Chrono::startTime(){
    return timespec_to_ms(startTime_);
}

double Chrono::stopTime(){
    return timespec_to_ms(stopTime_);
};

double Chrono::lap(){
    if(Chrono::isActive()){
        return timespec_to_ms(timespec_now())-startTime();
    }else{
        return stopTime()-startTime();
    }
}


