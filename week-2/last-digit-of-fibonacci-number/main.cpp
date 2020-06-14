#include <iostream>

int get_fibonacci_last_digit(int n)
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

int main()
{
    int n = 0;

    std::cin >> n;
    std::cout << get_fibonacci_last_digit(n) << "\n";

    return 0;
}
