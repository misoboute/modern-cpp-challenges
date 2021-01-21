#include "PrimeNumbers.h"

namespace modcppchal
{
namespace math
{

thread_local std::vector<PrimeNumbers::IntT> PrimeNumbers::m_Primes { 
    2, 3, 5, 7 };
 
}
}
