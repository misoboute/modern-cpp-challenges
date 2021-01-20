#pragma once

#include <numeric>
#include <set>

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
    PrimeNumbers<T> primes;
    int i = 0;
    while (primes[i] < n) ++i;
    return primes[i > 0 ? i - 1 : 0];
}

template <typename T>
std::set< std::pair<T, T> > SexyPrimePairsUpTo(T n)
{
    PrimeNumbers<T> primes;
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
std::map<T, size_t> FactorizeInteger(T num)
{
    std::map<T, size_t> result;

    if (num < 0)
        result[-1] = 1;
    else if (num < 1)
        return {};
    else if (num == 1)
        return { std::make_pair(1, 1) };

    PrimeNumbers<T> prime;
    for (size_t i = 0; prime[i] <= std::ceil(std::sqrt(num + 1));)
    {
        if (num % prime[i] == 0)
        {
            num /= prime[i];
            ++result[prime[i]];
        }
        else
            ++i;
    }
    if (num > 1)
        ++result[num];
    return result;

}

template <typename T>
T RecomputeIntegerFromFactors(const std::map<T, size_t>& factors)
{
    T result = 1;
    for (const auto f : factors)
        for (size_t i = 0; i < f.second; ++i)
            result *= f.first;
    return result;
}

template <typename T>
bool IterateFactors(
    std::map<T, size_t>& factors, const std::map<T, size_t>& maxFactors)
{
    for (auto& f : factors)
    {
        if (f.second > 0)
        {
            --f.second;
            for (auto& f2 : factors)
            {
                if (f.first == f2.first)
                    break;
                f2.second = maxFactors.at(f2.first);
            }
            return true;
        }
    }
    return false;
}

template <typename T>
std::set<T> ComputeAllDivisors(T num)
{
    std::set<T> result;
    if (num == 0)
        return result;

    const auto maxFactors = FactorizeInteger(num);
    auto factors = maxFactors; 
    do
    {
        result.insert(result.cbegin(), RecomputeIntegerFromFactors(factors));
    } while (IterateFactors(factors, maxFactors));
    return result;
}

template <typename T>
std::set<T> AbundantNumbersUpTo(T n)
{
    std::set<T> result;
    for (T i = 12; i < n; ++i)
    {
        auto divisors = ComputeAllDivisors(i);
        divisors.erase(i);
        const auto sumDivs = 
            std::accumulate(divisors.cbegin(), divisors.cend(), 0);
        if (sumDivs > i)
            result.insert(result.cend(), i);
    }

    return result;
}

}
}