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
using std::stoi;

//Method prints the text with x number of char per line
void printFile(std::vector<TYPE> fileData, const int linesPerPage,
               const int columnWidth, const int spaceBetweenColumns) {

    int countcheck = 0;
    int countLines = 0;
    int count = 0;
    std::vector <TYPE> strColumn1;
    std::vector <TYPE> strColumn2;
    for (int i = 0; i < fileData.size(); i++) {

        std::string s;
        //checking char count on each line and printing if 50 or under
        if ((count + fileData[i].size()) < columnWidth) {
            s = fileData[i] + " ";
            strColumn1.push_back(s);
//            std::cout << fileData[i] << " ";
            count = count + fileData[i].size() + 1;
        } else if ((count + fileData[i].size()) == columnWidth) {
//            std::cout << fileData[i];
            strColumn1.push_back(fileData[i]);
            count = count + fileData[i].size();
        } else if ((count + fileData[i].size()) > columnWidth) {
//            std::cout << count << "\n"; //to check count of each line
            strColumn1.push_back("\n");
            count = 0;
            continue;
        } else {
            break;
        }
    }   strColumn1.push_back("\n");
    for (const auto &w : strColumn1) {
        std::cout << w;

    }
}



//run file method
void runFile(std::string fileName, const int linesPerPage,
             const int columnWidth, const int spaceBetweenColumns)
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
    printFile(fileData, linesPerPage, columnWidth, spaceBetweenColumns);
}

int main(int argc, char *argv[]){

    std::string fileName = argv[1];
    const char* chLinesPerPage = argv[2];
    const char* chColumnWidth = argv[3];
    const char* chSpaceBetweenColumns = argv[4];

    const int linesPerPage = stoi(chLinesPerPage);
    const int columnWidth = stoi(chColumnWidth);
    const int spaceBetweenColumns = stoi(chSpaceBetweenColumns);

    //TEST TEXT FILES
    //    std::string fileName = "/Users/erikkell/Programming/CS202/CS202/testfile.txt";
    //    /Users/erikkell/Programming/CS202/CS202/ten_page_book.txt

    runFile(fileName, linesPerPage, columnWidth, spaceBetweenColumns);

    return 0;
}

