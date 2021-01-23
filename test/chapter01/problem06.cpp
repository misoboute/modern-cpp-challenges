// Chapter 1 - 6. Abundant numbers
// Write a program that prints all abundant numbers and their abundance, up 
// to a number entered by the user.

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "mathutils.h"

using testing::ElementsAre;
using testing::IsEmpty;
using testing::Test;
using testing::UnorderedElementsAre;

using namespace modcppchal::math;

struct Chap01Prob06Fixture : public Test
{
    Chap01Prob06Fixture()
    {
    }

    ~Chap01Prob06Fixture()
    {
    }
};

TEST_F(Chap01Prob06Fixture, ComputeAllDivisors)
{
    IntDivisors divs;
    auto testFunc = [&divs](auto n) { return divs.ComputeAllDivisors(n); };
    EXPECT_THAT(testFunc(0), IsEmpty());
    EXPECT_THAT(testFunc(1), UnorderedElementsAre(1));
    EXPECT_THAT(testFunc(2), UnorderedElementsAre(1, 2));
    EXPECT_THAT(testFunc(3), UnorderedElementsAre(1, 3));
    EXPECT_THAT(testFunc(4), UnorderedElementsAre(1, 2, 4));
    EXPECT_THAT(testFunc(5), UnorderedElementsAre(1, 5));
    EXPECT_THAT(testFunc(6), UnorderedElementsAre(1, 2, 3, 6));
    EXPECT_THAT(testFunc(7), UnorderedElementsAre(1, 7));
    EXPECT_THAT(testFunc(8), UnorderedElementsAre(1, 2, 4, 8));
    EXPECT_THAT(testFunc(9), UnorderedElementsAre(1, 3, 9));
    EXPECT_THAT(testFunc(10), UnorderedElementsAre(1, 2, 5, 10));
    EXPECT_THAT(testFunc(11), UnorderedElementsAre(1, 11));
    EXPECT_THAT(testFunc(12), UnorderedElementsAre(1, 2, 3, 4, 6, 12));
    EXPECT_THAT(testFunc(13), UnorderedElementsAre(1, 13));
    EXPECT_THAT(testFunc(14), UnorderedElementsAre(1, 2, 7, 14));
    EXPECT_THAT(testFunc(15), UnorderedElementsAre(1, 3, 5, 15));
    EXPECT_THAT(testFunc(16), UnorderedElementsAre(1, 2, 4, 8, 16));
    EXPECT_THAT(testFunc(17), UnorderedElementsAre(1, 17));
    EXPECT_THAT(testFunc(18), UnorderedElementsAre(1, 2, 3, 6, 9, 18));
    EXPECT_THAT(testFunc(19), UnorderedElementsAre(1, 19));
    EXPECT_THAT(testFunc(20), UnorderedElementsAre(1, 2, 4, 5, 10, 20));
    EXPECT_THAT(testFunc(21), UnorderedElementsAre(1, 3, 7, 21));
    EXPECT_THAT(testFunc(22), UnorderedElementsAre(1, 2, 11, 22));
    EXPECT_THAT(testFunc(23), UnorderedElementsAre(1, 23));
    EXPECT_THAT(testFunc(24), UnorderedElementsAre(1, 2, 3, 4, 6, 8, 12, 24));
    EXPECT_THAT(testFunc(120), UnorderedElementsAre(
        1, 2, 3, 4, 5, 6, 8, 10, 12, 15, 20, 24, 30, 40, 60, 120));
}

TEST_F(Chap01Prob06Fixture, GetSumOfProperDivisors)
{
    IntDivisors divs;
    auto testFunc = [&divs](auto n) { return divs.GetSumOfProperDivisors(n); };
    EXPECT_EQ(divs.GetSumOfProperDivisors(1), 0);
    EXPECT_EQ(divs.GetSumOfProperDivisors(2), 1);
    EXPECT_EQ(divs.GetSumOfProperDivisors(3), 1);
    EXPECT_EQ(divs.GetSumOfProperDivisors(4), 3);
    EXPECT_EQ(divs.GetSumOfProperDivisors(5), 1);
    EXPECT_EQ(divs.GetSumOfProperDivisors(6), 6);
    EXPECT_EQ(divs.GetSumOfProperDivisors(7), 1);
    EXPECT_EQ(divs.GetSumOfProperDivisors(8), 7);
    EXPECT_EQ(divs.GetSumOfProperDivisors(9), 4);
    EXPECT_EQ(divs.GetSumOfProperDivisors(10), 8);
    EXPECT_EQ(divs.GetSumOfProperDivisors(12), 16);
    EXPECT_EQ(divs.GetSumOfProperDivisors(14), 10);
    EXPECT_EQ(divs.GetSumOfProperDivisors(15), 9);
    EXPECT_EQ(divs.GetSumOfProperDivisors(16), 15);
    EXPECT_EQ(divs.GetSumOfProperDivisors(18), 21);
    EXPECT_EQ(divs.GetSumOfProperDivisors(20), 22);
    EXPECT_EQ(divs.GetSumOfProperDivisors(21), 11);
    EXPECT_EQ(divs.GetSumOfProperDivisors(22), 14);
    EXPECT_EQ(divs.GetSumOfProperDivisors(24), 36);
    EXPECT_EQ(divs.GetSumOfProperDivisors(120), 240);
}

TEST_F(Chap01Prob06Fixture, AbundantNumbersUpTo)
{
    EXPECT_THAT(AbundantNumbersUpTo(0), IsEmpty());
    EXPECT_THAT(AbundantNumbersUpTo(5), IsEmpty());
    EXPECT_THAT(AbundantNumbersUpTo(10), IsEmpty());
    EXPECT_THAT(AbundantNumbersUpTo(12), IsEmpty());
    EXPECT_THAT(AbundantNumbersUpTo(13), ElementsAre(12));
    EXPECT_THAT(AbundantNumbersUpTo(17), ElementsAre(12));
    EXPECT_THAT(AbundantNumbersUpTo(18), ElementsAre(12));
    EXPECT_THAT(AbundantNumbersUpTo(19), ElementsAre(12, 18));
    EXPECT_THAT(AbundantNumbersUpTo(20), ElementsAre(12, 18));
    EXPECT_THAT(AbundantNumbersUpTo(21), ElementsAre(12, 18, 20));
    EXPECT_THAT(AbundantNumbersUpTo(121), ElementsAre(
        12, 18, 20, 24, 30, 36, 40, 42, 48, 54, 56, 60, 66, 70, 72, 78, 80, 
        84, 88, 90, 96, 100, 102, 104, 108, 112, 114, 120));
    EXPECT_THAT(AbundantNumbersUpTo(272), ElementsAre(
        12, 18, 20, 24, 30, 36, 40, 42, 48, 54, 56, 60, 66, 70, 72, 78, 80,
        84, 88, 90, 96, 100, 102, 104, 108, 112, 114, 120, 126, 132, 138, 140,
        144, 150, 156, 160, 162, 168, 174, 176, 180, 186, 192, 196, 198, 200,
        204, 208, 210, 216, 220, 222, 224, 228, 234, 240, 246, 252, 258, 260,
        264, 270));
}
