#include <iostream>
#include <cmath>
#include <vector>

using namespace std;



struct Point
{
    double x, y, z;
};

// The function calculates the distance between two points in three-dimensional space
double dist(const Point& p1, const Point& p2)
{
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    double dz = p1.z - p2.z;
    return std::sqrt(dx * dx + dy * dy + dz * dz);
}

// The function calculates the diameter of a set of points in three-dimensional space
double diameter_parallel(const vector<Point>& points)
{
    double max_dist = 0.0;
#pragma omp parallel for
    for (size_t i = 0; i < points.size(); ++i) {
        for (size_t j = i + 1; j < points.size(); ++j) {
            double d = dist(points[i], points[j]);
            // Uses the critical section to update the maximum distance in safe multithreading mode
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
    vector<Point> points = { {0.0, 0.0, 0.0}, {1.0, 1.0, 1.0}, {2.0, 2.0, 2.0}, {3.0, 3.0, 3.0} };
    double d = diameter_parallel(points);
    cout << "The diameter of the point set is: " << d << endl;
    return 0;
}