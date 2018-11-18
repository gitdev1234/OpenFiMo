/**
* OpenFiMoTest.cpp
* Purpose: implements unit-tests for the OpenFinanceMonitor-class
*
* @author inc-ffh
* @version 1.0
*/

// !!!! TEST_CASE IN COMBINITION WITH REQUIRE IS LIKE A LOOP STRUCTURE !!!!
// !!!! THE TEST_CASE IS EXECUTED FOR EVERY SECTION !!!!

#include "catch.hpp"
#include "OpenFinanceMonitor.h"
#include "Types.h"

using namespace  std;

TEST_CASE("Test adding amount owners, transactions and calculation of transaction") {

    OpenFinanceMonitor ofm;
    ofm.addMoneyGiver("ABC GmbH",0);
    ofm.addMoneyGiver("CDF AG",0);
    ofm.addYou("Me",0);
    ofm.addMoneyReceiver("Insurance 1",0);
    ofm.addMoneyReceiver("Apartment owner",0);
    ofm.addPiggyBank("Emergency Fund",0);

    REQUIRE(ofm.getAmoutOwnerByName("ABC GmbH"       ).getName() == "ABC GmbH");
    REQUIRE(ofm.getAmoutOwnerByName("CDF AG"         ).getName() == "CDF AG");
    REQUIRE(ofm.getAmoutOwnerByName("Me"             ).getName() == "Me");
    REQUIRE(ofm.getAmoutOwnerByName("Insurance 1"    ).getName() == "Insurance 1");
    REQUIRE(ofm.getAmoutOwnerByName("Apartment owner").getName() == "Apartment owner");
    REQUIRE(ofm.getAmoutOwnerByName("Emergency Fund" ).getName() == "Emergency Fund");

    REQUIRE(ofm.getAmoutOwnerByName("ABC GmbH"       ).getBalance() == 0);
    REQUIRE(ofm.getAmoutOwnerByName("CDF AG"         ).getBalance() == 0);
    REQUIRE(ofm.getAmoutOwnerByName("Me"             ).getBalance() == 0);
    REQUIRE(ofm.getAmoutOwnerByName("Insurance 1"    ).getBalance() == 0);
    REQUIRE(ofm.getAmoutOwnerByName("Apartment owner").getBalance() == 0);
    REQUIRE(ofm.getAmoutOwnerByName("Emergency Fund" ).getBalance() == 0);

    REQUIRE(ofm.getAmoutOwnerByName("ABC GmbH"       ).getAmountOwnerType() == AmountOwnerType::moneyGiver);
    REQUIRE(ofm.getAmoutOwnerByName("CDF AG"         ).getAmountOwnerType() == AmountOwnerType::moneyGiver);
    REQUIRE(ofm.getAmoutOwnerByName("Me"             ).getAmountOwnerType() == AmountOwnerType::you);
    REQUIRE(ofm.getAmoutOwnerByName("Insurance 1"    ).getAmountOwnerType() == AmountOwnerType::moneyReceiver);
    REQUIRE(ofm.getAmoutOwnerByName("Apartment owner").getAmountOwnerType() == AmountOwnerType::moneyReceiver);
    REQUIRE(ofm.getAmoutOwnerByName("Emergency Fund" ).getAmountOwnerType() == AmountOwnerType::piggyBank);

    ofm.addIncomingTransaction("Paycheck",ofm.getAmoutOwnerByName("ABC GmbH"),1000);
    ofm.addIncomingTransaction("Monthly payment",ofm.getAmoutOwnerByName("CDF AG"),200);
    ofm.addOutgoingExpenseTransaction("Insurance payment",ofm.getAmoutOwnerByName("Insurance 1"),150);
    ofm.addOutgoingExpenseTransaction("Aparment rent",ofm.getAmoutOwnerByName("Apartment owner"),300);
    ofm.addOutgoingSavingsTransaction("Emergency savings",ofm.getAmoutOwnerByName("Emergency Fund"),15);

    REQUIRE(ofm.getTransactionByName("Paycheck"         ).getName() == "Paycheck");
    REQUIRE(ofm.getTransactionByName("Monthly payment"  ).getName() == "Monthly payment");
    REQUIRE(ofm.getTransactionByName("Insurance payment").getName() == "Insurance payment");
    REQUIRE(ofm.getTransactionByName("Aparment rent"    ).getName() == "Aparment rent");
    REQUIRE(ofm.getTransactionByName("Emergency savings").getName() == "Emergency savings");

    REQUIRE(ofm.getTransactionByName("Paycheck"         ).getTransactionType() == TransactionType::incoming);
    REQUIRE(ofm.getTransactionByName("Monthly payment"  ).getTransactionType() == TransactionType::incoming);
    REQUIRE(ofm.getTransactionByName("Insurance payment").getTransactionType() == TransactionType::outgoingExpense);
    REQUIRE(ofm.getTransactionByName("Aparment rent"    ).getTransactionType() == TransactionType::outgoingExpense);
    REQUIRE(ofm.getTransactionByName("Emergency savings").getTransactionType() == TransactionType::outgoingSavings);

    REQUIRE(ofm.getTransactionByName("Paycheck"         ).getSender()   == &(ofm.getAmoutOwnerByName("ABC GmbH")));
    REQUIRE(ofm.getTransactionByName("Paycheck"         ).getReceiver() == &(ofm.getAmoutOwnerByName("Me")));
    REQUIRE(ofm.getTransactionByName("Monthly payment"  ).getSender()   == &(ofm.getAmoutOwnerByName("CDF AG")));
    REQUIRE(ofm.getTransactionByName("Monthly payment"  ).getReceiver() == &(ofm.getAmoutOwnerByName("Me")));
    REQUIRE(ofm.getTransactionByName("Insurance payment").getSender()   == &(ofm.getAmoutOwnerByName("Me")));
    REQUIRE(ofm.getTransactionByName("Insurance payment").getReceiver() == &(ofm.getAmoutOwnerByName("Insurance 1")));
    REQUIRE(ofm.getTransactionByName("Aparment rent"    ).getSender()   == &(ofm.getAmoutOwnerByName("Me")));
    REQUIRE(ofm.getTransactionByName("Aparment rent"    ).getReceiver() == &(ofm.getAmoutOwnerByName("Apartment owner")));
    REQUIRE(ofm.getTransactionByName("Emergency savings").getSender()   == &(ofm.getAmoutOwnerByName("Me")));
    REQUIRE(ofm.getTransactionByName("Emergency savings").getReceiver() == &(ofm.getAmoutOwnerByName("Emergency Fund")));

    ofm.calculateCurrentTransactions();

    REQUIRE(ofm.getAmoutOwnerByName("ABC GmbH"       ).getBalance() == -1000);
    REQUIRE(ofm.getAmoutOwnerByName("CDF AG"         ).getBalance() == -200);
    REQUIRE(ofm.getAmoutOwnerByName("Me"             ).getBalance() == +735);
    REQUIRE(ofm.getAmoutOwnerByName("Insurance 1"    ).getBalance() == +150);
    REQUIRE(ofm.getAmoutOwnerByName("Apartment owner").getBalance() == +300);
    REQUIRE(ofm.getAmoutOwnerByName("Emergency Fund" ).getBalance() ==  +15);

    ofm.calculateCurrentTransactions();

    REQUIRE(ofm.getAmoutOwnerByName("ABC GmbH"       ).getBalance() == -2000);
    REQUIRE(ofm.getAmoutOwnerByName("CDF AG"         ).getBalance() == -400);
    REQUIRE(ofm.getAmoutOwnerByName("Me"             ).getBalance() == +1470);
    REQUIRE(ofm.getAmoutOwnerByName("Insurance 1"    ).getBalance() == +300);
    REQUIRE(ofm.getAmoutOwnerByName("Apartment owner").getBalance() == +600);
    REQUIRE(ofm.getAmoutOwnerByName("Emergency Fund" ).getBalance() ==  +30);
}


TEST_CASE("Test getAmountOwnerByName with a non-existing name") {
    OpenFinanceMonitor ofm;
    ofm.addMoneyGiver("ABC GmbH",0);
    REQUIRE_FALSE(ofm.getAmoutOwnerByName("CDF AG").getName() == "ABC GmbH");
    REQUIRE(ofm.getAmoutOwnerByName("CDF AG").getName() == "Error");
}
