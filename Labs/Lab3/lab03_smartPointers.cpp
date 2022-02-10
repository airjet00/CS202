#include <iostream>
#include <memory>

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
        //memeber func
        void whatever() {cout << "whatever" << endl;}
    private:


};


int main(){

    cout << "start of main()" << endl;

    MyClass a;
    a.whatever();

#if 0
    // raw pointers - no new code
    MyClass *ptr = new MyClass; //MEMORY LEAK without delete;
    //.... do something
    delete ptr;  // MUST DO OR MEMORY LEAK!
#endif

    auto sPtr = std::make_shared<MyClass>();
    auto sPtr2 = sPtr;
    auto sPtr3 = sPtr;

    auto uPtr = std::make_unique<MyClass>(10);
    // auto uPtr2 = uPtr; //Error
    auto uPtr2 = std::move(uPtr);

    uPtr2->whatever();

    cout << "end of main()" << endl;

    return 0;
}