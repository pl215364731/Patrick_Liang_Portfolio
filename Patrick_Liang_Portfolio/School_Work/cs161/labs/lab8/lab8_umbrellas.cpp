#include <iostream>

using namespace std;

struct umbrella
{
	float length;
	string color;
};

int main()
{
	umbrella arr[3];
	for (int i = 0; i < 3; i++)
	{
		cout << "Enter length for umbrella " << i << ": ";
		cin >> arr[i].length;
		cout << "Enter color for umbrella " << i << ": ";
		cin >> arr[i].color;
	}
	int longest = 0;
	for (int i = 1; i < 3; i++)
	{
		if (arr[i].length > arr[longest].length)
		{
			longest = i;
		}
	}
	cout << "The longest umbrella(index " << longest << ") has a length of " << 
		arr[longest].length << " and is " << arr[longest].color << "." << endl;
	return 0;
}
