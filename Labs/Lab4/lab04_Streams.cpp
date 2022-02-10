#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char *argv[]){

    std::string ln;
    std::ifstream file ("/Users/erikkell/Programming/CS202/CS202/Labs/Lab4/lab04_Streams.cpp");
    if(file.is_open()){
        while(getline(file, ln)){
            std::cout << ln << std::endl;
        }
        file.close();
    }else{
        std::cout << " Not working/opening" << std::endl;
    }

    return 0;
}