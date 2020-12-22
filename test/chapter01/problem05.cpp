// Chapter 1 - 5. Sexy prime pairs
// Write a program that prints all the sexy prime pairs up to a limit entered 
// by the user.

#include <gtest/gtest.h>

#include "mathutils.h"

using testing::Test;
using namespace modcppchal::math;

struct Chap01Prob05Fixture : public Test
{
    Chap01Prob05Fixture()
    {
    }

    ~Chap01Prob05Fixture()
    {
    }
};

TEST_F(Chap01Prob05Fixture, SexyPrimePairsUpTo)
{
    using SetT = std::invoke_result_t<decltype(SexyPrimePairsUpTo<int>), int>;

    EXPECT_TRUE(SexyPrimePairsUpTo(20) == (SetT{
        {5, 11}, {7, 13}, {11, 17}, {13, 19} }));

    EXPECT_TRUE(SexyPrimePairsUpTo(100) == (SetT{
        {5, 11}, {7, 13}, {11, 17}, {13, 19}, {17, 23}, {23, 29}, {31, 37}, 
        {37, 43}, {41, 47}, {47, 53}, {53, 59}, {61, 67}, {67, 73}, {73, 79}, 
        {83, 89} }));
}
