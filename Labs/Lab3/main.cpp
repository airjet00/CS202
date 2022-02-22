/************************************************
    Author: Erik Kell         Date: 7 Feb 2022
    Class: CS 202             Title: Lab02 ClassConstDestr

****Purpose****
In this lab, you will get some practice using modern C++
 smart pointers.

****What to Do****
Write a program that uses your class from Lab 2 that
 reports when it is created, copied, and destroyed. In
 this program you should

    1.Create a raw pointer to a dynamically allocated
    object of your class. Is this object ever destroyed?

    2. Create a unique_ptr to an object of your class.
    Note when the object is created, and that it is
    eventually destroyed. This object should be created
    with your "other constructor," which takes a parameter.

    3.Transfer ownership of that object to a different
    unique_ptr. Note that the object itself is not copied.

    4. Demonstrate the calling of a member function of your
    object through the unique_ptr.

    5. Make a shared_ptr to a dynamically allocated object
    of your class.

    6. Make another shared_ptr that points at the same
    object. Note that the object does not get destroyed
    until both shared_ptrs go out of scope.

 Before each step, print a line to the console explaining
 what you're doing, like "Creating raw pointer.", "Creating
 unique_ptr.", "Transferring ownership to new unique_ptr.",
 "Calling a member function.", "Creating shared_ptr.",
 "Creating another shared_ptr to the same object."

Be sure to use make_shared and make_unique, do not call the
constructors for shared_ptr and unique_ptr directly.

****Optional next steps****
N/A

************************************************/
#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;


int main(){
    cout << "test test " << endl;

    return 0;
}