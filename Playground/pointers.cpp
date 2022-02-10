#include <cstdlib>
#include <vector>
#include <iostream>
#include <memory>

void foo(const double & a){
    // a = 2.5;
};


int main(int argc, char *argv[]){
    //TODO
    std::shared_ptr<double> sp;
    std::unique_ptr<double> up;
    std::shared_ptr<double> sp2;
    std::unique_ptr<double> up2;
    sp2 = sp;
    //up2 = up; dosen't work
    up2 = std::move(up);
    //call a function
    foo(*sp);

    std::cout << sp << std::endl;
    // std::cout << *sp2 << std::endl; // segmentation fault
    return 0;
}

class Test {
    public:
        // Test();
        // ~Test();
        // Test(const Test &a);
    

    private:
};