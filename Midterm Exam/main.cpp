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
#include <string>
#include <sstream>
#include <iomanip>

using TYPE = std::string;

void loadFile(std::string fileName)
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

    int count = 0;
    for(int i = 0; i < fileData.size(); i++)
    {
//        std::cout << fileData[i].size() << std::endl;
        if((count + fileData[i].size()) < 50){
            std::cout << fileData[i] << " ";
            count = count + fileData[i].size() +1;
        }
        else if((count + fileData[i].size()) == 50)
        {
            std::cout << fileData[i];
            count = count + fileData[i].size();
        }
        else if((count + fileData[i].size()) > 50)
        {
            std::cout << count << "\n";
            count = 0;
            continue;
        }
        else
        {
            break;
        }


    }
    std::cout << count << "\n";
}

//using namespace std;
int main(int argc, char *argv[]){

    std::cout << "Section 1.10.33 of \"de Finibus Bonorum et" << std::endl;

    std::string fileName = "/Users/erikkell/Programming/CS202/CS202/testfile.txt";

    loadFile(fileName);

//    std::vector<std::vector<TYPE> > text;
//
//    std::ifstream fin(fileName);
//    for(std::string line; getline(fin, line);)
//    {
//        std::stringstream ss(line);
//        std::vector<TYPE> row;
//
//        for(TYPE d; ss >> d; ) row.push_back(d);
//        text.push_back(row);
//    }
//
//    std::cout << "Your text:\n";
//    for(auto &row : text)
//    {
//        for(auto &item : row) std::cout << std::setw(5) <<item << ' ' ;
//        std::cout << '\n';
//    }

    return 0;
}