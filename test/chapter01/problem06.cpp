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

TEST_F(Chap01Prob06Fixture, FactorizeInteger)
{
    EXPECT_THAT(FactorizeInteger(0), IsEmpty());
    EXPECT_THAT(FactorizeInteger(1), 
        UnorderedElementsAre(std::make_pair(1, 1)));
    EXPECT_THAT(FactorizeInteger(2), 
        UnorderedElementsAre(std::make_pair(2, 1)));
    EXPECT_THAT(FactorizeInteger(3), 
        UnorderedElementsAre(std::make_pair(3, 1)));
    EXPECT_THAT(FactorizeInteger(4), 
        UnorderedElementsAre(std::make_pair(2, 2)));
    EXPECT_THAT(FactorizeInteger(5), 
        UnorderedElementsAre(std::make_pair(5, 1)));
    EXPECT_THAT(FactorizeInteger(6), 
        UnorderedElementsAre(std::make_pair(2, 1), std::make_pair(3, 1)));
    EXPECT_THAT(FactorizeInteger(16 * 27 * 25 * 49 * 13 * 289), 
        UnorderedElementsAre(std::make_pair(2, 4), std::make_pair(3, 3),
            std::make_pair(5, 2), std::make_pair(7, 2),
            std::make_pair(13, 1), std::make_pair(17, 2)));
}

TEST_F(Chap01Prob06Fixture, RecomputeIntegerFromFactors)
{
    using T = unsigned long long int;
    EXPECT_EQ(RecomputeIntegerFromFactors<T>({ {1, 1} }), 1);
    EXPECT_EQ(RecomputeIntegerFromFactors<T>({ {2, 1} }), 2);
    EXPECT_EQ(RecomputeIntegerFromFactors<T>({ {3, 1} }), 3);
    EXPECT_EQ(RecomputeIntegerFromFactors<T>({ {2, 2} }), 4);
    EXPECT_EQ(RecomputeIntegerFromFactors<T>({ {5, 1} }), 5);
    EXPECT_EQ(RecomputeIntegerFromFactors<T>({ {2, 1}, {3, 1} }), 6);
    EXPECT_EQ(RecomputeIntegerFromFactors<T>({ {2, 3} }), 8);
    EXPECT_EQ(RecomputeIntegerFromFactors<T>({ {2, 1}, {5, 1} }), 10);
    EXPECT_EQ(RecomputeIntegerFromFactors<T>(
        { {2, 4}, {3, 3}, {5, 2}, {7, 2}, {13, 1}, {17, 2} }), 
        16 * 27 * 25 * 49 * 13 * 289);
}

TEST_F(Chap01Prob06Fixture, IterateFactors)
{
    using T = unsigned long long int;
    using MapT = std::map<T, size_t>;
    using P = MapT::value_type;

    MapT noFactors, maxNoFactors;
    EXPECT_EQ(IterateFactors(noFactors, maxNoFactors), false);
    EXPECT_THAT(noFactors, IsEmpty());

    const MapT maxFactors { {2, 2}, {3, 2}, {5, 1} };
    MapT factors = maxFactors;

    EXPECT_EQ(IterateFactors(factors, maxFactors), true);
    EXPECT_THAT(factors, UnorderedElementsAre(P{2, 1}, P{3, 2}, P{5, 1}));

    EXPECT_EQ(IterateFactors(factors, maxFactors), true);
    EXPECT_THAT(factors, UnorderedElementsAre(P{2, 0}, P{3, 2}, P{5, 1}));

    EXPECT_EQ(IterateFactors(factors, maxFactors), true);
    EXPECT_THAT(factors, UnorderedElementsAre(P{2, 2}, P{3, 1}, P{5, 1}));

    EXPECT_EQ(IterateFactors(factors, maxFactors), true);
    EXPECT_THAT(factors, UnorderedElementsAre(P{2, 1}, P{3, 1}, P{5, 1}));

    EXPECT_EQ(IterateFactors(factors, maxFactors), true);
    EXPECT_THAT(factors, UnorderedElementsAre(P{2, 0}, P{3, 1}, P{5, 1}));

    EXPECT_EQ(IterateFactors(factors, maxFactors), true);
    EXPECT_THAT(factors, UnorderedElementsAre(P{2, 2}, P{3, 0}, P{5, 1}));

    EXPECT_EQ(IterateFactors(factors, maxFactors), true);
    EXPECT_THAT(factors, UnorderedElementsAre(P{2, 1}, P{3, 0}, P{5, 1}));

    EXPECT_EQ(IterateFactors(factors, maxFactors), true);
    EXPECT_THAT(factors, UnorderedElementsAre(P{2, 0}, P{3, 0}, P{5, 1}));

    EXPECT_EQ(IterateFactors(factors, maxFactors), true);
    EXPECT_THAT(factors, UnorderedElementsAre(P{2, 2}, P{3, 2}, P{5, 0}));

    EXPECT_EQ(IterateFactors(factors, maxFactors), true);
    EXPECT_THAT(factors, UnorderedElementsAre(P{2, 1}, P{3, 2}, P{5, 0}));

    EXPECT_EQ(IterateFactors(factors, maxFactors), true);
    EXPECT_THAT(factors, UnorderedElementsAre(P{2, 0}, P{3, 2}, P{5, 0}));

    EXPECT_EQ(IterateFactors(factors, maxFactors), true);
    EXPECT_THAT(factors, UnorderedElementsAre(P{2, 2}, P{3, 1}, P{5, 0}));

    EXPECT_EQ(IterateFactors(factors, maxFactors), true);
    EXPECT_THAT(factors, UnorderedElementsAre(P{2, 1}, P{3, 1}, P{5, 0}));

    EXPECT_EQ(IterateFactors(factors, maxFactors), true);
    EXPECT_THAT(factors, UnorderedElementsAre(P{2, 0}, P{3, 1}, P{5, 0}));

    EXPECT_EQ(IterateFactors(factors, maxFactors), true);
    EXPECT_THAT(factors, UnorderedElementsAre(P{2, 2}, P{3, 0}, P{5, 0}));

    EXPECT_EQ(IterateFactors(factors, maxFactors), true);
    EXPECT_THAT(factors, UnorderedElementsAre(P{2, 1}, P{3, 0}, P{5, 0}));

    EXPECT_EQ(IterateFactors(factors, maxFactors), true);
    EXPECT_THAT(factors, UnorderedElementsAre(P{2, 0}, P{3, 0}, P{5, 0}));

    EXPECT_EQ(IterateFactors(factors, maxFactors), false);
}

