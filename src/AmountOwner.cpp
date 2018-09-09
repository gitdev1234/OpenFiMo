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

void AmountOwner::changeBalance(double delta_) {
    balance += delta_;
}

/* --- getters / setters --- */

