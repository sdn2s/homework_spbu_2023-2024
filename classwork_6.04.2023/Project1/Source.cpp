#include <iostream>
#include <cmath>
#include <future>

// ������� f ��������� 1/(1+x*x) � ���������� ���������
double f(double x) {
    // ������� ������ ��� ���������� 1/(1+x*x) � ��������� ������
    auto task = std::async(std::launch::async, [x] { return 1 / (1 + x * x); });
    // �������� ��������� ���������� �� ������� future, ���������� � �������
    return task.get();
}


int main() {
    // ������� �������� ��� ������� f
    double x = 2.0;
    // �������� ������� f � �������� ��������� ����������
    double result = f(x);
    
    std::cout << "f(" << x << ") = " << result << std::endl;
    
    return 0;
}
