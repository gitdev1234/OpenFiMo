/**
 * Amount.h
 * Purpose: defines class Amount
 *
 * @author inc-ffh
 * @version 1.0
 */

#ifndef Amount_H
#define Amount_H

#include "Types.h"

class Amount {
    public:
        /* --- constructors / destructors --- */
        Amount(bool perMonth_ =  true, double value_ = 0, AmountType amountType_ = AmountType::expense, const string &description_ = "");

        double getValuePerMonth() const;
        void setValuePerMonth(double val_);

        double getValuePerYear() const;
        void setValuePerYear(double val_);

        AmountType getAmountType() const;
        void setAmountType(const AmountType &val_);

        string getDescription() const;
        void setDescription(const string &val_);

private:
        double valuePerMonth;
        double valuePerYear;
        AmountType amountType;
        string description;


};

#endif // Amount_H
