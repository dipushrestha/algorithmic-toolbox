#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

double get_optimal_value(int capacity, std::vector<int> weights, std::vector<int> values)
{
    double value = 0.0;

    std::vector<double> value_per_weights(weights.size());

    for (int i = 0; i < weights.size(); ++i)
    {
        value_per_weights[i] = values[i] / (double)weights[i];
    }

    std::sort(value_per_weights.begin(), value_per_weights.end());

    return value;
}

int main()
{
    int n;
    int capacity;

    std::cin >> n >> capacity;
    std::vector<int> values(n);
    std::vector<int> weights(n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> values[i] >> weights[i];
    }

    double optimal_value = get_optimal_value(capacity, weights, values);

    std::cout.precision(10);
    std::cout << optimal_value << std::endl;

    return 0;
}
