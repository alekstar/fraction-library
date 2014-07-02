#ifndef FRACTION_H
#define	FRACTION_H

class Fraction
{
    int numerator_;
    int denominator_;
    
    int getDefaultNumerator() const;
    int getDefaultDenominator() const;
public:    
    Fraction();
    int getNumerator();
    int getDenominator();
};

#endif	/* FRACTION_H */

