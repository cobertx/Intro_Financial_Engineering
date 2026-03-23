#include <iostream>
#include <vector>
using namespace std;

vector<double> solveSystem(vector<vector<double>> A, vector<double> b) {
    int n = b.size();
    for(int i=0;i<n;i++) {
        double pivot = A[i][i];
        for(int j=i;j<n;j++)
            A[i][j] /= pivot;
        b[i] /= pivot;

        for(int k=i+1;k<n;k++) {
            double factor = A[k][i];
            for(int j=i;j<n;j++)
                A[k][j] -= factor*A[i][j];
            b[k] -= factor*b[i];
        }
    }
    vector<double> x(n);

    for(int i=n-1;i>=0;i--) {
        x[i] = b[i];
        for(int j=i+1;j<n;j++)
            x[i] -= A[i][j]*x[j];
    }
    return x;
}

int main() {
    vector<double> x = {0,1,2,3};
    vector<double> y = {1,3,2,5};

    int n = x.size()-1;
    vector<double> h(n);
    for(int i=0;i<n;i++)
        h[i] = x[i+1]-x[i];
    int N = n+1;
    vector<vector<double>> M_hat(N, vector<double>(N,0));
    vector<double> b_hat(N,0);
    M_hat[0][0] = 1;
    M_hat[n][n] = 1;
    for(int i=1;i<n;i++) {

        M_hat[i][i-1] = h[i-1];
        M_hat[i][i] = 2*(h[i-1]+h[i]);
        M_hat[i][i+1] = h[i];
        b_hat[i] = 3*((y[i+1]-y[i])/h[i] - (y[i]-y[i-1])/h[i-1]);
    }

    vector<double> c = solveSystem(M_hat,b_hat);
    vector<double> a(n), b(n), d(n);
    for(int i=0;i<n;i++) {
        a[i] = y[i];

        b[i] = (y[i+1]-y[i])/h[i] - h[i]*(2*c[i]+c[i+1])/3;

        d[i] = (c[i+1]-c[i])/(3*h[i]);
    }

    cout<<"Spline coefficients per interval:\n";

    for(int i=0;i<n;i++) {
        cout<<"Interval "<<i<<": ";
        cout<<"a="<<a[i]<<" ";
        cout<<"b="<<b[i]<<" ";
        cout<<"c="<<c[i]<<" ";
        cout<<"d="<<d[i]<<"\n";
    }
}