/**
 * OpenFinanceMonitor.cpp
 * Purpose: implements class OpenFinanceMonitor
 *
 * @author inc-ffh
 * @version 1.0
 */

#include "OpenFinanceMonitor.h"

/* --- constructors / destructors --- */

OpenFinanceMonitor::OpenFinanceMonitor() {

}

void OpenFinanceMonitor::addMoneyGiver(const string &name_, double initialBalance_) {
    addAmountOwner(AmountOwnerType::moneyGiver,name_,initialBalance_);
}

void OpenFinanceMonitor::addYou(const string &name_, double initialBalance_) {
    addAmountOwner(AmountOwnerType::you,name_,initialBalance_);
}

void OpenFinanceMonitor::addMoneyReceiver(const string &name_, double initialBalance_) {
    addAmountOwner(AmountOwnerType::moneyReceiver,name_,initialBalance_);
}

void OpenFinanceMonitor::addPiggyBank(const string &name_, double initialBalance_) {
    addAmountOwner(AmountOwnerType::piggyBank,name_,initialBalance_);
}



vector<AmountOwner> OpenFinanceMonitor::getAmountOwners() const
{
    return amountOwners;
}

void OpenFinanceMonitor::setAmountOwners(const vector<AmountOwner> &value)
{
    amountOwners = value;
}

vector<Transaction> OpenFinanceMonitor::getTransactions() const
{
    return transactions;
}

void OpenFinanceMonitor::setTransactions(const vector<Transaction> &value)
{
    transactions = value;
}

/* --- private functions --- */

void OpenFinanceMonitor::addAmountOwner(AmountOwnerType amountOwnerType_, const string &name_, double initialBalance_) {
    AmountOwner temp(name_,initialBalance_);
    switch (amountOwnerType_) {
        case AmountOwnerType::moneyGiver:
            moneyGivers.push_back(temp);
            break;
        case AmountOwnerType::you:
            you = temp;
            break;
        case AmountOwnerType::moneyReceiver:
            moneyReceivers.push_back(temp);
            break;
        case AmountOwnerType::piggyBank:
            piggyBanks.push_back(temp);
            break;
        default:
            break;
    }
}

/* --- getters / setters --- */

