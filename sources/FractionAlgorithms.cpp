#include "FractionAlgorithms.h"
#include "Fraction.h"
#include <cmath>

namespace FractionLibrary
{
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
        if ((left_operand.getNumerator() == 
                right_operand.getNumerator()) && 
             left_operand.getDenominator() == 
                right_operand.getDenominator())
        {
            return true;
        }
        Fraction reduced_left_operand = getReduced(left_operand);
        Fraction reduced_right_operand = getReduced(right_operand);
        if((reduced_left_operand.getNumerator() == 
                reduced_right_operand.getNumerator()) && 
             reduced_left_operand.getDenominator() == 
                reduced_right_operand.getDenominator())
        {
            return true;
        }
        return false;
    }
    
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
            return -fraction;
        }
        return fraction;
    }
    
    const Fraction operator-(const Fraction& fraction)
    {
        return Fraction(-fraction.getNumerator(), -fraction.getDenominator());
    }
}
