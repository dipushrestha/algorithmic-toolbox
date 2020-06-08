#include <iostream>
#include <vector>
#include <algorithm>

long long MaxPairwiseProduct(const std::vector<int> &numbers)
{
    int max = 0;
    int second_max = 0;
    int n = numbers.size();

    for (int i = 0; i < n; ++i)
    {
        if (numbers[i] > max)
        {
            second_max = max;
            max = numbers[i];
        }
        else if (numbers[i] > second_max)
        {
            second_max = numbers[i];
        }
    }

    return (long long)max * second_max;
}

int main()
{
    int n;

    std::cin >> n;
    std::vector<int> numbers(n);

    for (int i = 0; i < n; ++i)
    {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";

    return 0;
}
