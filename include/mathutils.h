#pragma once

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
    return 0;
}

}
}