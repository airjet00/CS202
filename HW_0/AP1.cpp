#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;



int main(int argc, char *argv[])
{

    ifstream f("/Users/erikkell/Downloads/Sherlock_Holmes.txt");

    if(f.is_open())
        cout << f.rdbuf() << endl;


    f.close();
    cout << "Hello World" << endl; // for testing

    return 0;
}