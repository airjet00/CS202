#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char *argv[]){

    std::string ln;
    std::ifstream file ("/Users/erikkell/Programming/CS202/CS202/Labs/Lab4/lab04_Streams.cpp");
    if(file.is_open()){
        int count = 0;
        while(getline(file, ln)){
            std::cout << count+1 << ":  ";
            std::cout << ln << std::endl;
            count++;
        }
        std::cout << "Please enter number of copies to print\n" <<
                        "then space and number line to print: ";
        
        int numPrint, numLine;
        std::cin >> numPrint >> numLine;

        std::cout << "Entered: " << numPrint << " and " << numLine << std::endl;

        file.close();
    }else{
        std::cout << " Not working/opening" << std::endl;
    }

    return 0;
}