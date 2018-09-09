/**
 * Transaction.h
 * Purpose: defines class Transaction
 *
 * @author inc-ffh
 * @version 1.0
 */

#ifndef Transaction_H
#define Transaction_H

#include "Types.h"
#include "AmountOwner.h"

class Transaction {
    public:
        /* --- constructors / destructors --- */
        Transaction(TransactionType transactionType_, const string &name_, const AmountOwner &sender_, const AmountOwner &receiver_, double amountPerMonth_);

        TransactionType getTransactionType() const;
        void setTransactionType(const TransactionType &value);

        string getName() const;
        void setName(const string &value);

        AmountOwner getSender() const;
        void setSender(const AmountOwner &value);

        AmountOwner getReceiver() const;
        void setReceiver(const AmountOwner &value);

        double getAmountPerMonth() const;
        void setAmountPerMonth(double value);

private:
        TransactionType transactionType;
        string name;
        AmountOwner sender;
        AmountOwner receiver;
        double amountPerMonth;

};

#endif // Transaction_H
