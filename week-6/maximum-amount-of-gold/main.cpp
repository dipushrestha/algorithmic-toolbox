#include <iostream>
#include <vector>

int optimal_weight(int W, const std::vector<int> &weights)
{
    std::vector<std::vector<int>> value(weights.size() + 1, std::vector<int>(W + 1, 0));

    for (size_t i = 1; i <= weights.size(); i++)
    {
        for (int w = 1; w <= W; w++)
        {
            value[i][w] = value[i - 1][w];

            if (weights[i - 1] <= w)
            {
                int val = value[i - 1][w - weights[i - 1]] + weights[i - 1];

                if (value[i][w] < val)
                {
                    value[i][w] = val;
                }
            }
        }
    }

    return value[weights.size()][W];
}

int main()
{
    int n, W;

    std::cin >> W >> n;
    std::vector<int> weights(n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> weights[i];
    }

    std::cout << optimal_weight(W, weights) << '\n';

    return 0;
}