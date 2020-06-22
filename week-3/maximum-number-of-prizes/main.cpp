#include <iostream>
#include <vector>

std::vector<int> optimal_summands(int n)
{
    std::vector<int> summands;

    int current_sum = 0;

    if (n <= 2)
    {
        summands.push_back(n);

        return summands;
    }

    for (int i = 1; i <= n; i++)
    {
        current_sum = i * (i + 1) / 2;

        if (current_sum >= n - i)
        {
            summands.push_back(n + i - current_sum);
            break;
        }

        summands.push_back(i);
    }

    return summands;
}

int main()
{
    int n;

    std::cin >> n;
    std::vector<int> summands = optimal_summands(n);
    std::cout << summands.size() << '\n';

    for (size_t i = 0; i < summands.size(); ++i)
    {
        std::cout << summands[i] << ' ';
    }

    std::cout << '\n';

    return 0;
}
