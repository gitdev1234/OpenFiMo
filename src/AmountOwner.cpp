/**
 * AmountOwner.cpp
 * Purpose: implements class AmountOwner
 *
 * @author inc-ffh
 * @version 1.0
 */

#include "AmountOwner.h"

/* --- constructors / destructors --- */

AmountOwner::AmountOwner() {
 
}

AmountOwnerType AmountOwner::getAmountOwnerType() const
{
    return amountOwnerType;
}

void AmountOwner::setAmountOwnerType(const AmountOwnerType &value)
{
    amountOwnerType = value;
}

double AmountOwner::getRunningTotalBalance() const
{
    return runningTotalBalance;
}

void AmountOwner::setRunningTotalBalance(double value)
{
    runningTotalBalance = value;
}

/* --- getters / setters --- */

