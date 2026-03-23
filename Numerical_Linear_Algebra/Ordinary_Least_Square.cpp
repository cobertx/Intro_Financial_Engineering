#include <iostream>
#include <vector>

using namespace std;

// Multiply matrices
vector<vector<double>> multiply(const vector<vector<double>>& A, const vector<vector<double>>& B) {
    int n = A.size(), m = B[0].size(), p = B.size();
    vector<vector<double>> result(n, vector<double>(m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int k = 0; k < p; k++)
                result[i][j] += A[i][k] * B[k][j];
    return result;
}

vector<vector<double>> transpose(const vector<vector<double>>& A) {
    int n = A.size(), m = A[0].size();
    vector<vector<double>> T(m, vector<double>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            T[j][i] = A[i][j];
    return T;
}

// Inverse of 2x2 matrix (simple case)
vector<vector<double>> inverse2x2(const vector<vector<double>>& A) {
    double det = A[0][0]*A[1][1] - A[0][1]*A[1][0];
    vector<vector<double>> inv(2, vector<double>(2));
    inv[0][0] = A[1][1] / det;
    inv[0][1] = -A[0][1] / det;
    inv[1][0] = -A[1][0] / det;
    inv[1][1] = A[0][0] / det;
    return inv;
}

void printMatrix(const vector<vector<double>>& A) {
    for (auto& row : A) {
        for (auto val : row)
            cout << val << " ";
        cout << endl;
    }
    cout << endl;
}

int main() {
    vector<vector<double>> X = {
        {1, 1},
        {1, 2},
        {1, 3}
    };
    vector<vector<double>> y = {
        {1},
        {2},
        {2}
    };

    auto Xt = transpose(X);
    auto XtX = multiply(Xt, X);
    auto XtX_inv = inverse2x2(XtX);
    auto Xty = multiply(Xt, y);
    auto beta = multiply(XtX_inv, Xty);
    cout << "Beta (coefficients):\n";
    printMatrix(beta);

    return 0;
}