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


using TYPE = std::string;
using std::stoi;

//Method builds and returns columns as vector
std::vector<TYPE> createColumn(std::vector<TYPE> fileData, const int linesPerPage,
                               const int columnWidth, int& columnCount) {
    std::vector <TYPE> vColumn;
    std::string s;
    int count = 0;
    int countLines = 0;

        for (int i = columnCount; i <= fileData.size(); i++) {

            if ((s.size() + fileData[i].size()) < columnWidth) {
                s.append(fileData[i]).append(" ");
                columnCount = i;
                if(columnCount == fileData.size()) {
                    vColumn.push_back(s);
                    return vColumn;
                }

            } else if ((s.size() + fileData[i].size()) == columnWidth) { //so we have no space at end of line
                s.append(fileData[i]);
                vColumn.push_back(s);
                s = "";
                columnCount = i;
                countLines++;
                if(countLines == linesPerPage || columnCount == fileData.size()) return vColumn;

            } else if ((s.size() + fileData[i].size()) > columnWidth) {
                vColumn.push_back(s);
                columnCount = i;
                i--;
                countLines++;
                s = "";
                if(countLines == linesPerPage) return vColumn;
            }
        }
    return vColumn;
}

//Method prints the text with x number of char per line
void printFile(std::vector<TYPE> fileData, const int linesPerPage,
               const int columnWidth, const int spaceBetweenColumns) {

    std::string spaceBC;
    for (int i = 0; i < spaceBetweenColumns; i++) spaceBC.append(" ");

    int LTCount = 0;
    int RTCount = 0;

    int countcheck = 0;
    int countLines = 0;
    int count = 0;
    bool flag = true;
    std::vector <TYPE> strColumn1;
    std::vector <TYPE> strColumn2;
    int dataPlace = 0;
            std::string s;

        //could do ((countLines / linesPerPage) + 2) % 2 ==  0 or 1
        while(flag) {
            if ((LTCount + RTCount) % 2 == 0) {
                std::vector <TYPE> vectorCol1 = createColumn(fileData, linesPerPage, columnWidth,dataPlace);
                strColumn1.insert(strColumn1.end(), vectorCol1.begin(), vectorCol1.end());
                LTCount++;
//                strColumn1.push_back("--------------");  don't do this now, after column build, it and insert
                if (strColumn1.size() != (linesPerPage * LTCount)) {
                    std::cout << dataPlace << " and1 " << strColumn1.size() << std::endl;
                    flag = false;
                    break;
                }
                std::cout << "Col 1:" <<strColumn1.size() << std::endl;
                std::cout << "data count:" << dataPlace << std::endl;
            } else if ((LTCount + RTCount) % 2 != 0) {
                //TODO add new line to end of line  //LT to calc where at in fileData
                std::vector <TYPE> vectorCol2 = createColumn(fileData, linesPerPage, columnWidth, dataPlace);
                strColumn2.insert(strColumn2.end(), vectorCol2.begin(), vectorCol2.end());
                RTCount++;

                if (strColumn2.size() != (linesPerPage * RTCount)) {
                    std::cout << dataPlace << " and2 " << strColumn2.size() << " andsize " << fileData.size()<<std::endl;
                    flag = false;
                std::cout <<"Col 2: " <<strColumn2.size() << std::endl;
                    break;
                }
            }
        }


// Testing loop
        for (int p = 0; p < 42; p++) {
            std::cout << strColumn1[p] << spaceBC << strColumn2[p] << std::endl;


        }
        std::cout << strColumn2.size() <<std::endl;
//    for (int x = 0; x < 39; ++x) {
//            std::cout << strColumn2[x] << std::endl;
//
//    }
//        std::cout << strColumn1.size() << std::endl;
//        std::cout << strColumn2.size() << std::endl;
//        std::cout << "_________________" << std::endl;
//        std::string st;
//        std::string str;
//        st.append(strColumn1[0]).append(spaceBC);
//        str.append(strColumn2[1]).append(spaceBC);
//        std::cout << st;
//        std::cout << str;
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

