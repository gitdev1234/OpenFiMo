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
#include "Amount.h"

class Transaction {
    public:
        /* --- constructors / destructors --- */
        Transaction();

        AmountOwner getSender() const;
        void setSender(const AmountOwner &value);

        AmountOwner getReceiver() const;
        void setReceiver(const AmountOwner &value);

        Amount getAmount() const;
        void setAmount(const Amount &value);

private:
        AmountOwner sender;
        AmountOwner receiver;
        Amount amount;



};

#endif // Transaction_H
