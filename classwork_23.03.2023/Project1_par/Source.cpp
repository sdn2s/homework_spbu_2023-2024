#include <iostream>
#include <cmath>
#include <omp.h>


using namespace std;


int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;


    double pi = 3.14159265358979323846;
    double step_size = pi / (2.0 * n);
    int num_steps = (int)(pi / 2.0 / step_size);

    // create an array and fill it with values of sines of angles
    double* sin_table = new double[num_steps];


#pragma omp parallel for
    for (int i = 0; i < num_steps; i++) {
        double angle = i * step_size;
        sin_table[i] = sin(angle); // calculate the sine value of the angle and write it into an array  
    }

    // output the resulting array
    cout << "Sine table: ";
    for (int i = 0; i < num_steps; i++) {
        cout << sin_table[i] << " ";
    }
    cout << endl;

    // освобождение памяти, занятой под массив
    delete[] sin_table;
    return 0;
}