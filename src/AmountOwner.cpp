/**
 * AmountOwner.cpp
 * Purpose: implements class AmountOwner
 *
 * @author inc-ffh
 * @version 1.0
 */

#include "AmountOwner.h"

/* --- constructors / destructors --- */

AmountOwner::AmountOwner(const string &name_, const AmountOwnerType &amountOwnerType_, double initialBalance_) {
    // create and init singleton-NoSeriesGenerator-object
    NoSeriesGenerator& nsGen = NoSeriesGenerator::getInstance();
    // set numeric identifier for AmountOwner
    setId(nsGen.getNextAmountOwnerNo());
    setName(name_);
    setBalance(initialBalance_);
    setAmountOwnerType(amountOwnerType_);
}

AmountOwner::AmountOwner(const AmountOwner &other_) {
    setId(other_.getId());
    setName(other_.getName());
    setBalance(other_.getBalance());
    setAmountOwnerType(other_.getAmountOwnerType());
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

AmountOwnerType AmountOwner::getAmountOwnerType() const
{
    return amountOwnerType;
}

void AmountOwner::setAmountOwnerType(const AmountOwnerType &value)
{
    amountOwnerType = value;
}

unsigned int AmountOwner::getId() const
{
    return id;
}

void AmountOwner::setId(unsigned int value)
{
    id = value;
}

/* --- getters / setters --- */

