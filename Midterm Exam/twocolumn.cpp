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
        //loop thr and build column using columnCount as a ref for i
        for (int i = columnCount; i <= fileData.size(); i++) {
            //if less than column width
            if ((s.size() + fileData[i].size()) < columnWidth) {
                columnCount = i;
                if(columnCount == fileData.size()) {
                    s.append(fileData[i]);
                    vColumn.push_back(s);
                    return vColumn;
                }
                s.append(fileData[i]).append(" ");

            //if equal to column width
            } else if ((s.size() + fileData[i].size()) == columnWidth) {
                s.append(fileData[i]);
                vColumn.push_back(s);
                s = "";
                columnCount = i;
                countLines++;
                if(countLines == linesPerPage || columnCount == fileData.size()) return vColumn;

            //if greater than column width
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

    int LTCount = 0;
    int RTCount = 0;
    bool flag = true;
    int dataPlace = 0;
    std::string s;
    std::vector <TYPE> strColumn1;
    std::vector <TYPE> strColumn2;

        while(flag) {
            //When even, make left column
            if ((LTCount + RTCount) % 2 == 0) {
                //dataPlace to calc where at in fileData
                std::vector <TYPE> vectorCol1 = createColumn(fileData, linesPerPage, columnWidth,dataPlace);
                strColumn1.insert(strColumn1.end(), vectorCol1.begin(), vectorCol1.end());
                LTCount++;
                //if size doesn't match line count then is uneven column and finished
                if (strColumn1.size() != (linesPerPage * LTCount)) {
                    flag = false;
                    break;
                }
            //When odd, make right column
            } else if ((LTCount + RTCount) % 2 != 0) {
                //dataPlace to calc where at in fileData
                std::vector <TYPE> vectorCol2 = createColumn(fileData, linesPerPage, columnWidth, dataPlace);
                strColumn2.insert(strColumn2.end(), vectorCol2.begin(), vectorCol2.end());
                RTCount++;

                //if size doesn't match line count then is uneven column and finished
                if (strColumn2.size() != (linesPerPage * RTCount)) {
                    flag = false;
                    break;
                }
            }
        }
// printing loop
    std::string spaceBC;
    int count = 0;
    std::ofstream resultFile("resultTest.txt");
    for (int p = 0; p < strColumn1.size(); p++) {
        //counting space between columns
        while((columnWidth - strColumn1[p].size() + spaceBetweenColumns) != spaceBC.size()) {
            spaceBC.append(" ");
        }
        //print to file/screen
        resultFile << strColumn1[p] << spaceBC << strColumn2[p] << "\n";
        std::cout << strColumn1[p] << spaceBC << strColumn2[p] << std::endl;

        //testing column size and spaces
//        std::cout << spaceBC.size() << " col size: " << strColumn1[p].size() <<std::endl;

        spaceBC = "";
        //adding pg break
        if(((p+1) % linesPerPage) == 0){
            std::cout << "\n------------- Pg. " << ((p+1)/linesPerPage) <<" ----------------\n" << std::endl;
            resultFile << "\n------------- Pg. " << ((p+1)/linesPerPage) <<" ----------------\n";
        }

    }
    resultFile.close();

}

//run file method
void runFile(std::string fileName, const int linesPerPage,
             const int columnWidth, const int spaceBetweenColumns)
{
    //open and added to vector fileData
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

    //Arguments from command line
    std::string fileName = argv[1];
    const char* chLinesPerPage = argv[2];
    const char* chColumnWidth = argv[3];
    const char* chSpaceBetweenColumns = argv[4];

    //convert to int
    const int linesPerPage = stoi(chLinesPerPage);
    const int columnWidth = stoi(chColumnWidth);
    const int spaceBetweenColumns = stoi(chSpaceBetweenColumns);

    //run method call
    runFile(fileName, linesPerPage, columnWidth, spaceBetweenColumns);

    //TEST TEXT FILES, for future testing
    //    /Users/erikkell/Programming/CS202/CS202/testfile.txt
    //    /Users/erikkell/Programming/CS202/CS202/ten_page_book.txt
    return 0;
}

