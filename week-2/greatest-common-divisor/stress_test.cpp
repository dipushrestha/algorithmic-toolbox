#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cassert>

unsigned long gcd_naive(unsigned long a, unsigned long b)
{
    unsigned current_gcd = 1;
    for (unsigned long d = 2; d <= a && d <= b; d++)
    {
        if (a % d == 0 && b % d == 0)
        {
            if (d > current_gcd)
            {
                current_gcd = d;
            }
        }
    }
    return current_gcd;
}

unsigned long gcd_fast(unsigned long a, unsigned long b)
{
    unsigned long larger_number = std::max(a, b);
    unsigned long smaller_number = std::min(a, b);
    unsigned long remainder = larger_number % smaller_number;

    while (remainder != 0)
    {
        larger_number = smaller_number;
        smaller_number = remainder;
        remainder = larger_number % smaller_number;
    }

    return smaller_number;
}

void test_solution()
{
    for (int n = 0; n < 1; ++n)
    {
        unsigned long a = rand() % 2000000000 + 1;
        unsigned long b = rand() % 2000000000 + 1;

        unsigned long naive_result = gcd_naive(a, b);
        unsigned long fast_result = gcd_fast(a, b);

        assert(fast_result == naive_result);

        std::cout << "Test Passed: GCD(" << a << ", " << b << ") = " << fast_result << "\n";
    }

    std::cout << "All test passed \n";
}

int main()
{
    unsigned long a, b;

    //std::cin >> a >> b;

    test_solution();

    //std::cout << gcd_naive(a, b) << std::endl;

    return 0;
}
