#include <iostream>
#include <vector>

int compute_min_refills(int dist, int tank, std::vector<int> &stops)
{
    int refills = 0;
    int current_stop = 0;

    stops.insert(stops.begin(), current_stop);
    stops.push_back(dist);

    int stops_count = stops.size();

    while (current_stop <= stops_count)
    {
        int last_stop = current_stop;

        while (current_stop <= stops_count && stops[current_stop + 1] - stops[last_stop] <= tank)
        {
            current_stop++;
        }

        if (current_stop == last_stop)
            return -1;

        if (current_stop <= stops_count)
            refills++;
    }

    return refills;
}

int main()
{
    int d = 0;
    int m = 0;
    int n = 0;

    std::cin >> d;
    std::cin >> m;
    std::cin >> n;
    std::vector<int> stops(n);

    for (size_t i = 0; i < n; ++i)
        std::cin >> stops.at(i);

    std::cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
