#include <iostream>
using namespace std;

long long factorial(int n) {
    long long result = 1;
    for(int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

double expTaylor(double x, int terms) {
    double sum = 0.0;
    for(int n = 0; n < terms; n++) {
        double term = 1.0;
        for(int i = 0; i < n; i++) {
            term *= x;
        }
        term /= factorial(n);
        sum += term;
    }
    return sum;
}

int main() {
    double x;
    int terms;
    cout << "Enter value of x: ";
    cin >> x;
    cout << "Enter number of terms: ";
    cin >> terms;
    double result = expTaylor(x, terms);
    cout << "Approximation of e^" << x << " = " << result << endl;
    return 0;
}