#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	char arr[20] = {};
	cout << "Please enter a string: ";
	cin.getline(arr, 20);
	int star = 0;
	for (int i = 0; i < strlen(arr); i++)
	{
		if (arr[i] == '*')
			star++;
	}

	cout << "String length :" << strlen(arr) << endl;
	cout << "Stars : " << star << endl;
	cout << "Star-factor (percentage): " << ((float)star / (float)strlen(arr)) * 100 << " %" << endl;
	return 0;
}