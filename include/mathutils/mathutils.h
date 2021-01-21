#pragma once

#include <set>

#include "IntDivisors.h"
#include "PrimeNumbers.h"

namespace modcppchal
{
namespace math
{

template <typename T>
T CalcSumDiv3Div5(T n)
{
    const auto n3 = (n - 1) / 3, n5 = (n - 1) / 5;
    return (1 + n3) * n3 / 2 * 3 + (1 + n5) * n5 / 2 * 5;
}

template <typename T>
T GreatestCommonDivisor(T n, T m)
{
    if (n < m)
        std::swap(n, m);
    for (auto t = n % m; t != 0;)
    {
        n = m;
        m = t;
        t = n % m;
    }
    return m;
}

template <typename T>
T LeastCommonMultiple(T n, T m)
{
    const auto gcd = GreatestCommonDivisor(n, m);
    return gcd * n / gcd * m / gcd;
}

template <typename T>
T LargestPrimeThan(T n)
{
    PrimeNumbers primes;
    int i = 0;
    while (primes[i] < n) ++i;
    return primes[i > 0 ? i - 1 : 0];
}

template <typename T>
std::set< std::pair<T, T> > SexyPrimePairsUpTo(T n)
{
    PrimeNumbers primes;
    std::set< std::pair<T, T> > sexies;
    for (T i = 4; ; ++i)
    {
        const auto p = primes[i];
        if (p >= n)
            break;

        for (int j = i; j > i - 4; --j)
        {
            const auto q = primes[j];
            if (p - q == 6)
                sexies.emplace_hint(sexies.cend(), q, p);
                
        }
    }
    return sexies;
}

template <typename T>
std::set<T> AbundantNumbersUpTo(T n)
{
    std::set<T> result;
    IntDivisors divs;
    for (T i = 12; i < n; ++i)
    {
        if (divs.GetSumOfProperDivisors(i) > i)
            result.insert(result.cend(), i);
    }
    return result;
}

}
}