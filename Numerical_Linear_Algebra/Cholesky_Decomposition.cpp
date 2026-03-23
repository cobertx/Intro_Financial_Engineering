#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>

using Matrix = std::vector<std::vector<double>>;

Matrix choleskyDecomposition(const Matrix& A) {
    int n = A.size();
    for (const auto& row : A) {
        if ((int)row.size() != n) {
            throw std::invalid_argument("Matrix must be square.");
        }
    }

    Matrix L(n, std::vector<double>(n, 0.0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            double sum = 0.0;

            for (int k = 0; k < j; ++k) {
                sum += L[i][k] * L[j][k];
            }
            if (i == j) {
                double value = A[i][i] - sum;
                if (value <= 0.0) {
                    throw std::runtime_error("Matrix is not positive definite.");
                L[i][j] = std::sqrt(value);
            } else {
                L[i][j] = (A[i][j] - sum) / L[j][j];
        }   }
    }
    return L;
    }
}

void printMatrix(const Matrix& M) {
    for (const auto& row : M) {
        for (double val : row) {
            std::cout << val << " ";
        }
        std::cout << '\n';
    }
}

int main() {
    Matrix A = {
        {4, 12, -16},
        {12, 37, -43},
        {-16, -43, 98}
    };
    try {
        Matrix L = choleskyDecomposition(A);

        std::cout << "Lower triangular matrix L:\n";
        printMatrix(L);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
    return 0;
}