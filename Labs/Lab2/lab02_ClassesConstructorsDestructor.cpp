#include <cstdlib>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;


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