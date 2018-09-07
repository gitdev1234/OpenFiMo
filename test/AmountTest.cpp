/**
* AmountTest.cpp
* Purpose: implements unit-tests for analysing functions of the Amount-class
*
* @author inc-ffh
* @version 1.0
*/

// !!!! TEST_CASE IN COMBINITION WITH REQUIRE IS LIKE A LOOP STRUCTURE !!!!
// !!!! THE TEST_CASE IS EXECUTED FOR EVERY SECTION !!!!

#include "Amount.h"
#include "catch.hpp"

using namespace  std;


TEST_CASE("Test Constructors") {
    bool perMonth;
    double value;
    AmountType amtType;
    string description;

    SECTION("monthly Expense")  {
        perMonth = true;
        value = 10;
        amtType = AmountType::expense;
        description = "This is a description 1";
    }

    SECTION("yearly Expense")  {
        perMonth = false;
        value = 100;
        amtType = AmountType::expense;
        description = "This is a description 2";
    }

    SECTION("monthly Income")  {
        perMonth = true;
        value = 10;
        amtType = AmountType::income;
        description = "This is a description 3";
    }

    SECTION("yearly Income")  {
        perMonth = false;
        value = 100;
        amtType = AmountType::income;
        description = "This is a description 4";
    }

    Amount amount1(perMonth,value,amtType,description);
    REQUIRE(amount1.getAmountType() == amtType);
    if (perMonth) {
        REQUIRE(amount1.getValuePerMonth() == value);
    } else {
        REQUIRE(amount1.getValuePerYear() == value);
    }

    REQUIRE(amount1.getValuePerMonth() == amount1.getValuePerYear() / 12.0);
    REQUIRE(amount1.getValuePerYear() == amount1.getValuePerMonth() * 12.0);
}

TEST_CASE("Test negative amounts are not possible") {
    bool perMonth;
    double value;
    AmountType amtType;
    string description;

    SECTION("monthly Expense")  {
        perMonth = true;
        value = -10;
        amtType = AmountType::expense;
        description = "This is a description 1";
    }

    SECTION("yearly Expense")  {
        perMonth = false;
        value = -100;
        amtType = AmountType::expense;
        description = "This is a description 2";
    }

    SECTION("monthly Income")  {
        perMonth = true;
        value = -10;
        amtType = AmountType::income;
        description = "This is a description 3";
    }

    SECTION("yearly Income")  {
        perMonth = false;
        value = -100;
        amtType = AmountType::income;
        description = "This is a description 4";
    }

    Amount amount1(perMonth,value,amtType,description);
    REQUIRE(amount1.getAmountType() == amtType);
    if (perMonth) {
        REQUIRE(amount1.getValuePerMonth() == -value);
    } else {
        REQUIRE(amount1.getValuePerYear() == -value);
    }

    REQUIRE(amount1.getValuePerMonth() == amount1.getValuePerYear() / 12.0);
    REQUIRE(amount1.getValuePerYear() == amount1.getValuePerMonth() * 12.0);
    amount1.setValuePerMonth(-50);
    REQUIRE(amount1.getValuePerMonth() == 50);
    REQUIRE(amount1.getValuePerYear() == 50 * 12.0);
    amount1.setValuePerYear(-120);
    REQUIRE(amount1.getValuePerMonth() == 120 / 12.0);
    REQUIRE(amount1.getValuePerYear() == 120);
}
