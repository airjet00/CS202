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
        //copy ctor              **Need _id=t._id to copy id**
        FoodTruck(const FoodTruck & t){_id = t._id; cout << "copy truck" << endl;}
        //ctor with parameter
        FoodTruck(int id ){
            this->_id = id;
            cout << "Truck id number is: " << id << endl;
        }
        //dstor
        ~FoodTruck(){cout << "Destroyer\n";}

    //set truck id
    void setId(int id);

    //get truck id
    int getId();
};
