/************************************************
    Author: Erik Kell         Date: 26 March 2022
    Class: CS 202             Title: Midterm Exam

****Purpose****
Midterm exam. Code nneds to be clear, concise,
and readable. Create a pdf report containing
source code and first 10 pages of output for a
book for EACH problem.

****What to Do****

    1. (Version of HW3: Additional Program 1)
        Write a program that reads in a book
        (Project Gutenberg or similar) and
        outputs the text based on given characters
        wrapping value.

        Usage: prettyprint 768.txt 50
        Should print the book with a max of 50 char
        per line.

    2.  Modify program from #1 to print the text in
        two column format. The command-line arguments
        are the input file name, the number of lines
        per page, the width of the columns, and the
        number of blank spaces between the columns.

        Usage: twocolumn 768.txt 40 38 4
        Should print 40 lines per page, with each
        column a max of 38 char wide and 4 blank
        spaces between the columns. Output
        "-----------" to show each page break.

****Optional next steps****
N/A

************************************************/

#include <iostream>
#include <vector>
#include <fstream>


using TYPE = std::string;

//Method prints the text with x number of char per line
void printFile(std::vector<TYPE> fileData, const int charPerLine){
    int count = 0;
    for(int i = 0; i < fileData.size(); i++)
    {
        //checking char count on each line and printing if 50 or under
        if((count + fileData[i].size()) < charPerLine){
            std::cout << fileData[i] << " ";
            count = count + fileData[i].size() +1;
        }
        else if((count + fileData[i].size()) == charPerLine)
        {
            std::cout << fileData[i];
            count = count + fileData[i].size();
        }
        else if((count + fileData[i].size()) > charPerLine)
        {
//            std::cout << count << "\n"; //to check count of each line
            std::cout << "\n";
            count = 0;
            continue;
        }
        else
        {
            break;
        }
    }
    std::cout << "\n";
}

//open file method
void loadFile(std::string fileName, const int charPerLine)
{
    std::vector<TYPE>(fileData);
    std::ifstream file;
    file.open(fileName);
    if(!file.is_open()) return;

    std::string word;
    while (file >> word)
    {
        fileData.push_back(word);
    }
    //call to print file
    printFile(fileData, charPerLine);
}

int main(int argc, char *argv[]){

    std::string fileName = argv[1];
    const char* chNum = argv[2];
    const int charPerLine = std::stoi(chNum);

    //TEST TEXT FILES
    //    std::string fileName = "/Users/erikkell/Programming/CS202/CS202/testfile.txt";
    //    /Users/erikkell/Programming/CS202/CS202/ten_page_book.txt

    loadFile(fileName, charPerLine);

    return 0;
}