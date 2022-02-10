#include <cstdlib>
#include <iostream>

// using namespace std; //use or not to use?? 
        //NO can do something like std::cout

// using std::cout;

//creating a function
int timesTwoNum(int num){
    return num *2;
}

int main(int argc, char *argv[]){
    //TODO flow of control structures:

    //if/else
    int ifNum = 1;
    if(ifNum == 5) std::cout << "if number is " << ifNum << std::endl; // {} with more than one line
    else std::cout << "if number is: " << ifNum << std::endl;

    //switch
    char state[] = "switch number is: ";
    switch(ifNum){
        //TODO finish refactoring char[]
        case 1: std::cout << state << ifNum << std::endl;
        break;

        case 2: std::cout << "switch number is: " << ifNum << std::endl;
        break;
    
        case 3: std::cout << "switch number is: " << ifNum << std::endl;
        break;

        case 4: std::cout << "switch number is: " << ifNum << std::endl;
        break;

        case 5: std::cout << "switch number is: " << ifNum << std::endl;
        break;

        default: std::cout << "this isn't working right" << std::endl;
    
    };

    //calling a function
    int timesResult = timesTwoNum(ifNum);
    std::cout << "times two result is: " << timesResult << std::endl;


    //While loop
    bool flag = true;
    while(flag){
        if(flag){
            std::cout << flag << std::endl; //print 1
            flag = false;
            std::cout << flag << std::endl; //print 0
        }
    }

    //Do While
    int doFlag = 3;
    do{

        std::cout << "I'm looping still" << std::endl;
        doFlag--;
        if(doFlag == 0) std::cout << "all done" << std::endl;
    }while(doFlag != 0);

    //For loop (normal)
    int count = 10;
    for (int i = 0; i < count; i++)
    {
        if(i == count -1){
            std::cout << "The last loop interation: " << count << std::endl;
        }
    }
    
    //For loop (range based)
    int countArr[] = {1,2,3,4,5};
    int result; 
    for (int c : countArr)
    {
        result += c;
    }
    std::cout << "The sum of the count array is: " << result << std::endl;    

}

