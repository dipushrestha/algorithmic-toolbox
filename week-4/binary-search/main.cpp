#include <iostream>
#include <vector>

int binary_search(const std::vector<int> &a, int x)
{
    int left = 0, right = (int)a.size() - 1;

    while (right > left)
    {
        int mid = a[left] + (right - left) / 2 - 1;

        if (x == a[mid])
            return mid;

        else if (x < a[mid])
            right = mid - 1;

        else
            left = mid + 1;
    }

    return -1;
}

int main()
{
    int n;

    std::cin >> n;
    std::vector<int> a(n);

    for (size_t i = 0; i < a.size(); i++)
    {
        std::cin >> a[i];
    }

    int m;

    std::cin >> m;
    std::vector<int> b(m);

    for (int i = 0; i < m; ++i)
    {
        std::cin >> b[i];
    }

    for (int i = 0; i < m; ++i)
    {
        std::cout << binary_search(a, b[i]) << ' ';
    }

    std::cout << '\n';

    return 0;
}