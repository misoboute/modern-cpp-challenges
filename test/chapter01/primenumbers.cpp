#include <gtest/gtest.h>

#include "PrimeNumbers.h"

using testing::Test;
using namespace modcppchal::math;

struct PrimeNumbersFixture : public Test
{
    PrimeNumbersFixture()
    {
    }

    ~PrimeNumbersFixture()
    {
    }

    PrimeNumbers m_Primes;
};

TEST_F(PrimeNumbersFixture, IsPrimeReturnFalseForAllNegatives)
{
    EXPECT_EQ(m_Primes.IsPrime(-1), false);
    EXPECT_EQ(m_Primes.IsPrime(-2), false);
    EXPECT_EQ(m_Primes.IsPrime(-3), false);
    EXPECT_EQ(m_Primes.IsPrime(-4), false);
    EXPECT_EQ(m_Primes.IsPrime(-5), false);
    EXPECT_EQ(m_Primes.IsPrime(-6), false);
    EXPECT_EQ(m_Primes.IsPrime(-7), false);
    EXPECT_EQ(m_Primes.IsPrime(-1000000), false);
}

TEST_F(PrimeNumbersFixture, IsPrimeReturnsFalseForZeroAndOne)
{
    EXPECT_EQ(m_Primes.IsPrime(0), false);
    EXPECT_EQ(m_Primes.IsPrime(1), false);
}

TEST_F(PrimeNumbersFixture, IsPrimeReturnsTrueFor2_3_5_7)
{
    EXPECT_EQ(m_Primes.IsPrime(2), true);
    EXPECT_EQ(m_Primes.IsPrime(3), true);
    EXPECT_EQ(m_Primes.IsPrime(5), true);
    EXPECT_EQ(m_Primes.IsPrime(7), true);
}

TEST_F(PrimeNumbersFixture, IsPrimeReturnsTrueForPrimeNumbers)
{
    EXPECT_EQ(m_Primes.IsPrime(11), true);
    EXPECT_EQ(m_Primes.IsPrime(13), true);
    EXPECT_EQ(m_Primes.IsPrime(17), true);
    EXPECT_EQ(m_Primes.IsPrime(19), true);
    EXPECT_EQ(m_Primes.IsPrime(23), true);
    EXPECT_EQ(m_Primes.IsPrime(29), true);
    EXPECT_EQ(m_Primes.IsPrime(31), true);
    EXPECT_EQ(m_Primes.IsPrime(37), true);
    EXPECT_EQ(m_Primes.IsPrime(43), true);
    EXPECT_EQ(m_Primes.IsPrime(47), true);
    EXPECT_EQ(m_Primes.IsPrime(53), true);
    EXPECT_EQ(m_Primes.IsPrime(61), true);
    EXPECT_EQ(m_Primes.IsPrime(67), true);
    EXPECT_EQ(m_Primes.IsPrime(71), true);
    EXPECT_EQ(m_Primes.IsPrime(73), true);
    EXPECT_EQ(m_Primes.IsPrime(79), true);
    EXPECT_EQ(m_Primes.IsPrime(83), true);
    EXPECT_EQ(m_Primes.IsPrime(89), true);
    EXPECT_EQ(m_Primes.IsPrime(97), true);
    EXPECT_EQ(m_Primes.IsPrime(10007), true);
}

TEST_F(PrimeNumbersFixture, IsPrimeReturnsFalseFor4_6_8_9)
{
    EXPECT_EQ(m_Primes.IsPrime(4), false);
    EXPECT_EQ(m_Primes.IsPrime(6), false);
    EXPECT_EQ(m_Primes.IsPrime(8), false);
    EXPECT_EQ(m_Primes.IsPrime(9), false);
}

TEST_F(PrimeNumbersFixture, IsPrimeReturnsFalseForSomeNonPrimes)
{
    EXPECT_EQ(m_Primes.IsPrime(10), false);
    EXPECT_EQ(m_Primes.IsPrime(12), false);
    EXPECT_EQ(m_Primes.IsPrime(14), false);
    EXPECT_EQ(m_Primes.IsPrime(15), false);
    EXPECT_EQ(m_Primes.IsPrime(16), false);
    EXPECT_EQ(m_Primes.IsPrime(20), false);
    EXPECT_EQ(m_Primes.IsPrime(25), false);
    EXPECT_EQ(m_Primes.IsPrime(888), false);
}

TEST_F(PrimeNumbersFixture, IndexedPrimeNumbers)
{
    EXPECT_EQ(m_Primes[0], 2);
    EXPECT_EQ(m_Primes[1], 3);
    EXPECT_EQ(m_Primes[2], 5);
    EXPECT_EQ(m_Primes[3], 7);
    EXPECT_EQ(m_Primes[4], 11);
    EXPECT_EQ(m_Primes[5], 13);
    EXPECT_EQ(m_Primes[6], 17);
    EXPECT_EQ(m_Primes[7], 19);
    EXPECT_EQ(m_Primes[8], 23);
    EXPECT_EQ(m_Primes[9], 29);
    EXPECT_EQ(m_Primes[10], 31);
    EXPECT_EQ(m_Primes[14], 47);
    EXPECT_EQ(m_Primes[22], 83);
    EXPECT_EQ(m_Primes[29], 113);
    EXPECT_EQ(m_Primes[168], 1009);
}
