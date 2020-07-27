#include <iostream>
#include <vector>

void print_vector(std::vector<int> &v)
{
    for (int a : v)
        std::cout << a << ' ';

    std::cout << '\n';
}

size_t merge_count(std::vector<int> &a, std::vector<int> &b, size_t left, size_t mid, size_t right)
{
    size_t left_index = left;
    size_t right_index = mid;
    size_t main_index = left;
    size_t inversions_count = 0;

    while (left_index < mid && right_index < right)
    {
        if (a[left_index] > a[right_index])
        {
            b[main_index++] = a[right_index++];
            inversions_count += mid - left_index;
        }
        else
        {
            b[main_index++] = a[left_index++];
        }
    }

    while (left_index < mid)
    {
        b[main_index++] = a[left_index++];
    }

    while (right_index < right)
    {
        b[main_index++] = a[right_index++];
    }

    a = b;

    return inversions_count;
}

size_t get_number_of_inversions(std::vector<int> &a, std::vector<int> &b, size_t left, size_t right)
{
    size_t number_of_inversions = 0;

    if (right <= left + 1)
        return number_of_inversions;

    size_t ave = left + (right - left) / 2;

    number_of_inversions += get_number_of_inversions(a, b, left, ave);
    number_of_inversions += get_number_of_inversions(a, b, ave, right);
    number_of_inversions += merge_count(a, b, left, ave, right);

    return number_of_inversions;
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

    std::vector<int> b(a.size());
    std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';

    print_vector(b);

    return 0;
}
