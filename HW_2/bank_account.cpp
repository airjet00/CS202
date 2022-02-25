//
// Created by Erik Kell on 2/24/22.
//

#include <cstdlib>
#include <iostream>
#include <list>
#include <string>
#include <iomanip>

using std::cout;

struct AccountHolder {

    //TODO accountNum generator
    int accountNumber = 0;

    std::list<double> monthlyDeposit;
    std::list<double> monthlyWithdraw;

    double balance;

    //default sets account number and balance to 0.0
    AccountHolder(){
        balance = 0.0;
        accountNumber++;
    }

    //ctor sets account number and balance to deposit amt
    AccountHolder(double deposit){
        accountNumber++;
        balance = deposit;
        monthlyDeposit.push_back(deposit);
    }

    ~AccountHolder(){cout << "Destroyer\n";}; //destructor

    void deposit(double deposit){
        balance += deposit;
        monthlyDeposit.push_back(deposit);
    }

    void withdraw(double amt){
//        std::wstring str = L"$" + std::to_wstring(amt) + L" has been withdrawn";



        balance -= amt;
        monthlyWithdraw.push_back(amt);
//        std::cout << std::setprecision(2) << std::fixed;
//        double dAmt = amt;
////        std::cout << typeid(amt).name() << std::endl;
//        std::string sAmt = std::to_string(dAmt);
//        std::cout << typeid(dAmt).name() << std::endl;
//        std::wcout << sAmt << std::endl;
//        std::string str = "$"+ sAmt + " has been withdrawn";
        printf("$%.2f has been withdrawn", amt);
    }
};
