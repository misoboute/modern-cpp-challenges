// Chapter 1 - 7. Amicable numbers
// Write a program that prints the list of all pairs of amicable numbers 
// smaller than 1,000,000.

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "mathutils.h"

using testing::ElementsAre;
using testing::IsEmpty;
using testing::Test;

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

TEST_F(Chap01Prob07Fixture, AmicablePairsUpTo)
{
    auto p = [](auto x, auto y) { return std::make_pair(x, y); };
    EXPECT_THAT(AmicablePairsUpTo(0), IsEmpty());
    EXPECT_THAT(AmicablePairsUpTo(4), IsEmpty());
    EXPECT_THAT(AmicablePairsUpTo(10), IsEmpty());
    EXPECT_THAT(AmicablePairsUpTo(100), IsEmpty());
    EXPECT_THAT(AmicablePairsUpTo(220), IsEmpty());
    EXPECT_THAT(AmicablePairsUpTo(221), IsEmpty());
    EXPECT_THAT(AmicablePairsUpTo(284), IsEmpty());
    EXPECT_THAT(AmicablePairsUpTo(285), ElementsAre(p(220, 284)));
    EXPECT_THAT(AmicablePairsUpTo(1184), ElementsAre(p(220, 284)));
    EXPECT_THAT(AmicablePairsUpTo(1185), ElementsAre(p(220, 284)));
    EXPECT_THAT(AmicablePairsUpTo(1210), ElementsAre(p(220, 284)));
    EXPECT_THAT(AmicablePairsUpTo(1211), ElementsAre(
        p(220, 284), p(1184, 1210)));
    EXPECT_THAT(AmicablePairsUpTo(3000), ElementsAre(
        p(220, 284), p(1184, 1210), p(2620, 2924)));
    EXPECT_THAT(AmicablePairsUpTo(6000), ElementsAre(
        p(220, 284), p(1184, 1210), p(2620, 2924), p(5020, 5564)));
    EXPECT_THAT(AmicablePairsUpTo(10000), ElementsAre(
        p(220, 284), p(1184, 1210), p(2620, 2924), p(5020, 5564), 
        p(6232, 6368)));
    EXPECT_THAT(AmicablePairsUpTo(100000), ElementsAre(
        p(220, 284), p(1184, 1210), p(2620, 2924), p(5020, 5564), 
        p(6232, 6368), p(10744, 10856), p(12285, 14595), p(17296, 18416), 
        p(63020, 76084), p(66928, 66992), p(67095, 71145), p(69615, 87633), 
        p(79750, 88730)));
    EXPECT_THAT(AmicablePairsUpTo(1000000), ElementsAre(
        p(220, 284), p(1184, 1210), p(2620, 2924), p(5020, 5564), 
        p(6232, 6368), p(10744, 10856), p(12285, 14595), p(17296, 18416), 
        p(63020, 76084), p(66928, 66992), p(67095, 71145), p(69615, 87633), 
        p(79750, 88730), p(100485, 124155), p(122265, 139815), 
        p(122368, 123152), p(141664, 153176), p(142310, 168730), 
        p(171856, 176336), p(176272, 180848), p(185368, 203432), 
        p(196724, 202444), p(280540, 365084), p(308620, 389924), 
        p(319550, 430402), p(356408, 399592), p(437456, 455344), 
        p(469028, 486178), p(503056, 514736), p(522405, 525915), 
        p(600392, 669688), p(609928, 686072), p(624184, 691256), 
        p(635624, 712216), p(643336, 652664), p(667964, 783556), 
        p(726104, 796696), p(802725, 863835), p(879712, 901424), 
        p(898216, 980984)));
}
