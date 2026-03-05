#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

void pivotRows(vector<vector<double>>& A, int k) {
    int n = A.size();
    int pivotRow = k;
    double maxVal = fabs(A[k][k]);
    for (int i = k + 1; i < n; i++) {
        if (fabs(A[i][k]) > maxVal) {
            maxVal = fabs(A[i][k]);
            pivotRow = i;
        }
    }
    if (pivotRow != k) {
        swap(A[k], A[pivotRow]);
    }
}

void printMatrix(const vector<vector<double>>& A) {
    for (const auto& row : A) {
        for (double val : row)
            cout << val << " ";
        cout << endl;
    }
}

int main() {
    vector<vector<double>> A = {
        {2, 3, 1},
        {9, 1, 5},
        {4, 7, 6}
    };
    cout << "Matrix before pivoting:\n";
    printMatrix(A);
    int k = 0;  // pivot column
    pivotRows(A, k);
    cout << "\nMatrix after pivoting (column 0):\n";
    printMatrix(A);
    return 0;
}