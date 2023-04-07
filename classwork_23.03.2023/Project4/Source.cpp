/*This code defines a Point struct to represent a point in three-dimensional space and provides two functions:

dist function calculates the Euclidean distance between two points in three-dimensional space using the Pythagorean theorem. 

It takes two parameters p1 and p2 of type const Point& (const reference to a Point struct) and returns a double value.

diameter function calculates the maximum distance between any two points in a given vector of Point structs. 

It takes a parameter points of type const std::vector<Point>& (const reference to a vector of Point structs) 

and returns a double value representing the diameter of the given set of points.

The diameter function computes the maximum distance between any two points in the vector by comparing the distance between 

each pair of points and keeping track of the maximum distance seen so far.

Overall, this code provides a simple implementation to calculate the diameter of a set of points in three-dimensional space.
*/


#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct Point
{
    double x, y, z;
};


double dist(const Point& p1, const Point& p2)
{
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    double dz = p1.z - p2.z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}


double diameter(const vector<Point>& points)
{
    double max_dist = 0.0;
    for (size_t i = 0; i < points.size(); ++i) {
        for (size_t j = i + 1; j < points.size(); ++j) {
            double d = dist(points[i], points[j]);
            if (d > max_dist) {
                max_dist = d;
            }
        }
    }
    return max_dist;
}

int main()
{
    vector<Point> points = { {0.0, 0.0, 0.0}, {1.0, 1.0, 1.0}, {2.0, 2.0, 2.0}, {3.0, 3.0, 3.0} };
    double d = diameter(points);
    cout << "The diameter of the point set is: " << d << endl;
    return 0;
}