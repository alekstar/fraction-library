#include "Fraction.h"
#include <cmath>

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
    
    const Fraction operator+(const Fraction& left_operand, 
                             const Fraction& right_operand)
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
    
    const bool operator==(const Fraction& left_operand, 
                          const Fraction& right_operand)
    {
        return ((left_operand.getNumerator() == 
                    right_operand.getNumerator()) && 
                 left_operand.getDenominator() == 
                    right_operand.getDenominator());
    
    const fraction_type defineCommonDenominator(const fraction_type operand1,
                                                const fraction_type operand2)
    {
        fraction_type number1 = std::abs(operand1);
        fraction_type number2 = std::abs(operand2);
        
        while(number1 != 0 && number2 != 0)
        {
            if(number1 >= number2)
            {
                number1 = number1 % number2;
            }
            else
            {
                number2 = number2 % number1;
            }
        }
        
        return number1 + number2;
    }
    
    const Fraction getReduced(const Fraction& fraction)
    {
        int common_denominator = 
            defineCommonDenominator(fraction.getNumerator(), 
                                    fraction.getDenominator());
        return getWithReducedSign(
            Fraction(fraction.getNumerator() / common_denominator,
                     fraction.getDenominator() / common_denominator));
    }
    
    const Fraction getWithReducedSign(const Fraction& fraction)
    {
        if((fraction.getNumerator() < 0 && fraction.getDenominator() < 0) ||
            fraction.getNumerator() >= 0 && fraction.getDenominator() < 0)
        {
            Fraction result(-fraction);
        }
    }
    
    const Fraction operator-(const Fraction& fraction)
    {
        return Fraction(-fraction.getNumerator(), -fraction.getDenominator());
    }
}
