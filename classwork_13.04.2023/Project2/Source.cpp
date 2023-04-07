#include <iostream>
using namespace std;

const int ROWS = 3;
const int COLS = 3;

// This function takes a 2D array, two row indices and a coefficient as input
// The function subtracts the product of arr[row1][i] and the coefficient from each element of arr[row2][i] for i=0 to COLS-1
void subtract(double arr[][COLS], int row1, int row2, double coeff) {
    for (int i = 0; i < COLS; i++) {
        arr[row2][i] -= arr[row1][i] * coeff;
    }
}

int main() {
    // Define and initialize a 2D array "arr" of size ROWS x COLS
    double arr[ROWS][COLS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Define variables row1, row2 and coeff
    int row1 = 0;
    int row2 = 2;
    double coeff = 2.5;

    // Call the subtract function with input parameters arr, row1, row2 and coeff
    subtract(arr, row1, row2, coeff);

    // Print the modified 2D array arr
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
