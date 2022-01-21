#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{

    //if cmd line variable valid
    //check ftoc or ctof
    //call function

    string str1 = "ftoc";
    if (str1.compare(argv[1]) == 0)
        cout << argv[1] << endl;

    string fstr = argv[2];
    int f = stoi(fstr); //
    cout << f - 2 << endl;

    cout << "Hello" << endl;

    return 0;
}

// Convert from Fahrenheit to Celsius
//double cpp_ftoc(const char* str)

// Convert from Celsius to Fahrenheit
//double c_ctof(const char* str)