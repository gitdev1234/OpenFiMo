/**
 * Transaction.cpp
 * Purpose: implements class Transaction
 *
 * @author inc-ffh
 * @version 1.0
 */

#include "Transaction.h"

/* --- constructors / destructors --- */

Transaction::Transaction(TransactionType transactionType_, const string &name_, const AmountOwner &sender_, const AmountOwner &receiver_, double amountPerMonth_) {
    setTransactionType(transactionType_);
    setName(name_);
    setSender(sender_);
    setReceiver(receiver_);
    setAmountPerMonth(amountPerMonth_);
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

AmountOwner Transaction::getSender() const
{
    return sender;
}

void Transaction::setSender(const AmountOwner &value)
{
    sender = value;
}

AmountOwner Transaction::getReceiver() const
{
    return receiver;
}

void Transaction::setReceiver(const AmountOwner &value)
{
    receiver = value;
}

double Transaction::getAmountPerMonth() const
{
    return amountPerMonth;
}

void Transaction::setAmountPerMonth(double value)
{
    amountPerMonth = value;
}


/* --- getters / setters --- */

