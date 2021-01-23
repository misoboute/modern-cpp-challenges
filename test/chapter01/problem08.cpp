// Chapter 1 - 8. Armstrong numbers
// Write a program that prints all Armstrong numbers with three digits.

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "NarcissisticNumbers.h"

using testing::ElementsAre;
using testing::IsEmpty;
using testing::Test;

using namespace modcppchal::math;

struct Chap01Prob08Fixture : public Test
{
    Chap01Prob08Fixture()
    {
    }

    ~Chap01Prob08Fixture()
    {
    }
};

TEST_F(Chap01Prob08Fixture, ArmstrongNumbers)
{
    EXPECT_THAT(NarcissisticNumbers(1).Compute(), 
        ElementsAre(1, 2, 3, 4, 5, 6, 7, 8, 9));
    EXPECT_THAT(NarcissisticNumbers(3).Compute(), 
        ElementsAre(153, 370, 371, 407));
}
