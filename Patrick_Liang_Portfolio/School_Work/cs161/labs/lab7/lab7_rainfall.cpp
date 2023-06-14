#include <iostream>

using namespace std;

/*
*Input for cities: 3
*Outcome: Allocate an array of size 3 in the heap
*
*Input for 3 cities: 1.2, 1.2, 1.2
*Outcome: The average is 1.2
*
*Input for 3 cities: a,b,c
*Outcome: Program crashes
*/

int main()
{
	cout << "Hello Scientists! You need to record the rainfall per city (in inches)." << endl;
	cout << "How many cities would you like to record the rainfall of: ";
	int city;
	cin >> city;
	float* rain = new float[city];
	float total = 0;
	for (int i = 0; i < city; i++)
	{
		cout << "How much rainfall was there in city " << i << ": ";
		cin >> *(rain + i);
		total += *(rain + i);
	}

	cout << "Average rainfall per city: " << total / (float)city << " inches";

	delete rain;
	rain = NULL;
	return 0;

	
}

