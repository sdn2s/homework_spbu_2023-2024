#include <iostream>
#include <vector>
#include <cmath>
#include <thread>
#include <omp.h>

using namespace std;

struct Point { 
    double x, y, z;
};

//function for calculating the distance between two points in three-dimensional space
double dist(const Point& p1, const Point& p2) { 
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    double dz = p1.z - p2.z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}

//function for calculating the diameter of a set of points in three-dimensional space using a parallel implementation
double ParallelDiameter(const std::vector<Point>& points)
{
    double max_dist = 0.0;

    //open a parallel section of 4 threads
#pragma omp parallel for num_threads(4)
    for (size_t i = 0; i < points.size(); ++i)
    {
        for (size_t j = i + 1; j < points.size(); ++j) //go through all possible pairs of points
        {
            //calculate the distance between the current pair of points
            double d = dist(points[i], points[j]);
//open the critical section to access the common variable max_dist
#pragma omp critical
            if (d > max_dist)
            {
                max_dist = d;
            }
        }
    }
    return max_dist;
}

int main() {
    vector<Point> points{ {0.0, 0.0, 0.0}, {1.0, 1.0, 1.0}, {2.0, 2.0, 2.0}, {3.0, 3.0, 3.0} };
    cout << "Parallel diameter: " << ParallelDiameter(points) << endl;
    return 0;
}