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
#include "Amount.h"
#include "Transaction.h"

#include <vector>

using namespace std;

class OpenFinanceMonitor {
    public:
        /* --- constructors / destructors --- */
        OpenFinanceMonitor();

        void addMoneyGiver    (const string &name_, double initialRunningTotalBalance_);
        void addYou           (const string &name_, double initialRunningTotalBalance_);
        void addMoneyReceiver (const string &name_, double initialRunningTotalBalance_);
        void addPiggyBank     (const string &name_, double initialRunningTotalBalance_);

        void addIncomingTransaction (const Amount &amount, const AmountOwner &sender_);
        void addOutgoingSavingsTransaction (const Amount &amount, const AmountOwner &receiver);
        void addOutgoingExpenseTransaction (const Amount &amount, const AmountOwner &receiver);

        vector<AmountOwner> getAmountOwners() const;
        void setAmountOwners(const vector<AmountOwner> &value);

        vector<Transaction> getTransactions() const;
        void setTransactions(const vector<Transaction> &value);

private:
        vector<AmountOwner> moneyGivers;
        AmountOwner you;
        vector<AmountOwner> moneyReceivers;
        vector<AmountOwner> piggyBanks;
        vector<Transaction> incomingTransactions;
        vector<Transaction> outgoingTransactions;


};

#endif // OpenFinanceMonitor_H
