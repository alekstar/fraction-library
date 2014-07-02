#ifndef FRACTION_H
#define	FRACTION_H

#include "exceptions/DivisionByZero.h"

typedef int fraction_type;

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
};

#endif	/* FRACTION_H */

