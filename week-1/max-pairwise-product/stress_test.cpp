#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

long long MaxPairwiseProduct(const std::vector<int> &numbers)
{
    long long max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first)
    {
        for (int second = first + 1; second < n; ++second)
        {
            max_product = std::max(max_product, (long long)numbers[first] * numbers[second]);
        }
    }

    return max_product;
}

long long MaxPairwiseProductFast(const std::vector<int> &numbers)
{
    int max = 0;
    int second_max = 0;
    long long max_product = 0;
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
    while (true)
    {
        int n = rand() % 1000 + 2;
        std::cout << n << "\n";
        std::vector<int> a;

        for (int i = 0; i < n; i++)
        {
            a.push_back(std::rand() % 100000);
        }

        for (int i = 0; i < n; i++)
        {
            std::cout << a[i] << ' ';
        }

        std::cout << "\n";

        long long res1 = MaxPairwiseProduct(a);
        long long res2 = MaxPairwiseProductFast(a);

        if (res1 != res2)
        {
            std::cout << "Wrong answer: " << res1 << ' ' << res2 << "\n";
            break;
        }
        else
        {
            std::cout << "OK\n";
        }
    }

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
