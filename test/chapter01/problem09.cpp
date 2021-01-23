// Chapter 1 - 9. Prime factors of a number
// Write a program that prints the prime factors of a number entered by 
// the user.

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "IntDivisors.h"

using testing::IsEmpty;
using testing::Test;
using testing::UnorderedElementsAre;

using namespace modcppchal::math;

struct Chap01Prob09Fixture : public Test
{
    Chap01Prob09Fixture()
    {
    }

    ~Chap01Prob09Fixture()
    {
    }
};


TEST_F(Chap01Prob09Fixture, PrimeFactors)
{
    auto p = [](auto x, auto y) { return std::make_pair(x, y); };
    EXPECT_THAT(FactorizeInteger(0), IsEmpty());
    EXPECT_THAT(FactorizeInteger(1), UnorderedElementsAre(p(1, 1)));
    EXPECT_THAT(FactorizeInteger(2), UnorderedElementsAre(p(2, 1)));
    EXPECT_THAT(FactorizeInteger(3), UnorderedElementsAre(p(3, 1)));
    EXPECT_THAT(FactorizeInteger(4), UnorderedElementsAre(p(2, 2)));
    EXPECT_THAT(FactorizeInteger(5), UnorderedElementsAre(p(5, 1)));
    EXPECT_THAT(FactorizeInteger(6), UnorderedElementsAre(p(2, 1), p(3, 1)));
    EXPECT_THAT(FactorizeInteger(16 * 27 * 25 * 49 * 13 * 289), 
        UnorderedElementsAre(
            p(2, 4), p(3, 3), p(5, 2), p(7, 2), p(13, 1), p(17, 2)));
}
