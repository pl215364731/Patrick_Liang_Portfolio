#include <iostream>

using namespace std;

/*Test Cases:
*Input: 1,6,4,2,3
*Output: Highest:jar 1, lowest jar 0
*
*Input: 9,4,10,2,4
*Output: Highest:jar 2, lowest jar 3
*
*Input: a,b,c,d,e
*Output: Invalid input, program crashes
*/

int main()
{
	int jar[5] = {};
	cout << "Hello Scientists! You have 5 jars to fill with fruit flies." << endl;
	cout << "How many fruit flies would you like in jar 0: ";
	cin >> jar[0];
	cout << "How many fruit flies would you like in jar 1: ";
	cin >> jar[1];
	cout << "How many fruit flies would you like in jar 2: ";
	cin >> jar[2];
	cout << "How many fruit flies would you like in jar 3: ";
	cin >> jar[3];
	cout << "How many fruit flies would you like in jar 4: ";
	cin >> jar[4];
	
	int highest_value = 0;
	int highest_index = 0;
	int lowest_value = 99999;
	int lowest_index = 0;
	for (int i = 0; i < 5; i++)
	{
		if (jar[i] >= highest_value)
		{
			highest_value = jar[i];
			highest_index = i;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		if (jar[i] <= lowest_value)
		{
			lowest_value = jar[i];
			lowest_index = i;
		}
	}

	cout << "The jar with the most fruit flies : jar " << highest_index << endl;
	cout << "The jar with the least fruit flies: jar " << lowest_index << endl;
}

