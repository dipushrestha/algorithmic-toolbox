#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cassert>
#include <random>

int get_majority_element(std::vector<int> &a, int left, int right)
{
    if (left == right)
        return -1;

    if (left + 1 == right)
        return a[left];

    int left_element = get_majority_element(a, left, (left + right - 1) / 2 + 1);
    int right_element = get_majority_element(a, (left + right - 1) / 2 + 1, right);

    int left_count = 0;

    for (int i = left; i < right; i++)
    {
        if (a[i] == left_element)
            left_count++;
    }

    if (left_count > (right - left) / 2)
        return left_element;

    int right_count = 0;

    for (int i = left; i < right; i++)
    {
        if (a[i] == right_element)
            right_count++;
    }

    if (right_count > (right - left) / 2)
        return right_element;

    return -1;
}

void test()
{

    while (true)
    {
        int n = rand() % 100000 + 1;

        std::vector<int> vec(100000);

        for (int i = 0; i < vec.size(); i++)
        {
            if (vec.size() / 2 < i)
            {
                vec[i] = 1;
            }
            else
            {
                vec[i] = rand() % 1000000000;
            }
        }

        auto rng = std::default_random_engine{};

        std::shuffle(vec.begin(), vec.end(), rng);

        assert(get_majority_element(vec, 0, n) == 0);

        std::cout << "Test passed for n = " << n << '\n';
    }
}

int main()
{
    test();
    return 0;
}
