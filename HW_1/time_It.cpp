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

class StopWatch{
    private:
        std::chrono::time_point<std::chrono::steady_clock> start, end;
        std::chrono::duration<float> duration;
    public:
        StopWatch(){
            start = std::chrono::high_resolution_clock::now();
            std::cout << "Test " << std::endl; 
        }
        void setStart(){
            //for restarting clock
            //TODO should overwrite constr start variable? 
             start = std::chrono::system_clock::now();
        }
        void setStop(){
            //End clock
            end = std::chrono::system_clock::now();
        }
        auto getStart(){
            return this->start;
        }
        auto getEnd(){
            return this->end;
        }
        double TimeInSec(){
            //TODO calculations 
            std::chrono::duration<double> duration = this->end - this->start;
            return duration;
        }


};

int main(int argc, char *argv[]){
    // auto start = std::chrono::high_resolution_clock::now();

    StopWatch test1;

    std::cout << "Result is: ";

    // auto end = std::chrono::high_resolution_clock::now();

    // std::chrono::duration<double> duration = end - start;    

    std::cout << test1.TimeInSec() << "s " << std::endl;

    return 0;
}