#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>

long long eval(long long a, long long b, char op)
{
    if (op == '*')
    {
        return a * b;
    }
    else if (op == '+')
    {
        return a + b;
    }
    else if (op == '-')
    {
        return a - b;
    }
    else
    {
        assert(0);
    }
}
long long get_maximum_value(const std::string &exp)
{
    long n = exp.length() / 2 + 1;

    std::vector<std::vector<long>> m(n, std::vector<long>(n, 0));
    std::vector<std::vector<long>> M(n, std::vector<long>(n, 0));

    std::vector<long> numbers;
    std::vector<char> op;

    for (int i = 0; i < exp.size(); i++)
    {
        if (i % 2 == 0)
        {
            numbers.push_back((long)exp[i] - 48);
        }
        else
        {
            op.push_back(exp[i]);
        }
    }

    for (int i = 0; i < numbers.size(); i++)
    {
        m[i][i] = numbers[i];
        M[i][i] = numbers[i];
    }
    for (int s = 1; s < numbers.size(); s++)
    {
        for (int i = 0; i < numbers.size() - s; i++)
        {
            int j = i + s;

            long max_value = std::numeric_limits<long>::min();
            long min_value = std::numeric_limits<long>::max();

            for (int k = i; k <= j - 1; k++)
            {
                long a = eval(M[i][k], M[k + 1][j], op[k]);
                long b = eval(M[i][k], m[k + 1][j], op[k]);
                long c = eval(m[i][k], M[k + 1][j], op[k]);
                long d = eval(m[i][k], m[k + 1][j], op[k]);

                max_value = std::max(max_value, std::max(a, std::max(b, std::max(c, d))));
                min_value = std::min(min_value, std::min(a, std::min(b, std::min(c, d))));
            }

            std::pair<long, long> min_max;

            min_max.first = min_value;
            min_max.second = max_value;

            m[i][j] = min_max.first;
            M[i][j] = min_max.second;
        }
    }

    return M[0][numbers.size() - 1];
}

int main()
{
    std::string s;
    std::cin >> s;
    std::cout << get_maximum_value(s) << '\n';

    return 0;
}