TEST_F(Chap01Prob06Fixture, ComputeAllDivisors)
{
    EXPECT_THAT(ComputeAllDivisors(0), IsEmpty());
    EXPECT_THAT(ComputeAllDivisors(1), UnorderedElementsAre(1));
    EXPECT_THAT(ComputeAllDivisors(2), UnorderedElementsAre(1, 2));
    EXPECT_THAT(ComputeAllDivisors(3), UnorderedElementsAre(1, 3));
    EXPECT_THAT(ComputeAllDivisors(4), UnorderedElementsAre(1, 2, 4));
    EXPECT_THAT(ComputeAllDivisors(5), UnorderedElementsAre(1, 5));
    EXPECT_THAT(ComputeAllDivisors(6), UnorderedElementsAre(1, 2, 3, 6));
    EXPECT_THAT(ComputeAllDivisors(7), UnorderedElementsAre(1, 7));
    EXPECT_THAT(ComputeAllDivisors(8), UnorderedElementsAre(1, 2, 4, 8));
    EXPECT_THAT(ComputeAllDivisors(9), UnorderedElementsAre(1, 3, 9));
    EXPECT_THAT(ComputeAllDivisors(10), UnorderedElementsAre(1, 2, 5, 10));
    EXPECT_THAT(ComputeAllDivisors(11), UnorderedElementsAre(1, 11));
    EXPECT_THAT(ComputeAllDivisors(12),
        UnorderedElementsAre(1, 2, 3, 4, 6, 12));
    EXPECT_THAT(ComputeAllDivisors(13), UnorderedElementsAre(1, 13));
    EXPECT_THAT(ComputeAllDivisors(14), UnorderedElementsAre(1, 2, 7, 14));
    EXPECT_THAT(ComputeAllDivisors(15), UnorderedElementsAre(1, 3, 5, 15));
    EXPECT_THAT(ComputeAllDivisors(16), UnorderedElementsAre(1, 2, 4, 8, 16));
    EXPECT_THAT(ComputeAllDivisors(17), UnorderedElementsAre(1, 17));
    EXPECT_THAT(ComputeAllDivisors(18), 
        UnorderedElementsAre(1, 2, 3, 6, 9, 18));
    EXPECT_THAT(ComputeAllDivisors(19), UnorderedElementsAre(1, 19));
    EXPECT_THAT(ComputeAllDivisors(20), 
        UnorderedElementsAre(1, 2, 4, 5, 10, 20));
    EXPECT_THAT(ComputeAllDivisors(21), UnorderedElementsAre(1, 3, 7, 21));
    EXPECT_THAT(ComputeAllDivisors(22), UnorderedElementsAre(1, 2, 11, 22));
    EXPECT_THAT(ComputeAllDivisors(23), UnorderedElementsAre(1, 23));
    EXPECT_THAT(ComputeAllDivisors(24), 
        UnorderedElementsAre(1, 2, 3, 4, 6, 8, 12, 24));
    EXPECT_THAT(ComputeAllDivisors(120), UnorderedElementsAre(
        1, 2, 3, 4, 5, 6, 8, 10, 12, 15, 20, 24, 30, 40, 60, 120));
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
        264, 270 ));
}
