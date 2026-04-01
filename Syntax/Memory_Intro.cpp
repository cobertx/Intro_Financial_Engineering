#include <stdlib.h>
#include "OptionData.hpp"

int main()
{
	// Create a single object on the heap
	int n = 1;
	OptionData* myData = (OptionData*)malloc(n * sizeof(OptionData)); // cast void* to OptionData*
	(*myData).K = 300.0;
	(*myData).T = 1.0;
	(*myData).r = 0.12;
	(*myData).sig = 0.1;
	(*myData).D = 0.03;
	(*myData).beta = 0.1;
	(*myData).type = +1;
	print(*myData);
	n = 4;
	// OptionData* myDataArray = (OptionData*)malloc(n * sizeof(OptionData));
	OptionData * myDataArray = new OptionData[n];
	for (int j = 0; j < n; ++j)
	{
		myDataArray[j] = *myData;
		// Adjust the expiry
		myDataArray[j].T = double (j) + 0.5;
	}
	// another for loop for printing
	for (int j = 0; j < n; ++j)
	{
		print(myDataArray[j]);
	}
	// Deallocate memory
	free(myData);
//	free(myDataArray);
	delete [] myDataArray;
	//double d = 1/2;
	//cout << d;

	return 0;
}
