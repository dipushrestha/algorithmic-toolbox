#include <iostream>
#include <vector>

int get_fibonacci_mod(long long n, int m)
{
    if (n <= 1)
        return n;

    int previous = 0;
    int current = 1;

    std::vector<int> fib_mod_numbers;

    fib_mod_numbers.push_back(0);
    fib_mod_numbers.push_back(1);

    for (long long i = 1; i < n; ++i)
    {
        int tmp_previous = previous;
        previous = current % m;
        current = (tmp_previous + current) % m;

        fib_mod_numbers.push_back(current);

        if (previous == 0 && current == 1)
        {
            return fib_mod_numbers[n % i];
        }
    }

    return current;
}

int main()
{
    long long n;
    int m;

    std::cin >> n >> m;
    std::cout << get_fibonacci_mod(n, m) << '\n';

    return 0;
}