#include <iostream>
#include <cmath>
#include <cassert>

int fibonacci_sum_naive(long long n)
{
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current = 1;
    long long sum = 1;

    for (long long i = 0; i < n - 1; ++i)
    {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

int fibonacci_sum_fast(long long n)
{
    if (n <= 1)
        return n;

    int previous_number = 0;
    int current_number = 1;
    int pisano_period = n % 60;
    int next_number = 0;

    for (int i = 0; i <= pisano_period; ++i)
    {
        next_number = (previous_number + current_number) % 60;
        previous_number = current_number;
        current_number = next_number;
    }

    return current_number == 0 ? 9 : (current_number - 1) % 10;
}

void test_solution()
{
    for (int i = 0; i < 100; ++i)
    {
        int fibonacci_fast = fibonacci_sum_fast(i);
        int fibonacci_naive = fibonacci_sum_naive(i);
        std::cout << "Testing.... Sum(" << i << ") ==> "
                  << "Fast result: " << fibonacci_fast << ", Slow result: " << fibonacci_naive << '\n';
        assert(fibonacci_fast == fibonacci_naive);
        //std::cout << "Test passed for N: " << i << '\n';
    }

    std::cout << "All test passed. \n";
}

int main()
{
    long long n = 0;
    //std::cin >> n;

    //std::cout << fibonacci_sum_fast(100) << '\n';
    test_solution();
    // std::cout << fibonacci_sum_naive(n) << '\n';

    return 0;
}
