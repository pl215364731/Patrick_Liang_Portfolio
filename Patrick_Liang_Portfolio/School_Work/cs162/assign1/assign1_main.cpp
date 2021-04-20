/******************************************************
** Program: assign1_main.cpp
** Author: Patrick Liang
** Date: 04/10/2020
** Description: driver for assignment 1
** Input: 2 txt files including data of wizards and data of spellbooks
** Output: sorted spellbooks and spells
******************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "assign1.h"

using namespace std;

int main(int argc, char ** argv) { 
	if (argc != 3) {
		cout << "Invalid arguments." << endl;
		return -1;
	}
		
	ifstream f;
	int sb_num = 0;
	int wiz_num = 0;
	wizard* wiz_arr;

	f.open(argv[1]); //inputting from wizards.txt
	if (f.fail()) {
		cout << "File doesn't exist" << endl;
		return -1;
	}
	f >> wiz_num;
	wiz_arr = create_wizards(wiz_num);
	get_wizard_data(wiz_arr, wiz_num, f);
	f.close();

	f.open(argv[2]); //inputting from spellbooks.txt
	if (f.fail()) {
		cout << "File doesn't exist" << endl;
		return -1;
	}
	f >> sb_num;
	spellbook* sb_arr = create_spellbooks(sb_num);
	get_spellbook_data(sb_arr, sb_num, f);
	f.close();

	int wiz_index = 0;

	login(wiz_arr, wiz_num, wiz_index);
	check_for_permission(wiz_arr, wiz_index, sb_arr, sb_num);
	int option;

	while (true) {
		cout << "\n[1]Sort spellbooks by number of pages" << endl;
		cout << "[2]Sort spells by effects" << endl;
		cout << "[3]Sort spellbooks by average success rate of spells" << endl;
		cout << "[4]Log out" << endl;

		cin >> option;
		switch (option) {
		case 1: sort_spellbook(sb_arr, sb_num);
			break;
		case 2: print_spells_effect(sb_arr, sb_num);
			break;
		case 3: 	get_average(sb_arr, sb_num);
			sort_average(sb_arr, sb_num);
			break;
		case 4: delete_info(wiz_arr, sb_arr, sb_num);
			return 0;
			break;
		default: cout << "Invalid Option" << endl;
			break;
		}
	}
}