#include<iostream>
#include<string>

using namespace std;

string pal(char c)
{
	string s;
	if (c == 'A')
	{
		s = "A";
	}
	else
	{
		s = pal(c - 1) + c + pal(c - 1);
	}
	return s;
}

int main()
{
	char c;
	cin >> c;
	cout << pal(c) << endl;
	return 0;
}
