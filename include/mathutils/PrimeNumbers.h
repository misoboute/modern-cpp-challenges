#pragma once

#include <cmath>
#include <cstdint>
#include <vector>

namespace modcppchal
{
namespace math
{

    class PrimeNumbers
    {
    public:
        using IntT = std::uintmax_t;
        
        IntT operator[](size_t idx)
        {
            if (idx >= m_Primes.size())
                GenerateUpTo(idx);
            return m_Primes[idx];
        }

        template <typename T>
        bool IsPrime(T num)
        {
            if (num < 2)
                return false;
            if (num == 2)
                return true;
            return IsPrimeImpl(num, *this);
        }

    private:
        void GenerateUpTo(size_t idx)
        {
            for (IntT num = m_Primes.back() + 2;
                 m_Primes.size() < idx + 1;
                 num += 2)
            {
                if (IsPrimeImpl(num, m_Primes))
                    m_Primes.push_back(num);
            }
        }

        template <typename SeqT, typename T>
        bool IsPrimeImpl(T num, SeqT& seq)
        {
            auto maxCheckVal = static_cast<IntT>(std::ceil(std::sqrt(num + 1)));
            for (size_t i = 0; seq[i] < maxCheckVal; ++i)
                if (num % seq[i] == 0)
                    return false;
            return true;
        }

        static thread_local std::vector<IntT> m_Primes;
    };

}
}
