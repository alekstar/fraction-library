#ifndef FRACTIONALGORITHMS_H
#define	FRACTIONALGORITHMS_H
#include "fraction_type.h"
#include "Fraction.h"

namespace FractionLibrary
{
    const Fraction operator+(const Fraction& left_operand, 
                             const Fraction& right_operand);
    const Fraction operator-(const Fraction& fraction);
    const Fraction operator-(const Fraction& left_operand, 
                             const Fraction& right_operand);
    const Fraction operator*(const Fraction& left_operand, 
                             const Fraction& right_operand);
    const Fraction operator/(const Fraction& left_operand,
                             const Fraction& right_operand);
    const bool operator==(const Fraction& left_operand, 
                          const Fraction& right_operand);
    const bool operator!=(const Fraction& left_operand, 
                          const Fraction& right_operand);
    const fraction_type defineGreatestCommonDivisor(const fraction_type operand1,
                                                const fraction_type operand2);
    const Fraction getReduced(const Fraction& fraction);
    const Fraction getWithReducedSign(const Fraction& fraction);
}

#endif	/* FRACTIONALGORITHMS_H */

