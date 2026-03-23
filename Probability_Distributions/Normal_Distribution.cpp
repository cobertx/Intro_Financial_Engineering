#include <iostream>
#include <random>
#include <cmath>
#include <iomanip>

using namespace std;

const double PI = 3.14159265358979323846;
const double SQRT2 = 1.41421356237309504880;

double normalCDF(double x) {
    return 0.5 * (1.0 + erf(x / SQRT2));
}
double generateNormal(double mean = 0.0, double stddev = 1.0) {
    static random_device rd;
    static mt19937 gen(rd());
    static normal_distribution<> dist(0.0, 1.0);
    
    return mean + stddev * dist(gen);
}

int main() {
    int choice;
    
    cout << "Normal Distribution CDF Calculator\n";
    cout << "==================================\n\n";
    cout << "1. Calculate CDF for a value\n";
    cout << "2. Generate random numbers and calculate CDF\n";
    cout << "Choice: ";
    cin >> choice;
    
    if (choice == 1) {
        double x;
        cout << "Enter x: ";
        cin >> x;
        cout << "CDF(" << x << ") = " << fixed << setprecision(6) << normalCDF(x) << "\n";
        cout << "P(X > " << x << ") = " << 1.0 - normalCDF(x) << "\n";
    }
    else {
        int n;
        double mean, stddev;
        cout << "Enter number of samples: ";
        cin >> n;
        cout << "Enter mean: ";
        cin >> mean;
        cout << "Enter standard deviation: ";
        cin >> stddev;
        cout << "\nGenerated values with CDF:\n";
        cout << setw(10) << "Value" << setw(15) << "CDF" << "\n";
        cout << string(25, '-') << "\n";
        for (int i = 0; i < n; i++) {
            double val = generateNormal(mean, stddev);
            double z = (val - mean) / stddev;
            double cdf = normalCDF(z); 
            cout << setw(10) << fixed << setprecision(4) << val 
                 << setw(15) << setprecision(6) << cdf << "\n";
        }
    }
    
    return 0;
}