/************************************************
    Author: Erik Kell         Date: 22 Feb 2022
    Class: CS 202             Title: HW2 toLower

****Purpose****
function, void to_lower(char* s), that replaces
 all uppercase characters in the Cstyle string s
 with their lowercase equivalents.

****What to Do****
 Do not use any standard library functions

example: Hello, World!
Output:
hello, world!

****Optional next steps****
N/A
************************************************/
#include <iostream>

using std::cout;
using std::endl;

//prints all lower char to screen
void toLower(char* s){

    int i = 0;
    //loop while not end of c-style string
    while(s[i] != 0){

        //looking for capital letter via ASCII
        if(s[i] > 64 && s[i] < 91){
            //if capital let to lower
            s[i] = s[i] + 32;
        }
        i++;
    }
    //lower case string
    cout << s << endl;
}

int main(){

    //user input a string upto 250 char
    char cString[250];
    cout << "Enter a string:  ";
    scanf("%[^\n]%*c", cString); //take input until \n and discard \n
//    std::cin >> cString;

    toLower(cString);

    return 0;
}