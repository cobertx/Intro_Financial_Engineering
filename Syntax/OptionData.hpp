#ifndef OptionData_HPP
#define OptionData_HPP
#include <iostream>
using namespace std;

// Encapsulate all data in one place
struct OptionData
{ 
	double K;
	double T;
	double r;
	double sig;
	double D;
	double beta;
	int type;

};

void print (OptionData data)
{ 
	cout << "Strike: " << data.K << endl;
	cout << "Expiry: " << data.T << endl;
	cout << "Interest: " << data.r << endl;
	cout << "Volatility: " << data.sig << endl;
	cout << "Dividend: " << data.D << endl;
	cout << "Elasticity factor (beta): " << data.beta << endl;
	cout << "Call +1 or Put -1: " << data.type << endl;
}

void print2 (struct OptionData* data) 
{ 
	cout << "Strike: " << data->K << endl;
	cout << "Expiry: " << data->T << endl;
    cout << "Interest: " << data->r << endl;
	cout << "Volatility: " << data->sig << endl;
	cout << "Dividend: " << data->D << endl;
	cout << "Elasticity factor (beta): " << data->beta << endl;
	cout << "Call +1 or Put -1: " << data->type << endl;
}



#endif