
#include <math.h>
#include <iostream>
using namespace std;

double f(double x)
{
	return exp(-x);
}

// Preprocessor directives; effectively global variables
#define TOL 1.0e-5
#define MAXITER 1000
#define PI 3.1415926

double ftp_I(double x_0)
{	
	double xcurrent;
	long counter = 0;

L1:
	xcurrent = f(x_0);
	if (counter >= MAXITER)
	{
		cout << "Max iterations exceeded, method not converging\n";
		return xcurrent;
	}
	if (fabs(xcurrent - x_0) >= TOL)
	{
		x_0 = xcurrent;
		counter++;
		goto L1;
	}
	cout << "Method I has converged in " << counter << " iterations\n";
	return xcurrent;
}


int main()
{
	// Input parameters
	double xInit = 0.5;
	cout << "Fixed point (method I) is: " << ftp_I(xInit) << endl;
	cout << MAXITER << endl;
	return 0;
}

	