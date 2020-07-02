#include <iostream>
#include <vector>
#include <cstdlib>

std::pair<int, int> partition3(std::vector<int> &a, int l, int r)
{
    int i = l;
    int j = l;
    int k = r;
    int x = a[l];

    while (i <= k)
    {
        if (a[i] < x)
            std::swap(a[i++], a[j++]);

        else if (a[i] == x)
            i++;

        else
            std::swap(a[i], a[k--]);
    }

    return std::make_pair(j, k);
}

void randomized_quick_sort(std::vector<int> &a, int l, int r)
{
    if (l >= r)
    {
        return;
    }

    int k = l + rand() % (r - l + 1);

    std::swap(a[l], a[k]);
    std::pair<int, int> m = partition3(a, l, r);

    randomized_quick_sort(a, l, m.first - 1);
    randomized_quick_sort(a, m.second + 1, r);
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> a(n);

    for (size_t i = 0; i < a.size(); ++i)
    {
        std::cin >> a[i];
    }

    randomized_quick_sort(a, 0, a.size() - 1);

    for (size_t i = 0; i < a.size(); ++i)
    {
        std::cout << a[i] << ' ';
    }

    std::cout << '\n';

    return 0;
}
