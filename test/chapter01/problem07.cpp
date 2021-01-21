// Chapter 1 - 7. Amicable numbers
// Write a program that prints the list of all pairs of amicable numbers 
// smaller than 1,000,000.

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "mathutils.h"

using testing::ElementsAre;
using testing::IsEmpty;
using testing::Test;
using testing::UnorderedElementsAre;

using namespace modcppchal::math;

struct Chap01Prob07Fixture : public Test
{
    Chap01Prob07Fixture()
    {
    }

    ~Chap01Prob07Fixture()
    {
    }
};

TEST_F(Chap01Prob07Fixture, FactorizeInteger)
{
    // EXPECT_THAT(FactorizeInteger(0), IsEmpty());
    // EXPECT_THAT(FactorizeInteger(1), 
    //     UnorderedElementsAre(std::make_pair(1, 1)));
    // EXPECT_THAT(FactorizeInteger(2), 
    //     UnorderedElementsAre(std::make_pair(2, 1)));
    // EXPECT_THAT(FactorizeInteger(3), 
    //     UnorderedElementsAre(std::make_pair(3, 1)));
    // EXPECT_THAT(FactorizeInteger(4), 
    //     UnorderedElementsAre(std::make_pair(2, 2)));
    // EXPECT_THAT(FactorizeInteger(5), 
    //     UnorderedElementsAre(std::make_pair(5, 1)));
    // EXPECT_THAT(FactorizeInteger(6), 
    //     UnorderedElementsAre(std::make_pair(2, 1), std::make_pair(3, 1)));
    // EXPECT_THAT(FactorizeInteger(16 * 27 * 25 * 49 * 13 * 289), 
    //     UnorderedElementsAre(std::make_pair(2, 4), std::make_pair(3, 3),
    //         std::make_pair(5, 2), std::make_pair(7, 2),
    //         std::make_pair(13, 1), std::make_pair(17, 2)));
}
