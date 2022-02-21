

#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include "FoodTruck.hpp"


using std::cout;
using std::endl;

//set Id in FoodTruck class
void FoodTruck::setId(int id){
    _id =id;
}

//get Id in FoodTruck class
int FoodTruck::getId(){
    return _id;
}

//pass by reference (outside foodtruck)
//changes id to 42
FoodTruck passByRef( FoodTruck& ft) {
    cout << ft.getId() << endl;
    ft.setId(42);
    cout << ft.getId() << endl;

    return ft;
}

//pass/return by value (outside foodtruck)
FoodTruck passByRetByValue(FoodTruck ft){
    cout << "pass by and return by value\n";
    return ft;
}

//pass by const reference (outside foodtruck)
FoodTruck passConstRef(const FoodTruck& ft){
    cout << "pass by reference to const\n";
    return ft;
}

