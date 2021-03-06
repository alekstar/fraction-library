#include <gtest/gtest.h>
#include "sources/Fraction.h"
#include "sources/FractionAlgorithms.h"

using namespace FractionLibrary;

TEST(Constructor, ShouldConstructFraction0by1)
{
    Fraction fraction;
    EXPECT_EQ(0, fraction.getNumerator());
    EXPECT_EQ(1, fraction.getDenominator());
}

TEST(Constructor, ShouldConstructFraction1by2)
{
    Fraction fraction(1, 2);
    EXPECT_EQ(1, fraction.getNumerator());
    EXPECT_EQ(2, fraction.getDenominator());
}

TEST(Constructor, ShouldThrowExceptionDivisionByZero)
{
    EXPECT_THROW(Fraction(1, 0), DivisionByZero);
}

TEST(Constructor, ShouldConstructFraction5by3)
{
    Fraction fraction(5, 3);
    EXPECT_EQ(5, fraction.getNumerator());
    EXPECT_EQ(3, fraction.getDenominator());
}

TEST(Constructor, ShouldConstruct7by7)
{
    Fraction fraction(7, 7);
    EXPECT_EQ(7, fraction.getNumerator());
    EXPECT_EQ(7, fraction.getDenominator());
}

TEST(SetNumerator, ShouldSetNumeratorTo3)
{
    Fraction fraction;
    fraction.setNumerator(3);
    EXPECT_EQ(3, fraction.getNumerator());
    EXPECT_EQ(1, fraction.getDenominator());
}

TEST(SetNumerator, ShouldSetNumeratorTo0)
{
    Fraction fraction;
    fraction.setNumerator(0);
    EXPECT_EQ(0, fraction.getNumerator());
    EXPECT_EQ(1, fraction.getDenominator());
}

TEST(SetNumerator, ShouldSetNumeratorToMinus5)
{
    Fraction fraction(10, 7);
    fraction.setNumerator(-5);
    EXPECT_EQ(-5, fraction.getNumerator());
    EXPECT_EQ(7, fraction.getDenominator());
}

TEST(SetDenominator, ShouldSetDenominatorTo3)
{
    Fraction fraction(2, 5);
    fraction.setDenominator(3);
    EXPECT_EQ(2, fraction.getNumerator());
    EXPECT_EQ(3, fraction.getDenominator());
}

TEST(SetDenominator, ShouldThrowAnExceptionDivisionByZero)
{
    Fraction fraction(2, 5);
    EXPECT_THROW(fraction.setDenominator(0), DivisionByZero);
    
}

TEST(SetDenominator, ShouldSetDenominatorToMinus100)
{
    Fraction fraction(2, 5);
    fraction.setDenominator(-100);
    EXPECT_EQ(2, fraction.getNumerator());
    EXPECT_EQ(-100, fraction.getDenominator());
}
