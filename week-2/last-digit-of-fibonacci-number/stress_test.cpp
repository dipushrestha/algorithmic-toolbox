#include <iostream>
#include <cassert>

int get_fibonacci_last_digit_naive(int n)
{
    if (n <= 1)
        return n;

    unsigned long long previous = 0;
    unsigned long long current = 1;

    for (int i = 0; i < n - 1; ++i)
    {
        unsigned long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int get_fibonacci_last_digit_fast(int n)
{
    if (n <= 1)
        return n;

    int previous_number = 0;
    int current_number = 1;
    int next_number = 1;

    for (int i = 1; i < n; ++i)
    {
        previous_number = current_number;
        current_number = next_number;
        next_number = (previous_number + current_number) % 10;
    }

    return current_number;
}

void test_solution()
{
    assert(get_fibonacci_last_digit_naive(3) == 2);
    assert(get_fibonacci_last_digit_fast(10) == 5);

    for (int n = 0; n < 80; ++n)
        assert(get_fibonacci_last_digit_naive(n) == get_fibonacci_last_digit_fast(n));

    std::cout << "Test passed \n";
}

int main()
{
    int n;

    std::cin >> n;
    std::cout << get_fibonacci_last_digit_naive(n) << '\n';

    test_solution();

    std::cout << get_fibonacci_last_digit_naive(n) << '\n';

    return 0;
}
