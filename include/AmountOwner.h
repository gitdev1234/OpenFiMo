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

class AmountOwner {
    public:
        /* --- constructors / destructors --- */
        AmountOwner(const string &name_ = "", double initialBalance_ = 0);
        AmountOwner(const AmountOwner &other_);

        string getName() const;
        void setName(const string &value);

        double getBalance() const;
        void setBalance(double value);

        void changeBalance(double delta_);

private:
        string name;
        double balance;



};

#endif // AmountOwner_H
