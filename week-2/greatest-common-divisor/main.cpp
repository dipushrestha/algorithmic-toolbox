#include <iostream>
#include <algorithm>

unsigned long gcd(unsigned long a, unsigned long b)
{
    unsigned long dividend = std::max(a, b);
    unsigned long divisor = std::min(a, b);
    unsigned long remainder = dividend % divisor;

    while (remainder != 0)
    {
        dividend = divisor;
        divisor = remainder;
        remainder = dividend % divisor;
    }

    return divisor;
}

int main()
{
    int a, b;

    std::cin >> a >> b;
    std::cout << gcd(a, b) << "\n";

    return 0;
}
