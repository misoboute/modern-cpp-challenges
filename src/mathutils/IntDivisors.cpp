#include "IntDivisors.h"

namespace modcppchal
{
namespace math
{

thread_local std::map<IntDivisors::IntT, IntDivisors::IntT> 
    IntDivisors::m_SumPropDivCache;
 
}
}
