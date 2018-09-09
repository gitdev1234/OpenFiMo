/**
 * AmountOwner.cpp
 * Purpose: implements class AmountOwner
 *
 * @author inc-ffh
 * @version 1.0
 */

#include "AmountOwner.h"

/* --- constructors / destructors --- */

AmountOwner::AmountOwner(const string &name_, double initialBalance_) {
    setName(name_);
    setBalance(initialBalance_);
}


double AmountOwner::getRunningTotalBalance() const
{
    return runningTotalBalance;
}

void AmountOwner::setRunningTotalBalance(double value)
{
    runningTotalBalance = value;
}

string AmountOwner::getName() const
{
    return name;
}

void AmountOwner::setName(const string &value)
{
    name = value;
}

double AmountOwner::getBalance() const
{
    return balance;
}

void AmountOwner::setBalance(double value)
{
    balance = value;
}

/* --- getters / setters --- */

