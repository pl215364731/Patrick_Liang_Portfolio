#include <iostream>
#include <cstring>

using namespace std;

float star_factor(char* str)
{
	int star = 0;
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == '*')
			star++;
	}

	cout << "String length :" << strlen(str) << endl;
	cout << "Stars : " << star << endl;
	cout << "Star-factor (percentage): " << ((float)star / (float)strlen(str)) * 100 << " %" << endl;
	return ((float)star / (float)strlen(str)) * 100;
}

int main()
{
	char arr[20] = {};
	cout << "Please enter a string: ";
	cin.getline(arr, 20);
	star_factor(arr);
	char* arr2 = new char[40];
	strcat(arr2, arr);
	strcat(arr2, arr);
	star_factor(arr2);
	cout << arr2 << endl;
	delete arr2;
	arr2 = NULL;
	return 0;
}

