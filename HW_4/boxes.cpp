/************************************************
    Author: Erik Kell         Date: 12 Apr 2022
    Class: CS 202             Title: HW4

****Purpose****
Your job is to write a set of C++ classes to
represent boxes, which can be displayed on the
screen. Boxes have a width and a height, and can
be printed to the screen (or a file). They can
be hollow, filled, or checkered.

A 3 by 4 filled box looks like this:
xxx
xxx
xxx
xxx

while a 10 by 5 hollow box looks like this:
xxxxxxxxxx
x        x
x        x
x        x
xxxxxxxxxx

And a 4x4 checkered box looks like this:
x x
 x x
x x
 x x

****What to Do****
You should have an abstract base class called Box, and three concrete derived
classes: FilledBox, HollowBox, and CheckeredBox.
Your Box class should provide the following functions:
    1. A constructor where the client can specify the width and height.
    2. getWidth() and getHeight() accessor functions.
    3. setWidth() and setHeight() mutator functions.
    4. a pure virtual void print(ostream &os) function.
    5. a pure virtual string type() function.
    6. an operator<<(ostream &os, const Box &b) function which draws the box to
        the ostream. It should print a newline at the end of every line, including the last. (This
        is a global function, not a member function, and it can be a two liner, simply
        call b.print(os); then return os;)

Each derived class should contain the following
    1. A default constructor. By default, boxes are 1 by 1. (Hint: what happens if you don't
        write this?)
    2. A constructor where the user can specify the width and height.
    3. The type() function, which returns the string "Filled", "Hollow", or "Checkered" as
        appropriate.
    4. The print(ostream &) function which draws the box to
        the ostream. The ostream should be cout by default. It should print a newline at the
        end of every line, including the last.

You should also provide a factory function:
unique_ptr<Box> boxFactory(char c, int w, int h), which takes a character 'f',
'h', or 'c', and a width and a height. boxFactory() should return a unique pointer to
a FilledBox, HollowBox, or CheckeredBox (of the proper width and height) depending on which
character was passed.

There is a test program attached to this assignment on Blackboard which you should use to
test your code.

****Optional next steps****
N/A

************************************************/


#include <cstdlib>
#include <iostream>

//Print to screen method
void printBoxScreen(int width, int height){

    std::cout << width << " and " << height << std::endl;

}


int main(){

    printBoxScreen(5, 6);

    return 0;
}