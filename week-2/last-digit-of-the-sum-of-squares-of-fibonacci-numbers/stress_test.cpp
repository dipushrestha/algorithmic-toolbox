#include <iostream>

int fibonacci_sum_squares_naive(long long n)
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
        sum += current * current;
    }

    return sum % 10;
}

int fibonacci_sum_squares_fast(long long n)
{
    if (n <= 1)
        return n;

    long long previous_number = 0;
    long long current_number = 1;
    long long next_number = 0;
    long long pisano_period_rem = n % 60;

    for (long long i = 1; i <= pisano_period_rem; ++i)
    {
        next_number = (previous_number + current_number) % 60;
        previous_number = current_number;
        current_number = next_number;
    }

    return ((previous_number % 10) * (current_number % 10)) % 10;
}

int main()
{
    long long n = 0;

    std::cin >> n;
    std::cout << fibonacci_sum_squares_naive(n) << '\n';
    std::cout << fibonacci_sum_squares_fast(n) << '\n';

    return 0;
}
