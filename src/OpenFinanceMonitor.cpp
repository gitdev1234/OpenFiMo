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

void OpenFinanceMonitor::addIncomingTransaction(const string &name_, const AmountOwner &sender_  , double amountPerMonth_) {
    addTransaction(TransactionType::incoming,name_,sender_,you,amountPerMonth_);
}

void OpenFinanceMonitor::addOutgoingSavingsTransaction(const string &name_, const AmountOwner &receiver_, double amountPerMonth_) {
    addTransaction(TransactionType::outgoingSavings,name_,you,receiver_,amountPerMonth_);
}

void OpenFinanceMonitor::addOutgoingExpenseTransaction(const string &name_, const AmountOwner &receiver_, double amountPerMonth_) {
    addTransaction(TransactionType::outgoingExpense,name_,you,receiver_,amountPerMonth_);
}

void OpenFinanceMonitor::calculateCurrentTransactions() {
    for (int i=0 ; i < incomingTransactions.size(); i++) {
        incomingTransactions[i].getSender().changeBalance(-incomingTransactions[i].getAmountPerMonth());
        incomingTransactions[i].getReceiver().changeBalance(incomingTransactions[i].getAmountPerMonth());
    }
}

vector<Transaction> OpenFinanceMonitor::getOutgoingExpenseTransactions() const {
    return outgoingExpenseTransactions;
}

void OpenFinanceMonitor::setOutgoingExpenseTransactions(const vector<Transaction> &value) {
    outgoingExpenseTransactions = value;
}

vector<Transaction> OpenFinanceMonitor::getOutgoingSavingsTransactions() const {
    return outgoingSavingsTransactions;
}

vector<Transaction> OpenFinanceMonitor::getIncomingTransactions() const {
    return incomingTransactions;
}

void OpenFinanceMonitor::setIncomingTransactions(const vector<Transaction> &value) {
    incomingTransactions = value;
}

void OpenFinanceMonitor::setOutgoingSavingsTransactions(const vector<Transaction> &value) {
    outgoingSavingsTransactions = value;
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

void OpenFinanceMonitor::addTransaction(TransactionType transactionType_, const string &name_, const AmountOwner &sender_, const AmountOwner &receiver_, double amountPerMonth_) {
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

