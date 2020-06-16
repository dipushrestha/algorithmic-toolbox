#include <iostream>
#include <cmath>
#include <vector>

int fibonacci_partial_sum_last_digit(long long m, long long n)
{
    int a = 0, b = 1, c = 0, fibonacci_partial_sum = 0;
    std::vector<int> last_digits = {a, b};

    for (int i = 2; i <= 60; ++i)
    {
        c = (a + b) % 10;
        a = b;
        b = c;

        last_digits.push_back(c);
    }

    m = m % 60;
    n = n % 60;
    n += m > n ? 60 : 0;

    for (int i = m; i <= n; ++i)
    {
        fibonacci_partial_sum += last_digits[i % 60];
    }

    return fibonacci_partial_sum % 10;
}

int main()
{
    long long m, n;

    std::cin >> m >> n;
    std::cout << fibonacci_partial_sum_last_digit(m, n) << '\n';

    return 0;
}