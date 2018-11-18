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

        void addIncomingTransaction        (const string &name_, AmountOwner &sender_  , double amountPerMonth_);
        void addOutgoingSavingsTransaction (const string &name_, AmountOwner &receiver_, double amountPerMonth_);
        void addOutgoingExpenseTransaction (const string &name_, AmountOwner &receiver_, double amountPerMonth_);

        void calculateCurrentTransactions();

        AmountOwner& getAmoutOwnerByID(unsigned int id_);
        AmountOwner& getAmoutOwnerByName(const string& name_);

/*
        vector<AmountOwner>& getMoneyGivers()    ;
        AmountOwner&         getYou()            ;
        vector<AmountOwner>& getMoneyReceivers()  ;
        vector<AmountOwner>& getPiggyBanks()      ;
        vector<Transaction>& getIncomingTransactions() ;
        vector<Transaction>& getOutgoingExpenseTransactions() ;
        vector<Transaction>& getOutgoingSavingsTransactions() ;
*/

private:
        vector<AmountOwner> moneyGivers;
        AmountOwner         you;
        vector<AmountOwner> moneyReceivers;
        vector<AmountOwner> piggyBanks;
        vector<Transaction> incomingTransactions;
        vector<Transaction> outgoingExpenseTransactions;
        vector<Transaction> outgoingSavingsTransactions;

        // for outputting an error
        AmountOwner emptyAmountOwner = AmountOwner("Error",AmountOwnerType::moneyGiver,0);
        
        void addAmountOwner(AmountOwnerType amountOwnerType_, const string &name_, double initialBalance_);
        void addTransaction(TransactionType transactionType_, const string &name_, AmountOwner *sender_, AmountOwner *receiver_, double amountPerMonth_);
        void setPiggyBanks(const vector<AmountOwner> &value);
        void setMoneyReceivers(const vector<AmountOwner> &value);
        void setYou(const AmountOwner &value);
        void setMoneyGivers(const vector<AmountOwner> &value);
        void setIncomingTransactions(vector<Transaction> &value);
        void setOutgoingExpenseTransactions(vector<Transaction> &value);
        void setOutgoingSavingsTransactions(vector<Transaction> &value);
};

#endif // OpenFinanceMonitor_H
