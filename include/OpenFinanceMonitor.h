/**
 * OpenFinanceMonitor.h
 * Purpose: defines class OpenFinanceMonitor
 *
 * @author inc-ffh
 * @version 1.0
 */

#ifndef OpenFinanceMonitor_H
#define OpenFinanceMonitor_H

#include "Types.h"
#include "AmountOwner.h"
#include "Transaction.h"

#include <vector>

using namespace std;

class OpenFinanceMonitor {
    public:
        /* --- constructors / destructors --- */
        OpenFinanceMonitor();

        void addMoneyGiver    (const string &name_, double initialBalance_);
        void addYou           (const string &name_, double initialBalance_);
        void addMoneyReceiver (const string &name_, double initialBalance_);
        void addPiggyBank     (const string &name_, double initialBalance_);

        void addIncomingTransaction        (const string &name_, const AmountOwner &sender_  , double amountPerMonth_);
        void addOutgoingSavingsTransaction (const string &name_, const AmountOwner &receiver_, double amountPerMonth_);
        void addOutgoingExpenseTransaction (const string &name_, const AmountOwner &receiver_, double amountPerMonth_);

        void calculateCurrentTransactions();

        vector<AmountOwner> getAmountOwners() const;
        vector<Transaction> getIncomingTransactions() const;
        vector<Transaction> getOutgoingExpenseTransactions() const;
        vector<Transaction> getOutgoingSavingsTransactions() const;

private:
        vector<AmountOwner> moneyGivers;
        AmountOwner you;
        vector<AmountOwner> moneyReceivers;
        vector<AmountOwner> piggyBanks;
        vector<Transaction> incomingTransactions;
        vector<Transaction> outgoingExpenseTransactions;
        vector<Transaction> outgoingSavingsTransactions;
        
        void addAmountOwner(AmountOwnerType amountOwnerType_, const string &name_, double initialBalance_);
        void addTransaction(TransactionType transactionType_, const string &name_, const AmountOwner &sender_, const AmountOwner &receiver_, double amountPerMonth_);
        void setAmountOwners(const vector<AmountOwner> &value);
        void setIncomingTransactions(const vector<Transaction> &value);
        void setOutgoingExpenseTransactions(const vector<Transaction> &value);
        void setOutgoingSavingsTransactions(const vector<Transaction> &value);
};

#endif // OpenFinanceMonitor_H
