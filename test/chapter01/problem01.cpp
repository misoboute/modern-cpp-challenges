#include <gtest/gtest.h>

#include "mathutils.h"

using testing::Test;
using namespace modcppchal::math;

struct Chap01Prob01Fixture : public Test
{
    Chap01Prob01Fixture()
    {
    }

    ~Chap01Prob01Fixture()
    {
    }
};

TEST_F(Chap01Prob01Fixture, T0)
{
    EXPECT_EQ(CalcSumDiv3Div5(0), 0);
}

TEST_F(Chap01Prob01Fixture, T1)
{
    EXPECT_EQ(CalcSumDiv3Div5(1), 0);
}

TEST_F(Chap01Prob01Fixture, T3)
{
    EXPECT_EQ(CalcSumDiv3Div5(3), 0);
}

TEST_F(Chap01Prob01Fixture, T4)
{
    EXPECT_EQ(CalcSumDiv3Div5(4), 3);
}

TEST_F(Chap01Prob01Fixture, T5)
{
    EXPECT_EQ(CalcSumDiv3Div5(5), 3);
}

TEST_F(Chap01Prob01Fixture, T6)
{
    EXPECT_EQ(CalcSumDiv3Div5(6), 8);
}

TEST_F(Chap01Prob01Fixture, T7)
{
    EXPECT_EQ(CalcSumDiv3Div5(7), 14);
}

TEST_F(Chap01Prob01Fixture, T10)
{
    EXPECT_EQ(CalcSumDiv3Div5(10), 23);
}

TEST_F(Chap01Prob01Fixture, T11)
{
    EXPECT_EQ(CalcSumDiv3Div5(11), 33);
}
