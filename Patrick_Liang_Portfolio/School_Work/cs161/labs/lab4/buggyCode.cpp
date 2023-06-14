/*
THERE ARE BUGS IN THE FOLLOWING CODE.
*/
#include <iostream>
using namespace std;

int main()

{

	int x = 3;
	int y = x;
	char myAnswer;

	cout << "y is set to: " << y << endl;

	cout << "Please input a number: ";

	cin >> y;

	bool again = true;
	while(again)
	{
		if(x > y)
		{
			cout << "X is greater than Y" << endl;
		}
		else
		{
			cout << "X is less than Y" << endl;
		}
		cout << "would you like to input another number?" << endl;
		cin >> again;
	}


	int num;
   
	cout << "What number would you like to find the factorial for? " << endl;
	cin >> num;

	for(x = num - 1; x > 0; x--)
	{
	   	num *= x;

	}

	cout << num  << endl;
	
	char myanswer;
	cout << "Are you enjoying cs161? (y or n) " << endl;
	cin >> myanswer;
	if(myanswer = y)
		cout << "YAY" << endl;
	else
		cout << "YOU WILL SOON!" << endl;

	return 0;
}
