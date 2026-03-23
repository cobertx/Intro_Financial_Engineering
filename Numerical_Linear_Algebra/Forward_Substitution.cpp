#include <iostream>
#include <vector>
using namespace std;

// Super simple forward substitution
vector<double> forwardSubSimple(vector<vector<double>> L, vector<double> b) {
    int n = L.size();
    vector<double> x(n);
    // For each row from top to bottom
    for (int i = 0; i < n; i++) {
        double sum = 0;
        // Sum all the terms we already know
        for (int j = 0; j < i; j++) {
            sum += L[i][j] * x[j];
        }
        // Solve for x[i]
        x[i] = (b[i] - sum) / L[i][i];
    }
    return x;
}

int main() {
    vector<vector<double>> L = {
        {4, 0, 0},
        {3, 5, 0},
        {2, 1, 6}
    };
    vector<double> b = {8, 19, 21};
    vector<double> x = forwardSubSimple(L, b);
    cout << "Solution: ";
    for (double val : x) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}