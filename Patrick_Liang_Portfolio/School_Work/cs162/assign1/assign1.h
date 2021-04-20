/******************************************************
** Program: assign1.h
** Author: Patrick Liang
** Date: 4/10/2020
** Description: Header file for assignment 1
** Input: None
** Output: Function declarations
******************************************************/
#include <iostream>

using namespace std;

struct wizard {
	string name;
	int id;
	string password;
	string position_title;
	float beard_length;
};

struct spell {
    string name;
    float success_rate;
    string effect;
};

struct spellbook {
    string title;
    string author;
    int num_pages;
    int edition;
    int num_spells;
    float avg_success_rate;
    spell* s;
};

wizard* create_wizards(int);
spellbook* create_spellbooks(int);
spell* create_spells(int);
void get_wizard_data(wizard*, int, ifstream&);
void get_spell_data(spell*, int, ifstream&);
void get_spellbook_data(spellbook*, int, ifstream&);
void login_id(wizard*, int, int&);
void login(wizard*, int, int&);
void check_for_permission(wizard*, int, spellbook*, int);
void print(string);
void sort_spellbook(spellbook*, int);
void sort_spells_effect(spellbook*, int,string&, string);
void print_spells_effect(spellbook*, int);
void get_average(spellbook*, int);
void sort_average(spellbook*, int);
void delete_info(wizard*, spellbook*, int);

