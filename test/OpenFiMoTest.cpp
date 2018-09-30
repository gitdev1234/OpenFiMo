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

using namespace  std;

TEST_CASE("Test TODO") {
    OpenFinanceMonitor ofm;
    ofm.addMoneyGiver("ABC GmbH",0);
    ofm.addMoneyGiver("cdf AG",0);
    ofm.addYou("anon",0);
    ofm.addMoneyReceiver("insurance abc",0);
    ofm.addMoneyReceiver("rent apartment",0);
    ofm.addPiggyBank("Emergency Fund",0);

    ofm.addIncomingTransaction("paycheck",ofm.getMoneyGivers()[0],1000);
    ofm.addIncomingTransaction("monthly payment",ofm.getMoneyGivers()[1],200);
    ofm.addOutgoingExpenseTransaction("insurance payment",ofm.getMoneyReceivers()[0],150);
    ofm.addOutgoingExpenseTransaction("aparment rent",ofm.getMoneyReceivers()[1],300);
    ofm.addOutgoingSavingsTransaction("emergency savings",ofm.getPiggyBanks()[0],15);

    ofm.calculateCurrentTransactions();
}
