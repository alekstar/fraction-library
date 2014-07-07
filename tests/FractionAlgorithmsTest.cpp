#include <gtest/gtest.h>
#include "sources/FractionAlgorithms.h"

using namespace FractionLibrary;

TEST(OperatorPlus, ResultShouldBe2by2)
{
    Fraction operand1(1, 2);
    Fraction operand2(1, 2);
    Fraction result = operand1 + operand2;
    EXPECT_EQ(2, result.getNumerator());
    EXPECT_EQ(2, result.getDenominator());
}

TEST(OperatorPlus, ResultShouldBe17By12)
{
    Fraction operand1(2, 3);
    Fraction operand2(3, 4);
    Fraction result = operand1 + operand2;
    EXPECT_EQ(17, result.getNumerator());
    EXPECT_EQ(12, result.getDenominator());
}

TEST(OperatorPlus, ResultShouldBeMinus1By12)
{
    Fraction operand1(2, 3);
    Fraction operand2(-3, 4);
    Fraction result = operand1 + operand2;
    EXPECT_EQ(-1, result.getNumerator());
    EXPECT_EQ(12, result.getDenominator());
}

TEST(OperatorPlus, ResultShouldBe11By4)
{
    int operand1(2);
    Fraction operand2(3, 4);
    Fraction result = operand1 + operand2;
    EXPECT_EQ(11, result.getNumerator());
    EXPECT_EQ(4, result.getDenominator());
}

TEST(OperatorPlus, ResultShouldBe15By4)
{
    Fraction operand1(3, 4);
    int operand2(3);
    Fraction result = operand1 + operand2;
    EXPECT_EQ(15, result.getNumerator());
    EXPECT_EQ(4, result.getDenominator());
}

TEST(OperatorPlus, MustBeCommutative)
{
    Fraction operand1(-14, 345);
    Fraction operand2(17, 3);
    EXPECT_EQ(operand1 + operand2, operand2 + operand1);
}

TEST(OperatorPlus, MustBeAssociative)
{
    Fraction operand1(15, -1345);
    Fraction operand2(16, 1);
    Fraction operand3(17, 17);
    EXPECT_EQ((operand1 + operand2) + operand3, 
              operand1 + (operand2 + operand3));
}

TEST(OperatorEqual, 1By2And1By2ShouldBeEqual)
{
    EXPECT_EQ(Fraction(1, 2), Fraction(1, 2));
}

TEST(OperatorEqual, 1By2And2By3ShouldNotBeEqual)
{
    EXPECT_FALSE(Fraction(1, 2) == Fraction(2, 3));
}

TEST(OperatorEqual, 1By2And2By4ShouldBeEqual)
{
    EXPECT_EQ(Fraction(1, 2), Fraction(2, 4));
}

TEST(OperatorEqual, Minus1ByMinus2And1By2ShouldBeEqual)
{
    EXPECT_TRUE(Fraction(-1, -2) == Fraction(1, 2));
}

TEST(getWithReducedSign, ReducedMinus1ByMinus2ShouldBeEqualTo1By2)
{
    EXPECT_EQ(Fraction(1, 2), getWithReducedSign(Fraction(-1, -2)));
}

TEST(getWithReducedSign, Reduced1By2ShouldBeEqualTo1By2)
{
    EXPECT_EQ(Fraction(1, 2), getWithReducedSign(Fraction(1, 2)));
}

TEST(getReduced, ReducedMinus1ByMinus2ShouldBeEqualTo1By2)
{
    EXPECT_EQ(Fraction(1, 2), getReduced(Fraction(-1, -2)));
}

TEST(getReduced, Reduced1By2ShouldBeEqualTo1By2)
{
    EXPECT_EQ(Fraction(1, 2), getReduced(Fraction(1, 2)));
}

TEST(getReduced, Reduced12By48ShouldBeEqualTo1By4)
{
    EXPECT_EQ(Fraction(1, 4), getReduced(Fraction(12, 48)));
}

TEST(getReduced, ReducedMinus15By25ShouldBeEqualToMinus3By5)
{
    EXPECT_EQ(Fraction(3, 5), getReduced(Fraction(15, 25)));
}

TEST(OperatorMinus, 1By2Minus1By4ShouldBeEqualTo1By4)
{
    EXPECT_EQ(Fraction(1, 4), Fraction(1, 2) - Fraction(1, 4));
}

TEST(defineGreatestCommonDivisor, 5And10ShouldReturn5)
{
    EXPECT_EQ(5, defineGreatestCommonDivisor(5, 10));
}

TEST(defineGreatestCommonDivisor, 10And15ShouldReturn5)
{
    EXPECT_EQ(5, defineGreatestCommonDivisor(10, 15));
}

TEST(defineGreatestCommonDivisor, 3And5ShouldReturn1)
{
    EXPECT_EQ(1, defineGreatestCommonDivisor(3, 5));
}

TEST(operatorNotEqual, 1By2ShouldBeNotEqualTo1By3)
{
    EXPECT_TRUE(Fraction(1, 2) != Fraction(1, 3));
}
