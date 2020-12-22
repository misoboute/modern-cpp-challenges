// Chapter 1 - 3. Problem Least common multiple
// Write a program that will, given two or more positive integers, calculate 
// and print the least common multiple of them all.

#include <gtest/gtest.h>

#include "mathutils.h"

using testing::Test;
using namespace modcppchal::math;

struct Chap01Prob03Fixture : public Test
{
    Chap01Prob03Fixture()
    {
    }

    ~Chap01Prob03Fixture()
    {
    }
};

TEST_F(Chap01Prob03Fixture, LeastCommonMultiple)
{
    EXPECT_EQ(LeastCommonMultiple(1, 1), 1);
    EXPECT_EQ(LeastCommonMultiple(2, 1), 2);
    EXPECT_EQ(LeastCommonMultiple(1, 2), 2);
    EXPECT_EQ(LeastCommonMultiple(2, 2), 2);
    EXPECT_EQ(LeastCommonMultiple(3, 2), 6);
    EXPECT_EQ(LeastCommonMultiple(6, 2), 6);
    EXPECT_EQ(LeastCommonMultiple(4, 2), 4);
    EXPECT_EQ(LeastCommonMultiple(12, 18), 36);
    EXPECT_EQ(
        LeastCommonMultiple<long long unsigned int>(234298 * 30, 234298 * 49),
        234298 * 30 * 49);
}
