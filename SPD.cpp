#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const double EPS = 1e-9;

bool isSymmetric(const vector<vector<double>>& A) {
    int n = A.size();
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (abs(A[i][j] - A[j][i]) > EPS)
                return false;
    return true;
}

bool choleskyDecomposition(const vector<vector<double>>& A) {
    int n = A.size();
    vector<vector<double>> L(n, vector<double>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            double sum = 0;
            if (j == i) {
                for (int k = 0; k < j; k++)
                    sum += L[j][k] * L[j][k];
                L[j][j] = sqrt(A[j][j] - sum);
                if (L[j][j] <= EPS)
                    return false;
            } 
            else {
                for (int k = 0; k < j; k++)
                    sum += L[i][k] * L[j][k];
                L[i][j] = (A[i][j] - sum) / L[j][j];
            }
        }
    }
    return true;
}

int main() {
    int n;
    cout << "Enter matrix size: ";
    cin >> n;
    
    vector<vector<double>> A(n, vector<double>(n));
    cout << "Enter matrix elements:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];
    if (!isSymmetric(A)) {
        cout << "Not symmetric - neither SPD nor SPSD\n";
    }
    else if (choleskyDecomposition(A)) {
        cout << "Symmetric Positive Definite\n";
    }
    else {
        cout << "Symmetric but not Positive Definite\n";
    }
    return 0;
}