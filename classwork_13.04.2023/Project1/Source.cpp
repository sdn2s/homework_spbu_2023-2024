#include <iostream>

using namespace std;

void divide(double** matrix, int row, double coefficient) {
    // Получаем количество столбцов в матрице
    int columns = sizeof(matrix[row]) / sizeof(double);

    // Делим каждый элемент строки на коэффициент
    for (int j = 0; j < columns; j++) {
        matrix[row][j] /= coefficient;
    }
}

int main() {
    // Создаем матрицу 3x3
    double** matrix = new double* [3];
    for (int i = 0; i < 3; i++) {
        matrix[i] = new double[3];
    }

    // Заполняем матрицу значениями
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix[i][j] = i * j + 1;
        }
    }

    // Выводим матрицу на экран
    cout << "Исходная матрица:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    // Делим вторую строку матрицы на 2
    divide(matrix, 1, 2);

    // Выводим измененную матрицу на экран
    cout << "Матрица после деления второй строки на 2:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    // Освобождаем память, занятую матрицей
    for (int i = 0; i < 3; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
