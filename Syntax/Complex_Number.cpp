#include <iostream>
#include <complex>
using namespace std;

int main() {
    complex<double> z1(3.0, 4.0); 
    complex<double> z2(1.0, -2.0); 
    complex<double> sum = z1 + z2;
    complex<double> diff = z1 - z2;
    complex<double> prod = z1 * z2;
    complex<double> quot = z1 / z2;
    double mag = abs(z1);
    complex<double> conj_z1 = conj(z1);
    cout << "z1 = " << z1 << endl;
    cout << "z2 = " << z2 << endl;

    cout << "\nAddition: " << sum << endl;
    cout << "Subtraction: " << diff << endl;
    cout << "Multiplication: " << prod << endl;
    cout << "Division: " << quot << endl;

    cout << "\nMagnitude of z1: " << mag << endl;
    cout << "Conjugate of z1: " << conj_z1 << endl;

    return 0;
}