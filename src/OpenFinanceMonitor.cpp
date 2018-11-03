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

void OpenFinanceMonitor::addIncomingTransaction(const string &name_, AmountOwner &sender_  , double amountPerMonth_) {
    addTransaction(TransactionType::incoming,name_,&sender_,&you,amountPerMonth_);
}

void OpenFinanceMonitor::addOutgoingSavingsTransaction(const string &name_, AmountOwner &receiver_, double amountPerMonth_) {
    addTransaction(TransactionType::outgoingSavings,name_,&you,&receiver_,amountPerMonth_);
}

void OpenFinanceMonitor::addOutgoingExpenseTransaction(const string &name_, AmountOwner &receiver_, double amountPerMonth_) {
    addTransaction(TransactionType::outgoingExpense,name_,&you,&receiver_,amountPerMonth_);
}

void OpenFinanceMonitor::calculateCurrentTransactions() {
    for (unsigned int i=0 ; i < incomingTransactions.size(); i++) {
        (*incomingTransactions[i].getSender()).changeBalance(-incomingTransactions[i].getAmountPerMonth());
        (*incomingTransactions[i].getReceiver()).changeBalance(incomingTransactions[i].getAmountPerMonth());
    }
    for (unsigned int i=0 ; i < outgoingExpenseTransactions.size(); i++) {
        (*outgoingExpenseTransactions[i].getSender()).changeBalance(-outgoingExpenseTransactions[i].getAmountPerMonth());
        (*outgoingExpenseTransactions[i].getReceiver()).changeBalance(outgoingExpenseTransactions[i].getAmountPerMonth());
    }
    for (unsigned int i=0 ; i < outgoingSavingsTransactions.size(); i++) {
        (*outgoingSavingsTransactions[i].getSender()).changeBalance(-outgoingSavingsTransactions[i].getAmountPerMonth());
        (*outgoingSavingsTransactions[i].getReceiver()).changeBalance(outgoingSavingsTransactions[i].getAmountPerMonth());
    }
}


/*
vector<Transaction>& OpenFinanceMonitor::getOutgoingExpenseTransactions() const {
    return outgoingExpenseTransactions;
}

void OpenFinanceMonitor::setOutgoingExpenseTransactions(vector<Transaction> &value) {
    outgoingExpenseTransactions = value;
}

vector<Transaction> OpenFinanceMonitor::getOutgoingSavingsTransactions() const {
    return outgoingSavingsTransactions;
}

vector<AmountOwner>& OpenFinanceMonitor::getMoneyGivers()
{
    return moneyGivers;
}

*/
AmountOwner &OpenFinanceMonitor::getAmoutOwnerByID(unsigned int id_)
{
    if (you.getId() == id_) {
        return you;
    }

    for (unsigned int i=0; i<moneyGivers.size(); i++) {
        if (moneyGivers[i].getId() == id_) {
            return moneyGivers[i];
        }
    }
    for (unsigned int i=0; i<moneyReceivers.size(); i++) {
        if (moneyReceivers[i].getId() == id_) {
            return moneyReceivers[i];
        }
    }
    for (unsigned int i=0; i<piggyBanks.size(); i++) {
        if (piggyBanks[i].getId() == id_) {
            return piggyBanks[i];
        }
    }

    // if there is no amount owner with the requested id
    // return an empty amount owner with name "Error"
    return emptyAmountOwner;
}

AmountOwner &OpenFinanceMonitor::getAmoutOwnerByName(const string &name_)
{
    if (you.getName() == name_) {
        return you;
    }

    for (unsigned int i=0; i < moneyGivers.size(); i++) {
        if (moneyGivers[i].getName() == name_) {
            return moneyGivers[i];
        }
    }
    for (unsigned int i=0; i < moneyReceivers.size(); i++) {
        if (moneyReceivers[i].getName() == name_) {
            return moneyReceivers[i];
        }
    }
    for (unsigned int i=0; i < piggyBanks.size(); i++) {
        if (piggyBanks[i].getName() == name_) {
            return piggyBanks[i];
        }
    }

    // if there is no amount owner with the requested name
    // return an empty amount owner with name "Error"
    return emptyAmountOwner;

}
/*
void OpenFinanceMonitor::setMoneyGivers(const vector<AmountOwner> &value)
{
    moneyGivers = value;
}

AmountOwner OpenFinanceMonitor::getYou() const
{
    return you;
}

void OpenFinanceMonitor::setYou(const AmountOwner &value)
{
    you = value;
}

vector<AmountOwner> OpenFinanceMonitor::getMoneyReceivers() const
{
    return moneyReceivers;
}

void OpenFinanceMonitor::setMoneyReceivers(const vector<AmountOwner> &value)
{
    moneyReceivers = value;
}

vector<AmountOwner> OpenFinanceMonitor::getPiggyBanks() const
{
    return piggyBanks;
}

void OpenFinanceMonitor::setPiggyBanks(const vector<AmountOwner> &value)
{
    piggyBanks = value;
}

vector<Transaction> OpenFinanceMonitor::getIncomingTransactions() const {
    return incomingTransactions;
}

void OpenFinanceMonitor::setIncomingTransactions(vector<Transaction> &value) {
    incomingTransactions = value;
}

void OpenFinanceMonitor::setOutgoingSavingsTransactions(vector<Transaction> &value) {
    outgoingSavingsTransactions = value;
}*/

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

void OpenFinanceMonitor::addTransaction(TransactionType transactionType_, const string &name_, AmountOwner *sender_, AmountOwner *receiver_, double amountPerMonth_) {
    Transaction temp(transactionType_,name_,sender_,receiver_,amountPerMonth_);
    switch (transactionType_) {
    case TransactionType::incoming:
        incomingTransactions.push_back(temp);
        break;
    case TransactionType::outgoingExpense:
        outgoingExpenseTransactions.push_back(temp);
        break;
    case TransactionType::outgoingSavings:
        outgoingSavingsTransactions.push_back(temp);
        break;
    default:
        break;
    }
}

/* --- getters / setters --- */

