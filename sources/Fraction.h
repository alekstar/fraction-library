#ifndef FRACTION_H
#define	FRACTION_H

#include "exceptions/DivisionByZero.h"
#include "fraction_type.h"

namespace FractionLibrary
{
    class Fraction
    {
        fraction_type numerator_;
        fraction_type denominator_;

        static fraction_type getDefaultNumerator();
        static fraction_type getDefaultDenominator();
    public:    
        Fraction(const fraction_type numerator = getDefaultNumerator(), 
                 const fraction_type denominator = getDefaultDenominator())
            throw (DivisionByZero);
        fraction_type getNumerator() const;
        fraction_type getDenominator() const;
        void setNumerator(const fraction_type numerator);
        void setDenominator(const fraction_type denominator)
            throw (DivisionByZero);
    };
}

#endif	/* FRACTION_H */

