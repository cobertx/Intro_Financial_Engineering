#include <iostream>
#include <Eigen/Dense>
#include <Eigen/Cholesky>

using namespace Eigen;
using namespace std;

bool isSPD(const MatrixXd& A) {
    // Check symmetric
    if (!A.isApprox(A.transpose())) return false;
    
    // Check positive definite via Cholesky
    LLT<MatrixXd> llt(A);
    return llt.info() == Success;
}

int main() {
    // Your matrix
    MatrixXd A(4, 4);
    A << 3, -3, 1, 0,
         1, 2, 0, 0,
         -1, 2, 3, 0,
         0, 0, 0, 5;
    
    cout << "Matrix A:\n" << A << "\n\n";
    
    if (isSPD(A)) {
        cout << "✅ Matrix is symmetric positive definite\n";
    } else {
        cout << "❌ Matrix is NOT symmetric positive definite\n";
    }
    
    return 0;
}