/**************************************************
** Program: assign4_text.cpp
** Author: Patrick Liang
** Date: 02/23/2020
** Description: A program that can perform multiple tasks on a string.
***************************************************/
#include <iostream>
#include <cstring>

using namespace std;

bool check_vowel_cons(const char* s)
{
	/*******************************************
	** Function: check_vowel_cons
	** Description: check if vowels = consonants
	** Parameters: a c-style string
	********************************************/
	int vowels = 0;
	int cons = 0;
	for (int i = 0; i < strlen(s); i++)
	{
		switch (s[i])
		{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U': vowels++;
			break;
		case ' ':
		case '(':
		case ')':
		case '?':
		case '!':
		case '.':
		case ',':
		case ':':
		case ';': continue;
			break;
		default: cons++;
			break;
		}
	}

	if (vowels == cons)
	{
		cout << "# vowels = # consonants\n" << endl;
		return true;
	}
		
	else
	{
		cout << "# vowels != # consonants\n" << endl;
		return false;
	}
		
}

void letter_swap(char* s)
{
	/*******************************************
	** Function: leter_swap
	** Description: swap 2 letters the user inputs
	** Parameters: a c-style string
	********************************************/
	char a, b;
	do
	{
		cout << "Please enter a letter in the string:";
		cin >> a;
	} while (a < 'A' || a > 'z' || (a > 'Z' && a < 'a'));
	do
	{
		cout << "Please enter a letter you want to swap (" << a << ") with:";
		cin >> b;
	} while (b < 'A' || b > 'z' || (b > 'Z' && b < 'a'));
	
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] == a)
			s[i] = b;
	}
	cout << s << endl;
}

void flip_str(const char* s, char* s2)
{
	/*******************************************
	** Function: flip_str
	** Description: reverse the string
	** Parameters: the original c-style string and another c-style string
	********************************************/
	for (int i = 0; i < strlen(s); i++)
	{
		s2[i] = s[strlen(s)- 1 - i];
	}
	cout << s2 << "\n" << endl;
	cout << s << endl;
}

int* count_chars(const char* s, const char* chars)
{
	/************************************************
	** Function: count_chars
	** Description: check the ocurrance of every letter inputted and print them out
	** Parameters: a c-style string, a c-style string on the heap
	*************************************************/
	int* frequency = new int[strlen(chars)];
	for (int i = 0; i < strlen(chars); i++)
	{
		frequency[i] = 0;
		for (int j = 0; j < strlen(s); j++)
		{
			if (chars[i] == s[j])
				frequency[i]++;
		}
		cout << chars[i] << ") " << frequency[i] << endl;
	}
	delete [] frequency;
	frequency = NULL;

	return 0;
}

void dicing(const char* s)
{
	/*******************************************
	** Function: dicing
	** Description: split the string into 2 by dicing them
	** Parameters: a c-style string
	********************************************/
	for (int i = 0; i < strlen(s); i += 2)
		cout << s[i] << " ";
	cout << "\n";
	for (int i = 1; i < strlen(s); i += 2)
		cout << " " << s[i];
	cout << "\n";

}


void prompt()
{
	/*******************************************
	** Function: prompt
	** Description: print the menu
	** Parameters: none
	********************************************/
	cout << "1. Check if vowels = consonants" << endl;
	cout << "2. Letter swap" << endl;
	cout << "3. Reverse the string" << endl;
	cout << "4. Compute character frequency distribution" << endl;
	cout << "5. Split the string into 2 different strings by dicing it." << endl;
	cout << "6. Quit" << endl;

}


int main()
{
	char arr[1028] = {}; //1027 characters plus '\0'
	char flip[1028] = {};
	char chars[10] = {};
	
	cout << "Please input a sentence or a paragraph:";
	cin.getline(arr, 1028);
	int options;
	bool b = true;
	while(b)
	{
		prompt();
		cin >> options;
		switch (options)
		{
		case 1: check_vowel_cons(arr);
			break;
		case 2: letter_swap(arr);
			break;
		case 3: flip_str(arr, flip);
			break;
		case 4: cout << "Please input a string of characters:";
			cin.ignore();
			cin.getline(chars, 10);
			count_chars(arr, chars);
			break;
		case 5: dicing(arr);
			break;
		case 6:return 0;
			break;
		default: cout << "Invalid input" << endl;
			break;
		}
	}
}