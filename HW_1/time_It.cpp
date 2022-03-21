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

//class StopWatch{
//    private:
//        std::chrono::time_point<std::chrono::steady_clock> start, end;
//        std::chrono::duration<float> duration;
//    public:
//        StopWatch(){
//            start = std::chrono::high_resolution_clock::now();
//            std::cout << "Test " << std::endl;
//        }
//        void setStart(){
//            //for restarting clock
//            //TODO should overwrite constr start variable?
//             start = std::chrono::system_clock::now();
//        }
//        void setStop(){
//            //End clock
//            end = std::chrono::system_clock::now();
//        }
//        auto getStart(){
//            return this->start;
//        }
//        auto getEnd(){
//            return this->end;
//        }
//        double TimeInSec(){
//            //TODO calculations
//            std::chrono::duration<double> duration = this->end - this->start;
//            return duration;
//        }
//
//
//};

int main(int argc, char *argv[]){
//    using namespace std::literals::chrono_literals;

    auto start = std::chrono::high_resolution_clock::now();

    std::this_thread::sleep_for(std::chrono::seconds(1));

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end - start;
    std::cout << duration.count() << std::endl;



    return 0;
}