#include "OptionData.hpp"

int main()
{

	OptionData myData;

	myData.K = 100.0;
	myData.T = 1.0;
	myData.r = 0.12;
	myData.sig = 0.1;
	myData.D = 0.03;
	myData.beta = 0.1;
	myData.type = +1;

	print(myData);

	print2(&myData);

	return 0;
}
