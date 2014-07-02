#include <gtest/gtest.h>
#include "sources/Fraction.h"

TEST(DefaultConstructor, ShouldConstructFraction0by1)
{
    Fraction fraction;
    EXPECT_EQ(0, fraction.getNumerator());
    EXPECT_EQ(1, fraction.getDenominator());
}
