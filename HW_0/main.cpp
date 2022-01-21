#include <cstdlib>
#include <iostream>

using namespace std;

double cpp_ftoc(const char* str);
double c_ctof(const char* str);

int main(int argc, char *argv[])
{

    //if cmd line variable valid
    //check ftoc or ctof
    //call function

    string str = argv[1];
    if (str.compare("ftoc") == 0)
        cout << cpp_ftoc(argv[2]) << endl;
    if (str.compare("ctof") == 0)
        cout << c_ctof(argv[2]) << endl;
    
    
    // string fstr = argv[2];
    // double f = stod(fstr); 
    // cout << f - 2 << endl;

    cout << "Hello" << endl;

    return 0;
}

// Convert from Fahrenheit to Celsius
double cpp_ftoc(const char* str){
    double result = 0.0;
    
    double f = stod(str);
    result = (f - 32.0) * (5.0/9.0);

    return result;
}

// Convert from Celsius to Fahrenheit
double c_ctof(const char* str){
    double result = 0.0;

    double c = stod(str);
    result = (c * (9.0/5.0)) + 32;
    
    return result;
}