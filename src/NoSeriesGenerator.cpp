/**
 * NoSeriesGenerator.cpp
 * Purpose: implements class NoSeriesGenerator
 *
 * @author inc-ffh
 */


#include "NoSeriesGenerator.h"



unsigned int NoSeriesGenerator::getNextAmountOwnerNo()
{
    amountOwnerLastNo++;
    return amountOwnerLastNo;
}
