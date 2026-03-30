#include <iostream>
using namespace std;

// Preprocessor directives
#define NX 4
#define NY 3

typedef double Vector[NX];
typedef double NumericMatrix[NX][NY];

double innerProduct(Vector v1, Vector v2)
{
	double result = v1[0]*v2[0];
	for (int j = 1; j < NX; ++j)
	{
		result += v1[j]*v2[j];
	}
	return result;
}

void print(NumericMatrix m)
{
	for (int i = 0; i < NX; ++i)
	{
		cout << endl << "(";
		for (int j = 0; j < NY; ++j)
		{
			cout << m[i][j] << ",";
		}
		cout << ")";
	}
	cout << endl;
}

int main()
{
	Vector v1, v2;
	for (int i = 0; i < NX; ++i)
	{
		v1[i] = i;
		v2[i] = NX - i;
	}
	cout << "Inner product: " << innerProduct(v1, v2) << endl;
	NumericMatrix m1, m2, result;
	for (int i = 0; i < NX; ++i)
	{
		for (int j = 0; j < NY; ++j)
		{
			m1[i][j] = i; m2[i][j] = j;
			result[i][j] = m1[i][j] + m2[i][j];
		}
	}
	print(m1); print(m2); print(result);
	return 0;
}
