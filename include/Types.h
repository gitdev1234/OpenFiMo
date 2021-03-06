/**
 * Types.h
 * Purpose: defines structs, constants and enums
 *
 * @author inc-ffh
 * @version 1.0
 */

#ifndef TYPES_H
#define TYPES_H

#include <string>

using namespace std;

/* --- structs --- */

/* --- constants --- */

// timer intervals in milli seconds

// error messages

/* --- enumerations --- */
enum AmountType {expense, income};
enum AmountOwnerType {moneyGiver,you,moneyReceiver,piggyBank};
enum TransactionType {incoming, outgoingExpense, outgoingSavings};

#endif // TYPES_H
