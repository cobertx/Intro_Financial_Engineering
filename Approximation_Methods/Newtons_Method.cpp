#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
    return x*x*x - x - 2;
}

double df(double x) {
    return 3*x*x - 1;
}

int main() {
    double x0, x1;
    int iterations;

    cout << "Enter initial guess: ";
    cin >> x0;
    cout << "Enter number of iterations: ";
    cin >> iterations;
    for(int i = 1; i <= iterations; i++) {
        x1 = x0 - f(x0)/df(x0);
        x0 = x1;
    }
    cout << "Approximate root = " << x1 << endl;
    return 0;
}