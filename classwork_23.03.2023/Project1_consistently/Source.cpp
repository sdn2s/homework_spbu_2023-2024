#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    const double pi = acos(-1.0);
    double step = pi / (2 * n);// iteration step calculation

    for (double x = 0; x <= pi / 2; x += step) {// loop from 0 to pi/2 with the specified step
        double sin_x = sin(x);// sin calculation
        cout << "sin(" << x << ") = " << sin_x << endl;
    }

    return 0;
}
