#pragma once

#include <numeric>
#include <set>
#include <vector>

namespace modcppchal
{
namespace math
{

    class NarcissisticNumbers
    {
    public:
        using IntT = unsigned long long int;

        NarcissisticNumbers(size_t numDigits)
        : m_NumDigits(numDigits)
        {
            auto initNum = m_NumDigits > 1 ? Power(10, m_NumDigits - 1) : 0;
            m_Number = initNum;
            m_Digits.resize(m_NumDigits);
            m_RaisedDigits.resize(m_NumDigits);
            for (size_t i = 0; i < m_NumDigits; ++i)
            {
                SetDigit(i, initNum % 10);
                initNum /= 10;
            }
        }

        std::set<IntT> Compute()
        {
            std::set<IntT> result;
            while (IncrementNumber())
            {
                if (ComputeSumOfPowersOfDigits() == m_Number)
                    result.insert(result.cend(), m_Number);
            }
            return result;
        }

    private:
        static unsigned int Power(unsigned char value, size_t power)
        {
            unsigned int raised = 1;
            for (size_t i = 0; i < power; ++i)
                raised *= value;
            return raised;
        }

        IntT ComputeSumOfPowersOfDigits()
        {
            return std::accumulate(
                m_RaisedDigits.cbegin(), m_RaisedDigits.cend(), 0);
        }

        bool IncrementNumber()
        {
            ++m_Number;
            for (size_t dig = 0; dig < m_NumDigits;)
            {
                if (m_Digits[dig] < 9)
                {
                    IncrementDigit(dig);
                    return true;
                }
                else
                {
                    SetDigit(dig++, 0);
                }
            }
            return false;
        }

        void IncrementDigit(size_t dig)
        {
            m_RaisedDigits[dig] = Power(++m_Digits[dig], m_NumDigits);
        }

        void SetDigit(size_t dig, unsigned char value)
        {
            m_RaisedDigits[dig] = Power(m_Digits[dig] = value, m_NumDigits);
        }

        const size_t m_NumDigits;
        std::vector<unsigned char> m_Digits;
        std::vector<unsigned int> m_RaisedDigits;
        IntT m_Number;
    };

}
}
