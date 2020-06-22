#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

bool compare_digits(std::string a, std::string b)
{
    return a + b > b + a;
}

std::string largest_number(std::vector<std::string> a)
{
    std::stringstream ret;
    std::sort(a.begin(), a.end(), compare_digits);

    for (size_t i = 0; i < a.size(); i++)
    {
        ret << a[i];
    }

    std::string result;
    ret >> result;

    return result;
}

int main()
{
    int n;

    std::cin >> n;
    std::vector<std::string> a(n);

    for (size_t i = 0; i < a.size(); i++)
    {
        std::cin >> a[i];
    }

    std::cout << largest_number(a) << '\n';

    return 0;
}
