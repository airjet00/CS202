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

int main(){

    FoodTruck ft;
    ft.setId(1);
    return 0;
}


/***** Class notes *****
class MyClass{
    public:
        //Default constructor
        MyClass(){cout << "Default constructor"<< endl;}
        //copy constructor
        MyClass(const MyClass & m){ cout << "copy constructor" << endl;}
        ///constructor with an int parameter
        MyClass(int x){ cout << "int constructor" << endl;}
        //Destructor
        ~MyClass() {cout << "Destructor" <<endl;} 
    private:


};

void fcn_by_value(MyClass x1){
    cout << "start of fcn_by_value" << endl;
    // MyClass z(10);
}

void fcn_by_reference(MyClass & x1){
    cout << "start of fcn_by_reference" << endl;
    // MyClass z(10);
}

void fcn_by_const_reference(const MyClass & x1){
    cout << "start of fcn_by_const_reference" << endl;
    // MyClass z(10);
}

MyClass fcn_return_by_value(){
    MyClass b; // local variable
    // ... do stuff
    return b;
}


int main(){

    cout << "start of main()" << endl;

    MyClass a; // obj of MyClass
    // MyClass b = a;
    // fcn_by_value(a);
    // fcn_by_reference(a);
    // fcn_by_const_reference(a);
    // fcn_return_by_value();
    // vector<MyClass> v(5);
    // v[2] =a;

    

    // a = fcn_return_by_value();

    cout << "end of main()" << endl;

    return 0;
}
*/