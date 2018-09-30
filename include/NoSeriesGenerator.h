/**
 * NoSeriesGenerator.h
 * Purpose: defines class NoSeriesGenerator
 *
 * @author inc-ffh
 */

#ifndef NoSeriesGenerator_H
#define NoSeriesGenerator_H


/**
 * NoSeriesGenerator class
 */
class NoSeriesGenerator {
    public:
        /* --- needed to create a singleton --- */
        static NoSeriesGenerator& getInstance() {
            static NoSeriesGenerator _instance;
            return _instance;
        }
        ~NoSeriesGenerator() {}

        unsigned int getNextAmountOwnerNo();

    private:
        /* --- needed to create a singleton --- */
        NoSeriesGenerator() {};  // must be private to avoid the creation of NoSeriesGenerator from the outside by the constructor
                                 // use 'protected' if you want to inherit from this class
        NoSeriesGenerator            (const NoSeriesGenerator& NoSeriesGenerator_); // must be private to avoid creation of another NoSeriesGenerator-instance by copy-constructor
        NoSeriesGenerator& operator= (const NoSeriesGenerator& NoSeriesGenerator_); // must be private to avoid creating an new NoSeriesGenerator-instance by copying

        unsigned int amountOwnerLastNo;


};

#endif // NoSeriesGenerator_H
