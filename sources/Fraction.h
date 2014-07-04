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
    
    const Fraction operator+(const Fraction& left_operand, 
                             const Fraction& right_operand);
    const Fraction operator-(const Fraction& fraction);
    const bool operator==(const Fraction& left_operand, 
                          const Fraction& right_operand);
    const fraction_type defineCommonDenominator(const fraction_type operand1,
                                                const fraction_type operand2);
    const Fraction getReduced(const Fraction& fraction);
    const Fraction getWithReducedSign(const Fraction& fraction);
}

#endif	/* FRACTION_H */

