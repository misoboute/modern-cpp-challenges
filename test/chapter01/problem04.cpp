// Chapter 1 - 4. Largest prime smaller than given number
// Write a program that computes and prints the largest prime number that is 
// smaller than a number provided by the user, which must be a positive integer.

#include <gtest/gtest.h>

#include "mathutils.h"

using testing::Test;
using namespace modcppchal::math;

struct Chap01Prob04Fixture : public Test
{
    Chap01Prob04Fixture()
    {
    }

    ~Chap01Prob04Fixture()
    {
    }
};

TEST_F(Chap01Prob04Fixture, LargestPrimeSmallerThanNumber)
{
    EXPECT_EQ(LargestPrimeThan(1), 2);
    EXPECT_EQ(LargestPrimeThan(2), 2);
    EXPECT_EQ(LargestPrimeThan(3), 2);
    EXPECT_EQ(LargestPrimeThan(4), 3);
    EXPECT_EQ(LargestPrimeThan(5), 3);
    EXPECT_EQ(LargestPrimeThan(6), 5);
    EXPECT_EQ(LargestPrimeThan(7), 5);
    EXPECT_EQ(LargestPrimeThan(8), 7);
    EXPECT_EQ(LargestPrimeThan(9), 7);
    EXPECT_EQ(LargestPrimeThan(10), 7);
    EXPECT_EQ(LargestPrimeThan(11), 7);
    EXPECT_EQ(LargestPrimeThan(12), 11);
    EXPECT_EQ(LargestPrimeThan(100), 97);
    EXPECT_EQ(LargestPrimeThan(1000), 997);
    EXPECT_EQ(LargestPrimeThan(10000), 9973);
    EXPECT_EQ(LargestPrimeThan(100000), 99991);
    EXPECT_EQ(LargestPrimeThan(1000000), 999983);
}
