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
        AmountOwner();

        AmountOwnerType getAmountOwnerType() const;
        void setAmountOwnerType(const AmountOwnerType &value);

        double getRunningTotalBalance() const;
        void setRunningTotalBalance(double value);

private:
        AmountOwnerType amountOwnerType;
        double runningTotalBalance;



};

#endif // AmountOwner_H
