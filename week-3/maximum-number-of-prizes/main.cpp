#include <iostream>
#include <vector>

std::vector<int> optimal_summands(int n)
{
    std::vector<int> summands;

    int current_sum = 0;
    int remaining_sum = n;

    for (int i = 1; i <= n; i++)
    {
        current_sum = i * (i + 1) / 2;
        if (current_sum > remaining_sum)
        {
            summands.push_back(remaining_sum + i);
            break;
        }

        summands.push_back(i);
        remaining_sum -= i;
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
}
