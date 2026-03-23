#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
    return x * x;
}

int main() {
    double a, b;
    int n;
    int method;
    cout << "Enter lower limit (a): ";
    cin >> a;
    cout << "Enter upper limit (b): ";
    cin >> b;
    cout << "Enter number of subintervals (n): ";
    cin >> n;

    cout << "Choose method: 1 = Left, 2 = Right, 3 = Midpoint: ";
    cin >> method;

    double dx = (b - a) / n;
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        double x;
        if (method == 1) {
            x = a + i * dx;
        } else if (method == 2) {
            x = a + (i + 1) * dx;
        } else {
            x = a + (i + 0.5) * dx;
        }
        sum += f(x);
    }
    double result = sum * dx;
    cout << "Approximate integral = " << result << endl;
    return 0;
}