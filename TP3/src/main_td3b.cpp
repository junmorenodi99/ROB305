/**
 * @file main_td3a.cpp
 * @author Nicolas Dimate (https://github.com/junmorenodi99)
 * @brief Main function for testing the CounterDown class created
 * @version 0.1
 * @date 2022-03-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */



#include <iostream>
#include "CounterDown/CounterDown.h"

using namespace std;

/**
 * @brief The main function implementing the test for the CounterDown Class, making a countdown for a created counter 
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char **argv){

 if (argc < 2)
    {
        std::cerr << " Please enter the value of: <nLoops> " << endl;
        return 1;
    }

    int nLoops = stoi(argv[1]);
    
    // Creation of counter
    CounterDown counterDown(nLoops);
    
    // Start Counting
    counterDown.start(1000.0);
    while (counterDown.get_counter() != 0)
    {}
    
    return 0;

}

