/*In order to find the optimal partitioning of the segment [3,n] into two parts with equal load in each stream, you can use the integral sum method.

Let f(x) be the function specifying the load on the interval [3,n]. 

Then the integral of f(x) on the interval [3,n] is equal to the total load on this interval. 

Divide this segment into two parts [3,m] and [m,n]. 

Then the integral of f(x) on the interval [3,m] will be equal to the load on the first part, and the integral of f(x) on the interval [m,n] will be equal to the load on the second part.

So we need to find a number m such that the integral of f(x) on the interval [3,m] is equal to half of the integral of f(x) on the interval [3,n]. 

To do this, you can use a numerical integration method, such as the trapezoidal method or Simpson's method.

After finding such a number m, we can divide the segment [3,n] into two parts [3,m] and [m,n], and the load on each of these parts will be equal to half of the total load on the segment [3,n].

Thus, the optimal partition of the segment [3,n] into two parts with equal load in each of the two streams is the partition into two parts [3,m] and [m,n], where the number m is found so that the integral of the load function on the segment [3,m] 

is equal to half of the integral of the load function on the segment [3,n].
*/
#include <iostream>
#include <cmath>
#include <omp.h>


using namespace std;

// function to check the number for simplicity
bool prime(int num) { 
    // if the number is less than or equal to 1, it is not prime
    if (num <= 1) {
        return false;
    }
    int limit = sqrt(num); // find the maximal divisor of a number
    // go through all possible divisors
    for (int i = 2; i <= limit; ++i) { 
        if (num % i == 0) {
            return false;
        }
    }
    return true; // if all possible divisors are greater than the maximal one, then the number is prime
}

// function for counting the number of prime numbers between 1 and n
int prime_numbers(int n) {
    int count = 1; 
#pragma omp parallel for reduction(+: count)
    for (int i = 3; i <= n; i += 2) {
        if (prime(i)) { // check the number for simplicity
            ++count;
        }
    }
    return count;
}


int main() {
    int n = 10000000;
    double t1 = omp_get_wtime();
    int count = prime_numbers(n);
    double t2 = omp_get_wtime();
    cout << "Number of primes between 1 and " << n << " is " << count << endl;
    cout << "Elapsed time: " << t2 - t1 << " seconds." << endl;
    return 0;
}