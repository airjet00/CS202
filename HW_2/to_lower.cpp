/************************************************
    Author: Erik Kell         Date: 22 Feb 2022
    Class: CS 202             Title: HW2 toLower

****Purpose****


****What to Do****


****Optional next steps****
N/A
************************************************/
#include <iostream>

using std::cout;
using std::endl;

void toLower(char* s){

    int i = 0;
    while(s[i] != 0){

        if(s[i] > 64 && s[i] < 91){
            s[i] = s[i] + 32;
            cout << s[i];

        }else{
            cout << s[i];
        }
        i++;
    }
    cout << "\n";
}

int main(){
    char cString[250];
    cout << "Enter a string:  ";
    scanf("%[^\n]%*c", cString); //take input until \n and discard \n
//    std::cin >> cString;

    toLower(cString);

    return 0;
}