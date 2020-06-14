#include <iostream>

int fibonacci(int n)
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
        next_number = previous_number + current_number;
    }

    return current_number;
}

int main()
{
    int n = 0;

    std::cin >> n;
    std::cout << fibonacci(n) << '\n';

    return 0;
}
