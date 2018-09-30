/**
 * Transaction.cpp
 * Purpose: implements class Transaction
 *
 * @author inc-ffh
 * @version 1.0
 */

#include "Transaction.h"

/* --- constructors / destructors --- */

Transaction::Transaction(TransactionType transactionType_, const string &name_, AmountOwner *sender_, AmountOwner *receiver_, double amountPerMonth_)
{
    setTransactionType(transactionType_);
    setName(name_);
    setAmountPerMonth(amountPerMonth_);
    sender = sender_;
    receiver = receiver_;
}

TransactionType Transaction::getTransactionType() const
{
    return transactionType;
}

void Transaction::setTransactionType(const TransactionType &value)
{
    transactionType = value;
}

string Transaction::getName() const
{
    return name;
}

void Transaction::setName(const string &value)
{
    name = value;
}

double Transaction::getAmountPerMonth() const
{
    return amountPerMonth;
}

void Transaction::setAmountPerMonth(double value)
{
    amountPerMonth = value;
}

AmountOwner *Transaction::getSender()
{
    return sender;
}

void Transaction::setSender(AmountOwner *value)
{
    sender = value;
}

AmountOwner *Transaction::getReceiver()
{
    return receiver;
}

void Transaction::setReceiver(AmountOwner *value)
{
    receiver = value;
}


/* --- getters / setters --- */

