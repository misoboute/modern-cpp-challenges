#pragma once

#include <map>
#include <numeric>
#include <set>

#include "PrimeNumbers.h"

namespace modcppchal
{
namespace math
{

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

    PrimeNumbers prime;
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

class IntDivisors
{
public:
    using IntT = std::uintmax_t;

    static std::set<IntT> ComputeProperDivisors(IntT num)
    {
        std::set<IntT> result;
        if (num <= 1)
            return result;

        const auto maxFactors = FactorizeInteger(num);
        auto factors = maxFactors; 
        while (IterateFactors(factors, maxFactors))
        {
            result.insert(
                result.cbegin(), RecomputeIntegerFromFactors(factors));
        } 
        return result;
    }

    static std::set<IntT> ComputeAllDivisors(IntT num)
    {
        auto result = ComputeProperDivisors(num);
        if (num > 0)
            result.insert(result.cend(), num);
        return result;
    }

    IntT GetSumOfProperDivisors(IntT num) const
    {
        auto find = m_SumPropDivCache.find(num);
        if (find != m_SumPropDivCache.cend())
            return find->second;
        auto divs = ComputeProperDivisors(num);
        auto sum = std::accumulate(divs.cbegin(), divs.cend(), 0);
        m_SumPropDivCache[num] = sum;
        return sum;
    }

    IntT GetSumOfAllDivisors(IntT num) const
    {
        return GetSumOfProperDivisors(num) + num;
    }

private:
    static IntT RecomputeIntegerFromFactors(
        const std::map<IntT, size_t>& factors)
    {
        IntT result = 1;
        for (const auto f : factors)
            for (size_t i = 0; i < f.second; ++i)
                result *= f.first;
        return result;
    }

    static bool IterateFactors(
        std::map<IntT, size_t>& factors,
        const std::map<IntT, size_t>& maxFactors)
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

    static thread_local std::map<IntT, IntT> m_SumPropDivCache;
};

}
}