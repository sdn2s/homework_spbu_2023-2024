#include <iostream>
#include <cmath>
#include <omp.h>

// ����������� ��������������� �������
double f(double x) {
    return std::sin(x);
}

// ������� ��� ���������� ��������� �� ����� ������� � ������� ������� ��������
// n - ���������� �������� ���������
double trapezoidal(double a, double b, double n) {
    double h = (b - a) / n;
    double sum = 0.5 * (f(a) + f(b));

    // ���������� OpenMP ��� ������������ ����������
#pragma omp parallel for reduction(+:sum)
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += f(x);
    }

    return h * sum;
}

// ������� ��� ���������� ��������� �� ������� [a, b] � ������� ������� �������� � OpenMP task
double integr(double a, double b) {
    const int n = 10; // ���������� �������� ���������
    double h = (b - a) / n;
    double sum = trapezoidal(a, b, n);

    // ���������� ��������� taskgroup ��� ����������� �������
#pragma omp taskgroup
    {
#pragma omp task shared(sum)
        sum += trapezoidal(a, a + h, n / 2);

#pragma omp task shared(sum)
        sum += trapezoidal(a + h, a + 2 * h, n / 2);

#pragma omp task shared(sum)
        sum += trapezoidal(a + 2 * h, a + 3 * h, n / 2);

#pragma omp task shared(sum)
        sum += trapezoidal(a + 3 * h, a + 4 * h, n / 2);

#pragma omp task shared(sum)
        sum += trapezoidal(a + 4 * h, a + 5 * h, n / 2);

#pragma omp task shared(sum)
        sum += trapezoidal(a + 5 * h, a + 6 * h, n / 2);

#pragma omp task shared(sum)
        sum += trapezoidal(a + 6 * h, a + 7 * h, n / 2);

#pragma omp task shared(sum)
        sum += trapezoidal(a + 7 * h, a + 8 * h, n / 2);

#pragma omp task shared(sum)
        sum += trapezoidal(a + 8 * h, a + 9 * h, n / 2);

#pragma omp task shared(sum)
        sum += trapezoidal(a + 9 * h, b, n / 2);
    }

    return sum;
}

int main() {
    const double PI = acos(-1.0);
    double a = 0.0;
    double b = PI;

    double result = integr(a, b);
    std::cout << "Result: " << result << std::endl;

    return 0;
}