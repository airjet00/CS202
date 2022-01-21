#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;



int main(int argc, char *argv[])
{
    char words[500];
    ifstream f("/Users/erikkell/Downloads/Sherlock_Holmes.txt");

    if(f.is_open())
        f.getline(words, 500);  
    
    cout << words << endl;

    f.close();
    
    // cout << "Hello World" << endl; // for testing

    return 0;
}