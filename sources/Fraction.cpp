#include "Fraction.h"

Fraction::Fraction()
{
    numerator_ = 0;
    denominator_ = 1;
}

int Fraction::getNumerator()
{
    return numerator_;
}

int Fraction::getDenominator()
{
    return denominator_;
}
