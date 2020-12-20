#pragma once

#include <cmath>
#include <vector>

namespace modcppchal
{
namespace math
{
    template <typename T>
    class PrimeNumbers
    {
    public:
        T operator[](size_t idx)
        {
            if (idx >= m_Primes.size())
                GenerateUpTo(idx);
            return m_Primes[idx];
        }

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
            for (T num = m_Primes.back() + 2;
                 m_Primes.size() < idx + 1;
                 num += 2)
            {
                if (IsPrimeImpl(num, m_Primes))
                    m_Primes.push_back(num);
            }
        }

        template <typename SeqT>
        bool IsPrimeImpl(T num, SeqT& seq)
        {
            auto maxCheckVal = static_cast<T>(std::ceil(std::sqrt(num + 1)));
            for (size_t i = 0; seq[i] < maxCheckVal; ++i)
                if (num % seq[i] == 0)
                    return false;
            return true;
        }

        std::vector<T> m_Primes { 2, 3, 5, 7 };
    };
}

}