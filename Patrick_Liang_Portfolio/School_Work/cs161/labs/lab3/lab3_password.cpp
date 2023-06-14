/**********************************************************
** Program: lab3_password.cpp
** Authors: Patrick Liang, Jared Goddard
** Date: 01/20/2020
** Description: make a random password generator
***********************************************************/

#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main()
{
	int length;
	int letters;
	int upperCase;
	srand(time(NULL));

	cout << "How many characters do you want your password to be?" << endl;
	cin >> length;

	if (length <= 0)
	{
		cout << "Your input is invalid" << endl;
		return 1;
	}

	cout << "How many letters(out of " << length << ")?" << endl;
	cin >> letters;

	int numbers = length - letters;

	if (letters == 0) //All numbers
	{
		cout << "Your program will contain no letters." << endl;
		cout << "Your random password is:";

		for (int i = 0; i < length; i++)
		{
			short digit = rand() % 9;
			cout << digit;
		}
		cout << "\n";

	}
	else if (letters >= 1 && letters <= length)//numbers and letters
	{
		cout << "How many upper-case letters(out of " << letters << ")?" << endl;
		cin >> upperCase;

		int lowerCase = letters - upperCase;

		if (upperCase < 0 || upperCase > letters)
		{
			cout << "Your input is invalid" << endl;
			return 1;
		}

		cout << "The rest of your letters (" << lowerCase << ") will be lowercase." << endl;
		cout << "The rest of your characters (" << numbers << ") will be numbers." << endl;
		
		cout << "Your random password is:";

		for (int i = 0; i < upperCase; i++)
		{
			short digit = rand() % 25;
			digit += 65;				
			cout << (char)digit;
		}
		for (int i = 0; i < lowerCase; i++)
		{
			short digit = rand() % 25;
			digit += 97;
			cout << (char)digit;
		}
		for (int i = 0; i < numbers; i++)
		{
			short digit = rand() % 9;
			cout << digit;
		}
		cout << "\n";
	}

	else
	{
		cout << "Your input is invalid" << endl;
		return 1;
	}

	return 0;
}
