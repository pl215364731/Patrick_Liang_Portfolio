/*******************************************************************
** Program:lab6_hangman.cpp
** Author: Patrick Liang
** Description: Making the game hangman
** Date: 2/10/2020
*******************************************************************/
#include <iostream>
#include <string>

using namespace std;

void get_input(string* s)
/*******************************************************************
** Function: get_input
** Description:get a string
** Parameters:string* s
** Pre-Conditions: None
** Post-Conditions: s is now defined
*******************************************************************/
{
	getline(cin, *s);
}

void hide_letters(const string& s, string* s_hidden)
/*******************************************************************
** Function: hide_letters
** Description:hidding string s
** Parameters:s, s_hidden
** Pre-Conditions:s is defined
** Post-Conditions:s_hidden is the same as s but hidden
*******************************************************************/
{
	*s_hidden = s;
	int i = 0;
	while ((*s_hidden)[i])
	{
		if ((*s_hidden)[i] != ' ')
			(*s_hidden)[i] = '*';
		i++;
	}
}
int guess_letter(char letter, const string& s, string* s_hidden)
/*******************************************************************
** Function: guess_letter
** Description: replace guessed letter
** Parameters:letter, constant string s, string* s_hidden
** Pre-Conditions: none
** Post-Conditions: return matches
*******************************************************************/
{
	cout << "Please give a letter:";
	cin >> letter;
	int i = 0;
	int match = 0;
	while (s[i])
	{
		if (s[i] == letter)
		{
			(*s_hidden)[i] = letter;
			match++;
		}
		i++;
	}
	return match;
}

int main()
{
	string s;
	string s_hidden;
	char letter = 'c';
	int match = 0;

	cout << "Enter a secret string using only lower-case letters:";
	get_input(&s);
	for (int i = 0; i <= 50; i++)
		cout << "\n";

	hide_letters(s, &s_hidden);
	cout << s_hidden << endl;

	while (s_hidden != s)
	{
		match = guess_letter(letter, s, &s_hidden);
		cout << match << " matches!" << endl;
		cout << "Your string is:" << s_hidden << endl;
	}

	cout << "Congratulations! You win the game!" << endl;
	return 0;
}
