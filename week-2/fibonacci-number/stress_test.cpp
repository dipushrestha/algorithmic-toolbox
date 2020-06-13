#include <iostream>
#include <cassert>

int fibonacci_naive(int n)
{
    if (n <= 1)
        return n;

    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

int fibonacci_fast(int n)
{
    int first_number = 0;
    int second_number = 1;

    if (n == 0)
        return first_number;

    if (n == 1)
        return second_number;

    int next_number = 0;

    for (int i = 2; i <= n; ++i)
    {
        next_number = first_number + second_number;
        first_number = second_number;
        second_number = next_number;
    }

    return next_number;
}

void test_solution()
{
    assert(fibonacci_fast(3) == 2);
    assert(fibonacci_fast(10) == 55);

    for (int n = 0; n < 20; ++n)
        assert(fibonacci_fast(n) == fibonacci_naive(n));
}

int main()
{
    int n = 0;
    std::cin >> n;

    std::cout << fibonacci_naive(n) << '\n';
    test_solution();
    std::cout << fibonacci_fast(n) << '\n';
    return 0;
}
