#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>



int main(int argc, char *argv[]){

    //display file with number lines
    std::string ln;
    std::ifstream file; 
    file.open("/Users/erikkell/Programming/CS202/CS202/Labs/Lab4/lab04_Streams.cpp");

    int count = 0;
    if(file.is_open()){
        while(getline(file, ln)){
            std::cout << count+1 << ":  ";
            std::cout << ln << std::endl;
            count++;
        }
        file.close();
    }else{
        std::cout << " Not working/opening" << std::endl;
    }
        //get number of copies and number line
        std::cout << "Please enter number of copies to print\n" <<
                        "then space and number line to print: ";
        
        int numPrint, numLine;
        std::cin >> numPrint >> numLine;
        std::cout << "Entered: " << numPrint << " and " << numLine << std::endl;

        // std::cout << ln << std::endl;

        //find line and print n number of times 
        count = 0;
    // bool flag = file.eof();
    // std::cout << flag << std::endl;
file.open("/Users/erikkell/Programming/CS202/CS202/Labs/Lab4/lab04_Streams.cpp");

    if(file.is_open()){
        while(getline(file, ln)){
            // std::cout << "Test Test" << std::endl;
            count++;
            if(count == numLine){
                for(int i =0; i < numPrint; i++){
                    std::cout << ln << std::endl;
                }
            }
        }

        file.close();
    }else{
        std::cout << " Not working/opening" << std::endl;
    }

    return 0;
}