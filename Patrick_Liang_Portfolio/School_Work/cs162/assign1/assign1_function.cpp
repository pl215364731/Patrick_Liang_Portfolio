/******************************************************
** Program: assign1_function.cpp
** Author: Patrick Liang
** Date: 4/10/2020
** Description: Function implementations for assignment 1
** Input: functions from header
** Output: None
******************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "assign1.h"

using namespace std;

wizard* create_wizards(int i) {
/******************************************************
** Name: create_wizards
** Description: Creates a wizard array on the heap
** Input: int i, the size of the array
** Output: a wizard array on the heap
******************************************************/
	wizard* wiz_arr = new wizard[i];
	return wiz_arr;
}

spellbook* create_spellbooks(int i) {
/******************************************************
** Name: create_spellbooks
** Description: make a spellbook array on the heap
** Input: int i, the size of the array
** Output: a spellbook array on the heap
******************************************************/
	spellbook* sb_arr = new spellbook[i];
	return sb_arr;
}

spell* create_spells(int i) {
/******************************************************
** Name: create_spells
** Description: make a spell array on the heap
** Input: int i, the size of the array
** Output: a spell array on the heap
******************************************************/
	spell* spell_arr = new spell[i];
	return spell_arr;
}

void get_wizard_data(wizard* wiz_arr, int m, ifstream& f) {
/******************************************************
** Name: get_wizard_data
** Description: Assuming the file is already open take in all
** the information from the file and store it in the wizard array
** Input: the wizard array, the size of the array, input file stream
** Output: None
******************************************************/
	f.ignore(256, '\n');
	for (int i = 0; i < m; i++) {
		getline(f, wiz_arr[i].name, ' ');
		f >> wiz_arr[i].id;
		f.ignore(256, ' ');
		getline(f, wiz_arr[i].password, ' ');
		getline(f, wiz_arr[i].position_title, ' ');
		f >> wiz_arr[i].beard_length;
		f.ignore(256, '\n');
	}
}

void get_spell_data(spell* s, int m, ifstream& f) {
/******************************************************
** Name: get_spell_data
** Description: This function is part of getting spellbook data
** taking spell information from the file and storing it in the
** spell array of each spellbook
** Input: the spell array, the size of the array, input file stream
** Output: None
******************************************************/
	for (int i = 0; i < m; i++)
	{
		getline(f, s[i].name, ' ');
		f >> s[i].success_rate;
		f.ignore(256, ' ');
		getline(f, s[i].effect, '\n');
	}
}

void get_spellbook_data(spellbook* sb_arr, int m, ifstream& f) {
/******************************************************
** Name: get_spellbook_data
** Description: Assuming the file is already open take in all
** the information from the file and store it in the spellbook array
** Input: the spellbook array, the size of the array, input file stream
** Output: None
******************************************************/
	f.ignore(256, '\n');
	for (int i = 0; i < m; i++) {
		getline(f, sb_arr[i].title, ' ');
		getline(f, sb_arr[i].author, ' ');
		f >> sb_arr[i].num_pages;
		f >> sb_arr[i].edition;
		f >> sb_arr[i].num_spells;
		f.ignore(256, '\n');
		sb_arr[i].s = create_spells(sb_arr[i].num_spells);
		get_spell_data(sb_arr[i].s, sb_arr[i].num_spells, f);
	}
}

void login_id(wizard* wiz_arr, int m, int & index) {
/******************************************************
** Name: login_id
** Description:This function takes in the inputted id and 
** compare it with the wizard file.
** Input: the wizard array, the size of the array, an index integer
** to keep track of which wizard is loging in
** Output: Weather the inputted ID is valid
******************************************************/
	int id = 0;
	index = -1;

	while (index == -1) {
		cout << "Please enter your id: ";
		cin >> id;
		while (cin.fail()) {
			cout << "Id has to be all integers." << endl;
			cout << "Please enter your id:";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> id;
		}
		for (int i = 0; i < m; i++) {
			if (id == wiz_arr[i].id) {
				index = i;
			}
		}
		if (index == -1) {
			cout << "ID doesn't match our record, please try again." << endl;
		}
	}
}

void login(wizard* wiz_arr, int m, int& index) {
/******************************************************
** Name: login
** Description: The login function compares the inputted id and
** password with the wizard array and continues the program only
** when login is successful.
** Input: the wizard array, the size of the array, an index integer
** to keep track of which wizard is loging in
** Output: All information of the wizard after a successful login
******************************************************/
	short attempt = 0;
	while (attempt < 3) {
		string password;
		login_id(wiz_arr, m, index);
		cout << "Please enter your password: ";
		cin.ignore(256, '\n');
		getline(cin, password, '\n');
		if (password == wiz_arr[index].password) {
			attempt = 4;
		}
		else {
			cout << "Incorrect password." << endl;
			attempt++;
		}
	}
	if (attempt == 3)
		exit(0);

	cout << "\nWelcome " << wiz_arr[index].name << endl;
	cout << "ID: " << wiz_arr[index].id << endl;
	cout << "Status: " << wiz_arr[index].position_title << endl;
	cout << "Beard Length: " << wiz_arr[index].beard_length << endl;
}

