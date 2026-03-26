#include <algorithm>
#include <iostream>
using namespace std;

long Fibonacci(long n)
{ // Recursive function
        if(n == 0)
		{
			return 0;
		}
		if(n == 1)
		{
			return 1;
		}
		return Fibonacci(n-1) + Fibonacci(n-2);
}


int main()
{
    int N = 40; // How many Fibonacci numbers to compute
	for (int n = 0; n < N; ++n)
	{ 
		cout << Fibonacci(n) << ",";
	}
    return 0;
}
