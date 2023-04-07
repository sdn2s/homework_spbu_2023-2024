#include <iostream>

using namespace std;

void divide(double** matrix, int row, double coefficient) {
    // �������� ���������� �������� � �������
    int columns = sizeof(matrix[row]) / sizeof(double);

    // ����� ������ ������� ������ �� �����������
    for (int j = 0; j < columns; j++) {
        matrix[row][j] /= coefficient;
    }
}

int main() {
    // ������� ������� 3x3
    double** matrix = new double* [3];
    for (int i = 0; i < 3; i++) {
        matrix[i] = new double[3];
    }

    // ��������� ������� ����������
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix[i][j] = i * j + 1;
        }
    }

    // ������� ������� �� �����
    cout << "�������� �������:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    // ����� ������ ������ ������� �� 2
    divide(matrix, 1, 2);

    // ������� ���������� ������� �� �����
    cout << "������� ����� ������� ������ ������ �� 2:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    // ����������� ������, ������� ��������
    for (int i = 0; i < 3; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
