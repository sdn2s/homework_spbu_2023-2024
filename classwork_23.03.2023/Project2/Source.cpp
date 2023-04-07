/*Here we add the directive #pragma omp parallel for before the loop 
to tell the compiler that we want to parallelize its iterations.
We also use the reduction(+:sum) directive 
to combine the results of all the threads' calculations into the sum variable.*/
#include <iostream>
#include <cmath>
#include <omp.h>
using namespace std;

int main() {
    int n;
    std::cout << "Enter n: ";
    std::cin >> n;


    double h = 1.0 / n;
    double x, y;
    double sum = 0.0;


#pragma omp parallel for reduction(+:sum)// parallel loop specifying the information operation
    for (int i = 0; i < n; ++i) {
        x = (i + 0.5) * h;
        y = 4.0 / (1.0 + x * x);
        sum += y;
    }


    double pi = h * sum;
    std::cout << "pi = " << pi << std::endl;


    return 0;
}