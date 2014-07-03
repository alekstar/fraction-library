#include <gtest/gtest.h>
#include "sources/Fraction.h"

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
