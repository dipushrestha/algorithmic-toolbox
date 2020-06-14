#include <iostream>
#include <vector>

long long get_fibonacci_huge_naive(long long n, long long m)
{
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current = 1;

    std::vector<int> numbers;

    numbers.push_back(0);
    numbers.push_back(1);

    for (long long i = 0; i < n - 1; ++i)
    {
        long long tmp_previous = previous;
        previous = current % m;
        current = (tmp_previous + current) % m;
        numbers.push_back(current);

        if (previous == 0 && current == 1)
            return numbers[n % (i + 1)];
    }

    return current;
}

int get_pisano_period(int n)
{
    int period = 0;
    int previous_number = 0;
    int current_number = 1;
    int next_number = 0;

    do
    {
        next_number = (previous_number + current_number) % n;
        previous_number = current_number;
        current_number = next_number;

        period++;

    } while (previous_number != 0 || current_number != 1);

    return period;
}

long long fibonacci(int n)
{
    if (n <= 1)
        return n;

    long long previous_number = 0;
    long long current_number = 1;
    long long next_number = 1;

    for (int i = 1; i < n; ++i)
    {
        previous_number = current_number;
        current_number = next_number;
        next_number = previous_number + current_number;
    }

    return current_number;
}

int get_fibonacci_huge_fast(long long n, long long m)
{
    int mod = n % get_pisano_period(m);
    std::cout << mod << "\n";
    return fibonacci(mod) % m;
}

int main()
{
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
