// Chapter 1 - Problem 2. Greatest common divisor
// Write a program that, given two positive integers, will calculate and 
// print the greatest common divisor of the two.

#include <gtest/gtest.h>

#include "mathutils.h"

using testing::Test;
using namespace modcppchal::math;

struct Chap01Prob02Fixture : public Test
{
    Chap01Prob02Fixture()
    {
    }

    ~Chap01Prob02Fixture()
    {
    }
};

TEST_F(Chap01Prob02Fixture, GreatestCommonDivisor)
{
    EXPECT_EQ(GreatestCommonDivisor(1, 1), 1);
    EXPECT_EQ(GreatestCommonDivisor(2, 1), 1);
    EXPECT_EQ(GreatestCommonDivisor(1, 2), 1);
    EXPECT_EQ(GreatestCommonDivisor(2, 2), 2);
    EXPECT_EQ(GreatestCommonDivisor(3, 2), 1);
    EXPECT_EQ(GreatestCommonDivisor(6, 2), 2);
    EXPECT_EQ(GreatestCommonDivisor(4, 2), 2);
    EXPECT_EQ(GreatestCommonDivisor(12, 18), 6);
    EXPECT_EQ(GreatestCommonDivisor(234298 * 30, 234298 * 49), 234298);
}
