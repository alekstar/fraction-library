#include "Fraction.h"

using namespace FractionLibrary;

namespace FractionLibrary
{
    Fraction::Fraction(const fraction_type numerator, 
                       const fraction_type denominator)
        throw (DivisionByZero)
    {
        if(denominator == 0)
        {
            throw DivisionByZero();
        }
        setNumerator(numerator);
        setDenominator(denominator);
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
    
    Fraction operator+(const Fraction& left_operand, const Fraction& right_operand)
    {
        Fraction result;
        if(left_operand.getDenominator() == right_operand.getDenominator())
        {
            result.setDenominator(left_operand.getDenominator());
            result.setNumerator(left_operand.getNumerator() + 
                                right_operand.getNumerator());
        }
        else
        {
            result.setDenominator(left_operand.getDenominator() * 
                                  right_operand.getDenominator());
            result.setNumerator(left_operand.getNumerator() * 
                                right_operand.getDenominator() + 
                                right_operand.getNumerator() * 
                                left_operand.getDenominator());
        }
        return result;
    }
}
