#include <omp.h>
#include <iostream>
#include <vector>

using namespace std;

// Функция быстрой сортировки
void quicksort(vector<int>& arr, int left, int right) {
    if (left < right) {
        // Выбираем опорный элемент
        int pivot = arr[(left + right) / 2];
        // Разбиваем массив на две части
        int i = left - 1;
        int j = right + 1;
        while (true) {
            do {
                i++;
            } while (arr[i] < pivot);
            do {
                j--;
            } while (arr[j] > pivot);
            if (i >= j) {
                break;
            }
            // Обмен значениями
            swap(arr[i], arr[j]);
        }
        // Рекурсивный вызов функции для каждой части массива
#pragma omp task
        quicksort(arr, left, j);
#pragma omp task
        quicksort(arr, j + 1, right);
    }
}

int main() {
    // Исходный массив
    vector<int> arr = { 5, 4, 3, 2, 1 };
    // Создаем группу потоков OpenMP
#pragma omp parallel
// Гарантируем, что быстрая сортировка будет выполнена только одним потоком
#pragma omp single
    quicksort(arr, 0, arr.size() - 1);
    // Выводим отсортированный массив
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
/*В этой реализации директива #pragma omp parallel создает группу потоков OpenMP, 
а #pragma omp single гарантирует, что алгоритм быстрой сортировки будет выполнен только одним потоком. 
Внутри функции quicksort директива #pragma omp task создает задачи для рекурсивных вызовов функции quicksort, 
которые могут быть выполнены независимо друг от друга.
*/