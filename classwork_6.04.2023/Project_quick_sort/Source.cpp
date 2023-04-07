#include <omp.h>
#include <iostream>
#include <vector>

using namespace std;

// ������� ������� ����������
void quicksort(vector<int>& arr, int left, int right) {
    if (left < right) {
        // �������� ������� �������
        int pivot = arr[(left + right) / 2];
        // ��������� ������ �� ��� �����
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
            // ����� ����������
            swap(arr[i], arr[j]);
        }
        // ����������� ����� ������� ��� ������ ����� �������
#pragma omp task
        quicksort(arr, left, j);
#pragma omp task
        quicksort(arr, j + 1, right);
    }
}

int main() {
    // �������� ������
    vector<int> arr = { 5, 4, 3, 2, 1 };
    // ������� ������ ������� OpenMP
#pragma omp parallel
// �����������, ��� ������� ���������� ����� ��������� ������ ����� �������
#pragma omp single
    quicksort(arr, 0, arr.size() - 1);
    // ������� ��������������� ������
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
/*� ���� ���������� ��������� #pragma omp parallel ������� ������ ������� OpenMP, 
� #pragma omp single �����������, ��� �������� ������� ���������� ����� �������� ������ ����� �������. 
������ ������� quicksort ��������� #pragma omp task ������� ������ ��� ����������� ������� ������� quicksort, 
������� ����� ���� ��������� ���������� ���� �� �����.
*/