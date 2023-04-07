#include <iostream>
#include <cmath>
#include <vector>
#include <omp.h>

struct Point
{
    double x, y, z;
};

double dist(const Point& p1, const Point& p2)
{
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    double dz = p1.z - p2.z;
    return std::sqrt(dx * dx + dy * dy + dz * dz);
}

double diameter(const std::vector<Point>& points)
{
    double max_dist = 0.0;

#pragma omp parallel for num_threads(3)
    for (std::size_t i = 0; i < points.size(); ++i) {
        for (std::size_t j = i + 1; j < points.size(); ++j) {
            double d = dist(points[i], points[j]);

#pragma omp critical
            {
                if (d > max_dist) {
                    max_dist = d;
                }
            }
        }
    }

    return max_dist;
}

int main()
{
    std::vector<Point> points = { {0.0, 0.0, 0.0}, {1.0, 1.0, 1.0}, {2.0, 2.0, 2.0}, {3.0, 3.0, 3.0} };
    std::cout << "Diameter: " << diameter(points) << std::endl;
    return 0;
}