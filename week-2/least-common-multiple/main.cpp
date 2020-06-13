#include <iostream>
#include <algorithm>

long long lcm(unsigned int a, unsigned int b)
{
    unsigned int dividend = std::max(a, b);
    unsigned int divisor = std::min(a, b);
    unsigned int remainder = dividend % divisor;

    while (remainder != 0)
    {
        dividend = divisor;
        divisor = remainder;
        remainder = dividend % divisor;
    }

    return ((long long)a * b) / (long long)divisor;
}

int main()
{
    unsigned int a, b;

    std::cin >> a >> b;
    std::cout << lcm(a, b) << '\n';

    return 0;
}