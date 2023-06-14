
/**********************************************************
** Program: lab2_values.cpp
** Authors: Patrick Liang, Jared Goddard
** Date: 01/13/2020
** Description: Calculate min/max values.
***********************************************************/





#include <iostream>
#include <cmath>

using namespace std;

int main() 
{

	int b;
	cout << "please enter the number of bits you want to use: " << endl;
	cin >> b;
	int maxsigned = pow(2, b-1) - 1;
	int mindigned = pow(2, b-1);
	int maxunsigned = pow(2, b) - 1;

	cout << "the maximum signed value is: " << maxsigned << endl;
	cout << "the minimum signed value is: -" << mindigned << endl;
	cout << "the maximum unsigned value is: " << maxunsigned << endl;

	return 0;
}