void check_for_permission(wizard* wiz_arr, int index, spellbook* sb_arr, int m) {
/******************************************************
** Name: check_for_permission
** Description: For all students, leave a note on all spellbooks
** with spells effects death and poison.
** Input: the wizard array, the index number of the wizard who logged in,
** the spellbook array, the size of the spellbook array
** Output: None
******************************************************/
	if (wiz_arr[index].position_title == "Student") {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < sb_arr[i].num_spells; j++) {
				if ((sb_arr[i].s)[j].effect == "death" || (sb_arr[i].s)[j].effect == "poison") {
					sb_arr[i].edition = 0; //if edition is 0 for a spellbook, then this book will not appear for a student
				}
			}
		}
	}
}

void print(string s) {
/******************************************************
** Name: print
** Description: prompt the user where to print the information
** they requested and pring the information out
** Input: the string of information being printed
** Output: Printed info
******************************************************/
	int option = 0;
	string file;
	ofstream fout;
	bool b = true;
	while (b) {
		cout << "How would you like the information displayed?" << endl;
		cout << "[1]Print to screen\n[2]Print to file" << endl;
		cin >> option;
		switch (option) {
		case 1: cout << s;
			b = false;
			break;
		case 2: cin.clear();
			cin.ignore(256, '\n');
			cout << "File name: ";
			getline(cin, file, '\n');
			fout.open(file);
			fout << s;
			fout.close();
			b = false;
			break;
		default: cout << "Invalid option." << endl;
			break;
		}
	}
}

void sort_spellbook(spellbook* sb_arr, int m) {
/******************************************************
** Name: sort_spellbook
** Description: sort the spellbook by page number and print
** them in order
** Input: the spellbook array, the size of the book array
** Output: the books title and page number in order of page numbers
******************************************************/
	spellbook* sort = new spellbook[m];
	string output;

	for (int i = 0; i < m; i++) {
		sort[i].title = sb_arr[i].title;
		sort[i].num_pages = sb_arr[i].num_pages;
	}
	for (int j = 0; j < m; j++) {
		int index = 0;
		for (int i = 1; i < m; i++) {
			if (sort[i].num_pages < sort[index].num_pages) {
				index = i;
			}
		}
		if (sb_arr[index].edition == 0) {
			sort[index].num_pages = 999999;
			continue;
		}
		else {
			output += sort[index].title + " " + to_string(sort[index].num_pages) + "\n";
			sort[index].num_pages = 999999;
		}
	}
	print(output);
	delete[] sort;
}

void sort_spells_effect(spellbook* sb_arr, int m, string& output, string effect) {
/******************************************************
** Name: sort_spells_effect
** Description: find all spells with a specific effect and
** all them to the output string
** Input: the spellbook array, the size of the array, the given effect
** Output: output string
******************************************************/
	for (int i = 0; i < m; i++) {
		if (sb_arr[i].edition == 0)
			continue;
		else {
			for (int j = 0; j < sb_arr[i].num_spells; j++) {
				if ((sb_arr[i].s)[j].effect == effect)
					output += (sb_arr[i].s)[j].effect + " " + (sb_arr[i].s)[j].name + "\n";
			}
		}
	}
}

void print_spells_effect(spellbook* sb_arr, int m) {
/******************************************************
** Name: print_spells_effect
** Description: go through and find all spells of each category
** and print them in order
** Input: spellbook array, the size of the array
** Output: the string with every spell in order
******************************************************/
	string output;
	sort_spells_effect(sb_arr, m, output, "bubble");
	sort_spells_effect(sb_arr, m, output, "memory_loss");
	sort_spells_effect(sb_arr, m, output, "fire");
	sort_spells_effect(sb_arr, m, output, "poison");
	sort_spells_effect(sb_arr, m, output, "death");
	print(output);

}

void get_average(spellbook* sb_arr, int m) {
/******************************************************
** Name: get_average
** Description: calculate the average success rate of each spellbook
** Input: the spellbook array and its size
** Output: the average success rate of each spellbook and store in the array
******************************************************/
	for (int i = 0; i < m; i++) {
		sb_arr[i].avg_success_rate = 0;
		for (int j = 0; j < sb_arr[i].num_spells; j++) {
			sb_arr[i].avg_success_rate += (sb_arr[i].s)[j].success_rate;
		}
		sb_arr[i].avg_success_rate /= (float)sb_arr[i].num_spells;
	}
}

void sort_average(spellbook* sb_arr, int m) {
/******************************************************
** Name: sort_average
** Description: sort the spellbooks by their average success rate
** and print all of the books and their success rate in order
** Input: the spellbook array, the size of the array
** Output: the book names and their success rate
******************************************************/
	spellbook* sort = create_spellbooks(m);
	string output;
	for (int i = 0; i < m; i++) {
		sort[i].title = sb_arr[i].title;
		sort[i].avg_success_rate = sb_arr[i].avg_success_rate;
	}
	for (int j = 0; j < m; j++) {
		int index = 0;
		for (int i = 1; i < m; i++) {
			if (sort[i].avg_success_rate > sort[index].avg_success_rate) {
				index = i;
			}
		}
		if (sb_arr[index].edition == 0) {
			sort[index].avg_success_rate = 0;
			continue;
		}
		else {
			output += sort[index].title + " " + to_string(sort[index].avg_success_rate) + "\n";
			sort[index].avg_success_rate = 0;
		}
	}
	print(output);
	delete[] sort;
}

void delete_info(wizard* wiz_arr, spellbook* sb_arr, int n) {
/******************************************************
** Name: delete_info
** Description: delete the wizard and spellbook array created on the heap
** Input: the wizard array, the spellbook array, the size of the spellbook array
** Output: None
******************************************************/
	delete[] wiz_arr;
	for (int i = 0; i < n; i++) {
		delete[] sb_arr[i].s;
	}
	delete[] sb_arr;
}
