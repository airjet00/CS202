/************************************************
    Author: Erik Kell         Date: 22 Feb 2022
    Class: CS 202             Title: HW2 Linked List

****Purpose****
Use linked list class and in main.cpp, use Catch.hpp
 to test the class. Spend time learning how linked
 list works.

****What to Do****

    1. Struct called Value
    2. Create linked list
    3. Catch.hpp to test:
        -Queue: FIFO
        -Stack: LIFO
        -Insert and Find
        -Print list

****Optional next steps****
N/A
************************************************/
#include <cstdlib>
#include <iostream>
#include <list>

using std::cout;
using std::endl;

//struct {
//
//};

void toLower(char* s){
//    char result[] {""};
    int i = 0;
    while(s[i] != 0){
        if(s[i] > 64 && s[i] < 91){
            s[i] = s[i] + 32;
            cout << s[i];
//            result += s[i];
        }else{

            cout << s[i];
//            result += s[i];
        }
        i++;
//        cout << result << endl;
    }
    cout << "\n";
}

int main(){
    char cString[] { "Hello, World!"};
    toLower(cString);

    return 0;
}
