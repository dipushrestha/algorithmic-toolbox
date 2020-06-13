#include <iostream>

int fibonacci(int n)
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

int main()
{
    int n = 0;

    std::cin >> n;
    std::cout << fibonacci(n) << '\n';

    return 0;
}