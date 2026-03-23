#include <iostream>
#include <vector>
using namespace std;

// Super simple backward substitution
vector<double> backwardSubSimple(vector<vector<double>> U, vector<double> b) {
    int n = U.size();
    vector<double> x(n);
    // Start from the last row and go up to the first
    for (int i = n - 1; i >= 0; i--) {
        double sum = 0;
        // Sum all the terms we already know (columns to the right)
        for (int j = i + 1; j < n; j++) {
            sum += U[i][j] * x[j];
        }
        // Solve for x[i]
        x[i] = (b[i] - sum) / U[i][i];
    }
    return x;
}

int main() {
    // Simple example
    vector<vector<double>> U = {
        {2, 1, 1},
        {0, 3, 2},
        {0, 0, 4}
    };
    vector<double> b = {7, 13, 12};
    vector<double> x = backwardSubSimple(U, b);
    cout << "Solution: ";
    for (double val : x) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}