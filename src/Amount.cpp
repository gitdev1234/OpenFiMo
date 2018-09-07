/**
 * Amount.cpp
 * Purpose: implements class Amount
 *
 * @author inc-ffh
 * @version 1.0
 */

#include "Amount.h"

/* --- constructors / destructors --- */

Amount::Amount(bool perMonth_, double value_, AmountType amountType_, const string &description_) {
    if (perMonth_) {
        setValuePerMonth(value_);
    } else {
        setValuePerYear(value_);
    }
    setAmountType(amountType_);
    setDescription(description_);
}

/* --- getters / setters --- */

double Amount::getValuePerMonth() const {
    return valuePerMonth;
}

void Amount::setValuePerMonth(double val_) {
    valuePerMonth = val_;
    valuePerYear = val_ * 12.0;
}

double Amount::getValuePerYear() const {
    return valuePerYear;
}

void Amount::setValuePerYear(double val_) {
    valuePerMonth = val_ / 12.0;
    valuePerYear = val_;
}

AmountType Amount::getAmountType() const {
    return amountType;
}

void Amount::setAmountType(const AmountType &val_) {
    amountType = val_;
}

string Amount::getDescription() const {
    return description;
}

void Amount::setDescription(const string &val_) {
    description = val_;
}
