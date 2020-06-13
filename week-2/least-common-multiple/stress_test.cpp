#include <iostream>
#include <algorithm>
#include <cassert>

long long lcm_naive(int a, int b)
{
    for (long l = 1; l <= (long long)a * b; ++l)
        if (l % a == 0 && l % b == 0)
            return l;

    return (long long)a * b;
}

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

long long lcm_fast(int a, int b)
{
    return ((long long)a * b) / (long long)gcd(a, b);
}

void test_solution()
{
    for (int n = 0; n < 10; ++n)
    {
        int a = rand() % 100000 + 1;
        int b = rand() % 100000 + 1;

        unsigned long naive_result = lcm_naive(a, b);
        unsigned long fast_result = lcm_fast(a, b);

        assert(fast_result == naive_result);

        std::cout << "Test Passed: LCM(" << a << ", " << b << ") = " << fast_result << "\n";
    }

    std::cout << "All test passed \n";
}

int main()
{
    int a, b;
    //std::cin >> a >> b;
    //std::cout << lcm_naive(a, b) << std::endl;

    test_solution();

    return 0;
}
