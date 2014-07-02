#include "Fraction.h"

Fraction::Fraction()
{
    numerator_ = getDefaultNumerator();
    denominator_ = getDefaultDenominator();
}

int Fraction::getNumerator()
{
    return numerator_;
}

int Fraction::getDenominator()
{
    return denominator_;
}

int Fraction::getDefaultNumerator() const
{
    return 0;
}

int Fraction::getDefaultDenominator() const
{
    return 1;
}
