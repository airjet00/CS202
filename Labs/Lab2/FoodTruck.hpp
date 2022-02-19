#pragma once

#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>


using std::cout;
using std::endl;

class FoodTruck{
    private:
        int _id;
    public:
        //Default ctor
        FoodTruck()  {cout << "I'm a food truck\n";}
        //copy ctor
        FoodTruck(const FoodTruck & t){cout << "copy truck" << endl;}
        //ctor with parameter
        FoodTruck(int id ){cout << "It's id number is: " << id <<"\n";}
        //dstor
        ~FoodTruck(){cout << "Destroyer\n";}

    //set truck id
    void setId(int id);

    //get truck id
    int getId();
};
