#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to)
{
    long long sum = 0;

    long long current = 0;
    long long next = 1;

    for (long long i = 0; i <= to; ++i)
    {
        if (i >= from)
        {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

int get_fibonacci_partial_sum_fast(long long from, long long to)
{
    int a = 0, b = 1, c = 0, fibonacci_partial_sum = 0;
    vector<int> last_digits = {a, b};

    for (int i = 2; i <= 60; ++i)
    {
        c = (a + b) % 10;
        a = b;
        b = c;

        last_digits.push_back(c);
    }

    from = from % 60;
    to = to % 60;
    to += from > to ? 0 : 60;

    for (int i = from; i <= to; ++i)
    {
        fibonacci_partial_sum += last_digits[i % 60];
    }

    return fibonacci_partial_sum % 10;
}

int main()
{
    long long from, to;

    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';

    return 0;
}
