/**
 * AmountOwner.h
 * Purpose: defines class AmountOwner
 *
 * @author inc-ffh
 * @version 1.0
 */

#ifndef AmountOwner_H
#define AmountOwner_H

#include "Types.h"
#include "NoSeriesGenerator.h"

class AmountOwner {
    public:
        /* --- constructors / destructors --- */
        AmountOwner(const string &name_ = "", const AmountOwnerType &amountOwnerType_ = AmountOwnerType::moneyGiver, double initialBalance_ = 0);
        AmountOwner(const AmountOwner &other_);

        unsigned int getId() const;
        void setId(unsigned int value);

        string getName() const;
        void setName(const string &value);

        double getBalance() const;
        void setBalance(double value);

        AmountOwnerType getAmountOwnerType() const;
        void setAmountOwnerType(const AmountOwnerType &value);

        void changeBalance(double delta_);

private:
        unsigned int id;
        string name;
        double balance;
        AmountOwnerType amountOwnerType;



};

#endif // AmountOwner_H
