#include "Fraction.h"

using namespace FractionLibrary;

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

void Fraction::setNumerator(const fraction_type numerator)
{
    numerator_ = numerator;
}

void Fraction::setDenominator(const fraction_type denominator)
    throw(DivisionByZero)
{
    if(denominator == 0)
    {
        throw DivisionByZero();
    }
    denominator_ = denominator;
}
