#include <iostream>
using namespace std;
int main()
{
	int input;
	cout << "Do you like vim as an editor?" << endl;
	cout << "[1]Yes\n[0]No" << endl;
	cin >> input;
	switch(input)
	{
		case 1:
		   cout << "You love vim!" << endl;
		   break;
		case 0:
		   cout<< "You hate vim!" << endl;
		   break;
		default:
		   cout << "Invalid choice" << endl;
	}
	return 0;
}
