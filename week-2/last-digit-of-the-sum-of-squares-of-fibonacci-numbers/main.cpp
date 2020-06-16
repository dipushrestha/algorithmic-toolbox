#include <iostream>
#include <vector>

int fibonacci_square_sum_last_digit(long long n)
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
    long long n;

    std::cin >> n;
    std::cout << fibonacci_square_sum_last_digit(n) << '\n';

    return 0;
}