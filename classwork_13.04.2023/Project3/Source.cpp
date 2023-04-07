#include <iostream>
#include <vector>

using namespace std;

void transform(vector<vector<double>>& matrix) {
    int n = matrix.size(); // количество строк
    int m = matrix[0].size(); // количество столбцов

    for (int i = 0; i < n; i++) {
        // Если на диагонали стоит ноль, ищем строку с ненулевым элементом и меняем их местами
        if (matrix[i][i] == 0) {
            int j = i + 1;
            while (j < n && matrix[j][i] == 0) {
                j++;
            }
            if (j == n) {
                // Нет ненулевых элементов, пропускаем эту строку
                continue;
            }
            swap(matrix[i], matrix[j]);
        }
        // Делим строку на первый элемент, чтобы получить единицу на диагонали
        double divisor = matrix[i][i];
        for (int k = 0; k < m; k++) {
            matrix[i][k] /= divisor;
        }
        // Вычитаем текущую строку из остальных, чтобы получить нули под диагональю
        for (int j = i + 1; j < n; j++) {
            double factor = matrix[j][i];
            for (int k = 0; k < m; k++) {
                matrix[j][k] -= factor * matrix[i][k];
            }
        }
    }
}

int main() {
    vector<vector<double>> matrix = { {2, 4, 6}, {1, 0, -1}, {3, 5, 2} };
    transform(matrix);

    for (auto& row : matrix) {
        for (auto& elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }

    return 0;
}
