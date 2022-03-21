/************************************************
    Author: Erik Kell         Date: 4 Feb 2022
    Class: CS 202             Title: HW1 Time It
    
    About:
    I : Starts clock / stops clock which will
    record the time for event. Report time in 
    seconds and milliseconds as double. Use 
    chrono header from STL to get time from 
    system.

    II: read five Gutenberg Project books 
    with std::string. Time with three different
    kind of containers finding a random string, 
    how long to sort. 
************************************************/

#include <cstdlib>
#include <iostream>
#include <chrono>
#include <thread>

//TODO using std chrono and clean up code

class StopWatch{
private:
    //Variable for starting/ending timer
    std::chrono::time_point<std::chrono::high_resolution_clock> _start, _end, _restart;
    //Variable for calculating duration
    std::chrono::duration<double> _duration, _intervalOperation;
public:
    //Ctor sets _start and print notification that obj created and associated timer
    StopWatch(){
        _start = std::chrono::high_resolution_clock::now();
        std::cout << "Time started" << std::endl;
    }

    //Dtor sets _end and calculated total life-time of obj in milliseconds
    ~StopWatch(){
        _end = std::chrono::high_resolution_clock::now();
        _duration = _end - _start;

        double millisec = _duration.count() * 1000.0; //.count returns number of ticks
        std::cout << "Total object life-time is: " << millisec <<"ms" <<std::endl;
    }

    //Sets the _restart value for an operation
    void start(){
        _restart = std::chrono::high_resolution_clock::now();
    }
    //Sets the end time for an operation
    void stop(){
        _end = std::chrono::high_resolution_clock::now();
    }
    //Prints time for operation in seconds
    void timeSec(){
        _intervalOperation = _end - _restart;
        double seconds = _intervalOperation.count();
        std::cout << "Time to complete operation: " << seconds << "seconds" << std::endl;
    }
    //Prints time for operation in milliseconds
    void timeMilSec(){
        _intervalOperation = _end - _restart;
        double milliseconds = _intervalOperation.count() * 1000.0;
        std::cout << "Time to complete operation: " << milliseconds << "milliseconds" << std::endl;
    }
};

int main(int argc, char *argv[]){
    
    StopWatch st;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    st.start();
    std::this_thread::sleep_for(std::chrono::seconds(2));
    st.stop();
    st.timeSec();
    st.timeMilSec();




    return 0;
}