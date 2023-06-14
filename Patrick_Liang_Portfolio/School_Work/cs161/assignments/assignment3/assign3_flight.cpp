/**************************************************
** Program: assign3_flight.cpp
** Author: Patrick Liang
** Date: 02/08/2020
** Description: Make a flight animator
***************************************************/

#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <string>

using namespace std;

int getInput(int input, string prompt) //get a postive integer or 0, reprompt if input is negative
{
	cout << prompt;
	cin >> input;
	while (input <= 0)
	{
		cout << "Invalid input" << endl;
		cout << prompt;
		cin >> input;
	}
	return input;
}

float getFloat(float input, string prompt) //get a positive float, reprompt if input is negative
{
	cout << prompt;
	cin >> input;
	while (input <= 0)
	{
		cout << "Invalid input" << endl;
		cout << prompt;
		cin >> input;
	}
	return input;
}

float flightTime(float& time, int distance, int airspeed, int windspeed)
{
	time = (float)distance / ((float)airspeed - (float)windspeed);
	return time;
}

float returnTime(float& time, int distance, int airspeed, int windspeed)
{
	time = (float)distance / ((float)airspeed + (float)windspeed);
	return time;
}

float price(float& cost, int fuelBurnRate, int fuelPrice, float time, int passengers)
{
	cost = (float)fuelBurnRate * (float)fuelPrice * time / (float)passengers;
	return cost;
}

void animation(int hour, float animationTime)
{
	unsigned long time = animationTime * 1000000;
	cout << "*" << flush;
	for (int i = 0; i < hour; i++)
	{
		usleep(time);
		cout << "*" << flush;
	}
	cout << "\n";
}

void reAnimation(int hour, float animationTime)
{
	unsigned long time = animationTime * 1000000;
	hour++;
	string s(hour, ' ');
	s[hour] = '*';
	cout << s << flush << "\r";
	for (int i = hour; i >= 0; i--)
	{
		if (i != 0)
		{
			s[i] = '*';
			cout << s << flush << "\r";
			usleep(time);
			
		}
		else
		{
			s[i] = '*';
			cout << s << flush << endl;
		}
	}

	
}

int main()
{
	int distance = 0; /*all these variables are ints because they are all integers and they all use the same function later*/
	int airspeed = 0; /*the min of int is -2147483648, max is 2147483647*/
	int windspeed = 0;
	int fuelBurnRate = 0;
	int fuelPrice = 0;
	int passengers = 0;

	float animationTime = 0; /*These values are floats because they have decimal places*/
	float time = 0;
	float cost = 0;
	
	distance = getInput(distance, "Flight distance (miles):");
	airspeed = getInput(airspeed, "Airplane airspeed (miles per hour):");

	cout << "Wind speed (miles per hour):";
	cin >> windspeed;
	while (windspeed >= airspeed || -windspeed >= airspeed)
	{
		cout << "Invalid input" << endl;
		cout << "Wind speed (miles per hour):";
		cin >> windspeed;
	}
	
	fuelBurnRate = getInput(fuelBurnRate, "Fuel burn rate (gallons per hour):");
	fuelPrice = getInput(fuelPrice, "Fuel price (dollars per gallon):");
	passengers = getInput(passengers, "Number of people onboard:");
	animationTime = getFloat(animationTime, "Seconds of animation per flight hour:");
		
	
	flightTime(time, distance, airspeed, windspeed);
	int hour = time;
	int minute = (time - (float)hour) * 60;
	price(cost, fuelBurnRate, fuelPrice, time, passengers);
	cout << "Your flight will take " << hour << " hours and "<< minute << " minutes and cost $" 
		<< fixed << setprecision(2) << cost << " per person." << endl;

	animation(hour, animationTime);

	returnTime(time, distance, airspeed, windspeed);
	hour = time;
	minute = (time - (float)hour) * 60;
	price(cost, fuelBurnRate, fuelPrice, time, passengers);
	cout << "Your flight will take " << hour << " hours and " << minute << " minutes and cost $"
		<< fixed << setprecision(2) << cost << " per person." << endl;

	reAnimation(hour, animationTime);

	return 0;
}
