#include "Fraction.h"

Fraction::Fraction(const fraction_type numerator, 
                   const fraction_type denominator)
    throw (DivisionByZero)
{
    if(denominator == 0)
    {
        throw DivisionByZero();
    }
    numerator_ = numerator;
    denominator_ = denominator;
}

fraction_type Fraction::getNumerator() const
{
    return numerator_;
}

fraction_type Fraction::getDenominator() const
{
    return denominator_;
}

fraction_type Fraction::getDefaultNumerator()
{
    return 0;
}

fraction_type Fraction::getDefaultDenominator()
{
    return 1;
}
