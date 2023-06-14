/**********************************************************
** Program: lab2_hotel.cpp
** Authors: Patrick Liang, Jared Goddard
** Date: 01/13/2020
** Description: random number generator and if statements
***********************************************************/


#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	srand(time(NULL));
	int x;
	int hotel_floor = rand() % 6;
	cout << "your floor is " << hotel_floor << endl;
	if(hotel_floor == 0)
	{
		cout << "you are assigned to the ground floor." << endl;
	}
	else if(hotel_floor % 2 == 1)
	{
		cout << "you are assigned to an odd floor." << endl;
		if(hotel_floor == 5)
		{
			cout << "you are assigned to the penthouse." << endl;
		}
	} 
	else
	{
		cout << "you are assigned to an even floor." << endl;
	}

	return 0;
}
