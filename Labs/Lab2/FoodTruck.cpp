

#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include "FoodTruck.hpp"


using std::cout;
using std::endl;

void FoodTruck::setId(int id){
    _id =id;
}

int FoodTruck::getId(){
    return _id;
}

FoodTruck passByRef( FoodTruck& ft) {
    cout << ft.getId() << endl;
    ft.setId(42);
    cout << ft.getId() << endl;

    return ft;
}

FoodTruck passByRetByValue(FoodTruck ft){
    cout << "pass by and return by value\n";
    return ft;
}

FoodTruck passConstRef(const FoodTruck& ft){
    cout << "pass by reference to const\n";
    return ft;
}

