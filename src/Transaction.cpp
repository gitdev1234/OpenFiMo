/**
 * Transaction.cpp
 * Purpose: implements class Transaction
 *
 * @author inc-ffh
 * @version 1.0
 */

#include "Transaction.h"

/* --- constructors / destructors --- */

Transaction::Transaction() {
 
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

Amount Transaction::getAmount() const
{
    return amount;
}

void Transaction::setAmount(const Amount &value)
{
    amount = value;
}

/* --- getters / setters --- */

