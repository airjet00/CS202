/************************************************
    Author: Erik Kell         Date: 7 Feb 2022
    Class: CS 202             Title: Lab02 ClassConstDestr
    
****Purpose****
In this lab, you will review how to properly write a class 
with various constructors and a destructor. 
    
****What to Do****
Write a C++ class that implements each of the following 
functions. These must provide output so that you can see 
when objects of your class are created, copied, or destroyed.
    1. Default constructor
    2. Copy constructor
    3. at least one other constructor
    4. Destructor

Be sure to properly create your class in separate .hpp and 
.cpp files. Write another .cpp file which uses objects of 
your class in the following ways.
    1. Create a local variable of an object of your class
    2. Create a local variable that is a copy of another 
    object of your class
    3. Pass an object by value
    4. Pass an object by reference
    5. Pass an object by reference to const
    6. Return an object by value
    7. Create a vector of 5 objects

If you have time, continue to work on your class by giving 
it a data member, and member functions that modify and return 
that member. Don't forget that your copy constructor will 
now need to copy that member!

Be sure to pay special attention to how you pass parameters 
and return values, and whether your member functions should 
be const or not. (You should ALWAYS be paying special 
attention to this!)

****Optional next steps****
N/A
     
************************************************/
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

#include "FoodTruck.hpp"

using std::cout;
using std::endl;
using std::vector;

int main(){

    //Create a vector of foodtrucks and iterate
    vector<FoodTruck> vFoodTrucks;
    FoodTruck ft1(2), ft2(3), ft3(4), ft4(5), ft5(6);
    vFoodTrucks.push_back(ft1);
    vFoodTrucks.push_back(ft2);
    vFoodTrucks.push_back(ft3);
    vFoodTrucks.push_back(ft4);
    vFoodTrucks.push_back(ft5);

    for (auto t: vFoodTrucks) {

        cout << t.getId() << endl;
    }


//    FoodTruck ft;
//    ft.setId(1);
//    cout << vFoodTrucks[1].getId() << endl;
//    FoodTruck copyFT = ft;
//    cout << ft.getId() << endl;
//    cout << copyFT.getId() << endl;
//    FoodTruck iFt(2);
    return 0;
}