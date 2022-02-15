/************************************************
    Author: Erik Kell         Date: 7 Feb 2022
    Class: CS 202             Title: Lab04 Streams
    
****Purpose****
In this lab, you will get some practice using streams 
in C++. 
    
****What to Do****
Write a program that reads and writes from a text file. 
In this program, you should:
    1. Open a text file and display the contents to the 
    console.
    2. Query the user for a number n, and a line of text, 
    to be entered all on one line.
    3. Append n copies of the line of text to the file.

When demonstrating your program you will run it more than 
once, so that we may see that you actually append the text, 
instead of overwriting the old file.

****Optional next steps****
Modify your program so that it counts the number of 
paragraphs, lines, words, and characters inside the file. 
Print the result in columns with headers out to the 
standard output.
     
************************************************/

#include <cstdlib>
#include <fstream>
#include <iostream>

using std::ofstream;
using std::ifstream;
using std::fstream;
using std::string;
using std::cout;
using std::endl;

string fileName = "/Users/erikkell/Programming/CS202/CS202/Labs/Lab4/test.txt";


int main(int argc, char *argv[]){

    // display file with number lines
    string ln;    
    ifstream inFile(fileName);
    if(inFile.is_open()){
        cout << fileName << " is open.\n";
    }

    int count=0;
    while (true)
    {
        string ln;
        count++;
        cout << count << ".  ";
        getline(inFile, ln);
        if(!inFile){                        //TODO figure out this line
            if(inFile.eof()){
                cout << "Completed reading file.\n";
                            
            }else{
                cout << "Error.\n";
        }
        break;
        }
        cout << ln << "\n";
        

    }
    



// #include <cstdlib>
// #include <fstream>
// #include <iostream>
// #include <string>

// //TODO: add function for opening file
// //TODO: add function for displaying file
// //TODO: add function for desplaying selected info  

// int main(int argc, char *argv[]){

//     //display file with number lines
//     std::string ln;
//     std::ifstream file; 
//     file.open("/Users/erikkell/Programming/CS202/CS202/Labs/Lab4/test.txt");

//     int count = 0;
//     if(file.is_open()){
//         while(getline(file, ln)){
//             std::cout << count+1 << ":  ";  //creates number line
//             std::cout << ln << std::endl;
//             count++;
//         }
//         file.close();
//     }else{
//         std::cout << " Not working/opening" << std::endl;
//     }

//     //get number of copies and number line
//     std::cout << "Please enter number of copies to print\n" <<
//                     "then space and number line to print: ";
//     int numPrint, numLine;
//     std::cin >> numPrint >> numLine;
//     std::cout << "Entered: " << numPrint << " and " << numLine << std::endl;
//     //find line and print n number of times 
//     count = 0;
    
//     //TODO: Different way to get to begining of file again?
//     file.open("/Users/erikkell/Programming/CS202/CS202/Labs/Lab4/test.txt");

//     if(file.is_open()){
//         while(getline(file, ln)){
//             count++;
//             //When count equals requested display line
//             if(count == numLine){
//                 for(int i =0; i < numPrint; i++){
//                     std::cout << ln << std::endl;
//                 }
//             }
//         }

//         file.close();
//     }else{
//         std::cout << " Not working/opening" << std::endl;
//     }

    return 0;
}