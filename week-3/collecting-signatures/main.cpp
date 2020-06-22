#include <iostream>
#include <vector>
#include <algorithm>

struct Segment
{
    int start, end;
};

bool compare_segment(Segment a, Segment b)
{
    return a.end < b.end;
}

std::vector<int> optimal_points(std::vector<Segment> &segments)
{
    std::vector<int> points;
    std::sort(segments.begin(), segments.end(), compare_segment);

    int last_point = 0;
    points.push_back(segments[last_point].end);

    for (int current_point = 1; current_point < segments.size(); current_point++)
    {
        if (segments[current_point].start > segments[last_point].end)
        {
            points.push_back(segments[current_point].end);
            last_point = current_point;
        }
    }

    return points;
}

int main()
{
    int n;

    std::cin >> n;
    std::vector<Segment> segments(n);

    for (int i = 0; i < n; ++i)
    {
        std::cin >> segments[i].start >> segments[i].end;
    }

    std::vector<int> points = optimal_points(segments);
    std::cout << points.size() << "\n";

    for (int i = 0; i < points.size(); ++i)
    {
        std::cout << points[i] << " ";
    }

    std::cout << '\n';

    return 0;
}
