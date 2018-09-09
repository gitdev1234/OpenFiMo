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

        string getName() const;
        void setName(const string &value);

        double getBalance() const;
        void setBalance(double value);

private:
        string name;
        double balance;



};

#endif // AmountOwner_H
