#ifndef FRACTION_H
#define	FRACTION_H

#include "exceptions/DivisionByZero.h"

namespace FractionLibrary
{
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
        void setNumerator(const fraction_type numerator);
        void setDenominator(const fraction_type denominator)
            throw (DivisionByZero);
    };
    
    const Fraction operator+(const Fraction& left_operand, 
                             const Fraction& right_operand);
    const bool operator==(const Fraction& operand1, 
                          const Fraction& operand2);
}

#endif	/* FRACTION_H */

