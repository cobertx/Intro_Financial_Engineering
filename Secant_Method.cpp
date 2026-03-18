#include <iostream>
#include <cmath>
using namespace std;

// Define the function f(x)
double f(double x) {
    return x*x*x - x - 2;
}

int main() {
    double x0, x1, x2;
    int max_iter;
    double tolerance;
    cout << "Enter first guess (x0): ";
    cin >> x0;
    cout << "Enter second guess (x1): ";
    cin >> x1;
    cout << "Enter tolerance: ";
    cin >> tolerance;
    cout << "Enter maximum iterations: ";
    cin >> max_iter;

    for (int i = 0; i < max_iter; i++) {
        if (fabs(f(x1) - f(x0)) < 1e-10) {
            cout << "Division by zero error.\n";
            return 0;
        }
        x2 = x1 - (f(x1) * (x1 - x0)) / (f(x1) - f(x0));
        cout << "Iteration " << i + 1 << ": x = " << x2 << endl;
        if (fabs(x2 - x1) < tolerance) {
            cout << "\nRoot found: " << x2 << endl;
            return 0;
        }
        x0 = x1;
        x1 = x2;
    }
    cout << "\nApproximate root after " << max_iter << " iterations: " << x2 << endl;

    return 0;
}