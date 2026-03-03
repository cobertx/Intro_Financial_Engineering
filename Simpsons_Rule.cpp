#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double f(double x) {
    return (1.0 / sqrt(2.0 * M_PI)) * exp(-x * x / 2.0);
}

// Simpson's rule
double simpson(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    
    for (int i = 1; i < n; i += 2)
        sum += 4 * f(a + i * h);
    for (int i = 2; i < n; i += 2)
        sum += 2 * f(a + i * h);
    
    return sum * h / 3.0;
}

double N(double t, int n) {
    return 0.5 + simpson(0, t, n);
}

int main() {
    cout << fixed << setprecision(12);
    double t_values[] = {0.1, 0.5, 1.0};
    int n_values[] = {64, 512, 1024};
    for (int i = 0; i < 3; i++) {
        cout << "N(" << t_values[i] << ") = " 
             << N(t_values[i], n_values[i]) << endl;
    }
    return 0;
}