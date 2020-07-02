#include <iostream>
#include <vector>
#include <algorithm>

int get_majority_element(std::vector<int> &votes, int left, int right)
{
    if (left == right)
        return -1;

    if (left + 1 == right)
        return votes[left];

    int left_element = get_majority_element(votes, left, (left + right - 1) / 2 + 1);
    int right_element = get_majority_element(votes, (left + right - 1) / 2 + 1, right);

    int left_count = 0;

    for (int i = left; i < right; i++)
    {
        if (votes[i] == left_element)
            left_count++;
    }

    if (left_count > (right - left) / 2)
        return left_element;

    int right_count = 0;

    for (int i = left; i < right; i++)
    {
        if (votes[i] == right_element)
            right_count++;
    }

    if (right_count > (right - left) / 2)
        return right_element;

    return -1;
}

int main()
{
    int n;

    std::cin >> n;
    std::vector<int> votes(n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> votes[i];
    }

    std::cout << (get_majority_element(votes, 0, votes.size()) != -1) << '\n';

    return 0;
}