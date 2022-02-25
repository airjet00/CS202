//
// Created by Erik Kell on 2/23/22.
// Test cases for HW_2 project
//
#define CATCH_CONFIG_MAIN //tells catch to provide a main()
#include "bank_account.cpp"
#include "catch.hpp"

//testing default ctor sets account number to 1
//testing default ctor starting balance
TEST_CASE("Testing Account Number"){
    AccountHolder holder = AccountHolder();
    REQUIRE(holder.accountNumber == 1);
    REQUIRE(holder.balance == 0.0);
}


//testing init deposit ctor
TEST_CASE("Testing Account Init Deposit"){
    double deposit = 500.00;
    AccountHolder holder = AccountHolder(deposit);
    REQUIRE(holder.accountNumber == 1);
    REQUIRE(holder.balance == deposit);
}
//testing deposit into established accounts
TEST_CASE("Testing Established Account Deposit"){
    AccountHolder holder = AccountHolder(100);
    REQUIRE(holder.balance == 100);
    holder.deposit(100);
    REQUIRE(holder.balance == 200);
    REQUIRE(holder.monthlyDeposit.back() == 100);
}

////testing withdrawal
TEST_CASE("Testing account withdrawal"){
    AccountHolder holder = AccountHolder(500);
    REQUIRE(holder.balance == 500);
    holder.withdraw(100);
//    REQUIRE(holder.withdraw(100) == "$100.00 has been withdrawn");
    REQUIRE(holder.balance == 400);
    REQUIRE(holder.monthlyWithdraw.back() == 100.00);
}

//testing link list methods

