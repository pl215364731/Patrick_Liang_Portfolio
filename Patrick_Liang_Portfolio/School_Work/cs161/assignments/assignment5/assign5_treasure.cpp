/**********************************************
** Program: assign5_treasure.cpp
** Author: Patrick Liang
** Date: 3/1/2020
** Description: A program that stores items in a treasure chest using a 2 dimensional array
***********************************************/
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

struct monster
{
	string name;
	short hand;
	short threat;
	float cost;
};

void add(const int mainRow, const int mainCol, monster** ptr)
{
	int row;
	int column;
	cout << "Enter row: ";
	cin >> row;
	cout << "Enter column: ";
	cin >> column;
	if (row >= mainRow || column >= mainCol)
	{
		cout << "Invalid coordinates" << endl;
		return;
	}
	if (ptr[row][column].threat > 0)
	{
		cout << "There is already a monster in this coordinate" << endl;
		return;
	}
	
	cout << "Enter name (string): ";
	cin.ignore();
	getline(cin, ptr[row][column].name);
	cout << "Enter number of hands (short): ";
	cin >> ptr[row][column].hand;
	do
	{
		cout << "Enter threat level (from 1 - 10, short): ";
		cin >> ptr[row][column].threat;
	} while (ptr[row][column].threat <= 0 || ptr[row][column].threat > 10);
	cout << "Enter the value($, float): ";
	cin >> ptr[row][column].cost;
}

void remove(const int mainRow, const int mainCol, monster** ptr)
{
	int row;
	int column;
	cout << "Enter row: ";
	cin >> row;
	cout << "Enter column: ";
	cin >> column;
	if (row >= mainRow || column >= mainCol)
		cout << "Invalid coordinates" << endl;
	else
	{
		if (ptr[row][column].threat == 0)
			cout << "There is no monster to remove" << endl;
		else
		{
			ptr[row][column].name = " ";
			ptr[row][column].hand = 0;
			ptr[row][column].threat = 0;
			ptr[row][column].cost = 0;
		}
	}
}

void random(const int mainRow, const int mainCol, monster** ptr)
{
	int row;
	int column;
	cout << "Enter row: ";
	cin >> row;
	cout << "Enter column: ";
	cin >> column;
	if (row >= mainRow || column >= mainCol)
	{
		cout << "Invalid coordinates" << endl;
		return;
	}
		
	if (ptr[row][column].threat > 0)
	{
		cout << "There is already a monster in this coordinate" << endl;
		return;
	}

	char c = (char)(rand() % 26 + 65);
	string s;
	s += c;
		for (int i = 0; i < (rand() % 15 + 10); i++)
		{
			s += (char)(rand() % 26 + 97);
		}
	ptr[row][column].name = s;
	ptr[row][column].hand = rand() % 100;
	ptr[row][column].threat = rand() % 10 + 1;
	ptr[row][column].cost = (float)(rand() % 10000) / 100;

	cout << "Random monster:";
	cout << " Name: " << ptr[row][column].name;
	cout << " Number of hands: " << ptr[row][column].hand;
	cout << " Level of threat: " << ptr[row][column].threat;
	cout << " Value: " << ptr[row][column].cost << "\n" << endl;
}

void display(const int mainRow, const int mainCol, monster** ptr)
{
	int row;
	int column;
	cout << "Enter row: ";
	cin >> row;
	cout << "Enter column: ";
	cin >> column;
	if (row >= mainRow || column >= mainCol)
	{
		cout << "Invalid coordinates" << endl;
		return;
	}
	if (ptr[row][column].threat == 0)
	{
		cout << "There is no monster in this coordinate" << endl;
		return;
	}
	cout << "Name: " << ptr[row][column].name << endl;
	cout << "Number of hands: " << ptr[row][column].hand << endl;
	cout << "Level of threat: " << ptr[row][column].threat << endl;
	cout << "Value: " << ptr[row][column].cost << "\n" << endl;
}

void swap(const int mainRow, const int mainCol, monster** ptr)
{
	monster holder;
	int row1;
	int column1;
	int row2;
	int column2;
	cout << "Enter row for the first monster: ";
	cin >> row1;
	cout << "Enter column for the first monster: ";
	cin >> column1;
	if (row1 >= mainRow || column1 >= mainCol)
	{
		cout << "Invalid coordinates" << endl;
		return;
	}
	if (ptr[row1][column1].threat == 0)
	{
		cout << "There is no monster to swap" << endl;
		return;
	}
		
	cout << "Enter row for the second monster: ";
	cin >> row2;
	cout << "Enter column for the second monster: ";
	cin >> column2;
	if (row1 >= mainRow || column1 >= mainCol)
	{
		cout << "Invalid coordinates" << endl;
		return;
	}
	if (ptr[row2][column2].threat == 0)
	{
		cout << "There is no monster to swap" << endl;
		return;
	}
	holder = ptr[row1][column1];
	ptr[row1][column1] = ptr[row2][column2];
	ptr[row2][column2] = holder;
	
}

void chest(int row, int column, monster ** ptr)
{
	string** item = new string * [row];
	for (int i = 0; i < row; i++)
	{
		item[i] = new string[column];
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			item[i][j] = (string)"[" + (ptr[i][j].name)[0] + (string)"]";
		}
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			cout << item[i][j];
		}
		cout << endl;
	}
	for (int i = 0; i < row; i++)
	{
		delete [] item[i];
	}
	delete [] item;
}

void prompt()
{
	cout << "1) Add monster" << endl;
	cout << "2) Remove monster" << endl;
	cout << "3) Add random monster" << endl;
	cout << "4) Display monster" << endl;
	cout << "5) Swap monster" << endl;
	cout << "6) Quit" << endl;
}

void price(int row, int column, monster** ptr)
{
	float value = 0;
	int item = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			value += ptr[i][j].cost;
			if (ptr[i][j].threat != 0)
				item++;
		}
	}
	if (item == 1)
		cout << "Total value of 1 item: $" << value << endl;
	else
		cout << "Total value of " << item << " items: $" << value << endl;
	cout << endl;
}

int main()
{
	int row;
	int column;
	short input;
	cout << "Enter the number of rows: ";
	cin >> row;
	cout << "Enter the number of column: ";
	cin >> column;

	monster** ptr = new monster*[row]; //making the 2D array on the heap
	for (int i = 0; i < row; i++)
	ptr[i] = new monster[column];

	for (int i = 0; i < row; i++) // initializing all monsters
	{
		for (int j = 0; j < column; j++)
		{
			ptr[i][j].hand = 0;
			ptr[i][j].threat = 0;
			ptr[i][j].cost = 0;
		}
	}
	srand(time(NULL));

	bool b = true;
	while (b) 
	{
		chest(row, column, ptr);
		price(row, column, ptr);
		prompt();
		cin >> input;
		switch (input)
		{
		case 1:add(row, column, ptr);
			break;
		case 2:remove(row, column, ptr);
			break;
		case 3:random(row, column, ptr);
			break;
		case 4:display(row, column, ptr);
			break;
		case 5:swap(row, column, ptr);
			break;
		case 6: 
			for (int i = 0; i < row; i++)
			{
				delete[] ptr[i];
			}
			delete[] ptr;
			return 0;
		default: cout << "Invalid Input" << endl;
			break;
		}
	}
}