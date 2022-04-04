/**
 * @file timerLib.cpp
 * @author Nicolas Dimate (https://github.com/junmorenodi99)
 * @brief Implementing methods for 'timespec' operation from TimerLib.h 
 * @version 0.1
 * @date 2022-03-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "timerLib.h"

double timespec_to_ms(const timespec& time_ts){
    double time_ms = time_ts.tv_sec*1e3 + time_ts.tv_nsec/1e6;
    return time_ms;
}

timespec timespec_from_ms(double time_ms){
    timespec time_ts;
    time_ts.tv_sec = (int)time_ms/1000;
    time_ts.tv_nsec = (time_ms - (time_ts.tv_sec*1e3))*1e6;;
    return time_ts;
    }

timespec timespec_now(){
    struct timespec time_ts;
    clock_gettime(CLOCK_REALTIME, &time_ts);
    return time_ts;
}

timespec timespec_negate(const timespec& time_ts){
    timespec time_ts_negate = time_ts;
    if (time_ts.tv_nsec < 0 ){
    time_ts_negate.tv_sec = time_ts.tv_sec-1;  
    time_ts_negate.tv_nsec = time_ts.tv_nsec+1e9; 
    }
    return time_ts_negate;
}

timespec timespec_add(const timespec& time1_ts, const timespec& time2_ts){
    timespec time_ts_total;

    time_ts_total.tv_sec = time1_ts.tv_sec + time2_ts.tv_sec;
    time_ts_total.tv_nsec = time1_ts.tv_nsec + time2_ts.tv_nsec;
    
    if (time_ts_total.tv_nsec>1e9){
        time_ts_total.tv_sec = time_ts_total.tv_sec+1;
        time_ts_total.tv_nsec = time_ts_total.tv_nsec-1e9; 
    }

    return time_ts_total;
}




timespec timespec_subtract(const timespec& time1_ts, const timespec& time2_ts){
    timespec time_ts_total;

    time_ts_total.tv_sec = time1_ts.tv_sec - time2_ts.tv_sec;
    time_ts_total.tv_nsec = time1_ts.tv_nsec - time2_ts.tv_nsec;
    time_ts_total = timespec_negate(time_ts_total);
    
    return time_ts_total;
}

timespec timespec_wait(const timespec& delay_ts){
    timespec debut, final, duration, delay;
    delay = timespec_negate(delay_ts);
    clock_gettime(CLOCK_REALTIME, &debut);
    nanosleep(&delay, NULL);
    clock_gettime(CLOCK_REALTIME, &final);

    duration.tv_sec = final.tv_sec - debut.tv_sec;
    duration.tv_nsec = final.tv_nsec - debut.tv_nsec;
  
    duration = timespec_negate(duration);
    return duration;
}

// Declaration of Operators


timespec  operator- (const timespec& time_ts){
    timespec neg;
    neg.tv_sec = -time_ts.tv_sec;
    neg.tv_nsec = -time_ts.tv_nsec;
    return timespec_negate(neg);
}

timespec  operator+ (const timespec& time1_ts, const timespec& time2_ts){
    timespec res;
    res = timespec_add(timespec_negate(time1_ts),timespec_negate(time2_ts));
    return  res; 
} 

timespec  operator- (const timespec& time1_ts, const timespec& time2_ts){
    timespec res;
    res = timespec_subtract(timespec_negate(time1_ts),timespec_negate(time2_ts));
    return  res;
}


timespec& operator+= (timespec& time_ts, const timespec& delay_ts){
    time_ts = timespec_negate(time_ts) + timespec_negate(delay_ts);
    if (time_ts.tv_nsec >= 1e9)
  {
    time_ts.tv_sec += 1;
    time_ts.tv_nsec -= 1e9;
  }
    return time_ts ;
}

timespec& operator-= (timespec& time_ts, const timespec& delay_ts){
    time_ts = timespec_negate(time_ts) - timespec_negate(delay_ts);
    return  time_ts;
}

bool operator== (const timespec& time1_ts, const timespec& time2_ts){
    double time1_ms =  timespec_to_ms(time1_ts);
    double time2_ms =  timespec_to_ms(time2_ts);
    if (time1_ms == time2_ms){
        return true;
    }else{
        return false;
    }
}


bool operator!= (const timespec& time1_ts, const timespec& time2_ts){
    double time1_ms =  timespec_to_ms(time1_ts);
    double time2_ms =  timespec_to_ms(time2_ts);
    if (time1_ms != time2_ms){
        return true;
    }else{
        return false;
    }
}

bool operator< (const timespec& time1_ts, const timespec& time2_ts){
    double time1_ms =  timespec_to_ms(time1_ts);
    double time2_ms =  timespec_to_ms(time2_ts);
    if (time1_ms < time2_ms){
        return true;
    }else{
        return false;
    }

}
bool operator> (const timespec& time1_ts, const timespec& time2_ts){
    double time1_ms =  timespec_to_ms(time1_ts);
    double time2_ms =  timespec_to_ms(time2_ts);
    if (time1_ms > time2_ms){
        return true;
    }else{
        return false;
    }

}

