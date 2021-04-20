/******************************************************
** Program: gold.cpp
** Author: Patrick Liang
** Date: 05/22/2020
** Description: Gold class cpp file
** Input: gold.h
** Output: None
******************************************************/
#include "gold.h"
#include <iostream>

using namespace std;

Gold::Gold() {
/******************************************************
** Name: Gold
** Description: Gold class constructor
** Parameter: None
******************************************************/
	name = "gold";
	g = false;
}
void Gold::encounter() {
/******************************************************
** Name: encounter
** Description: Gold encounter function
** Parameter: None
******************************************************/
	if (g == false) {
		cout << "You found the treasure!" << endl;
		g = true;
	}
}

void Gold::percept() {
/******************************************************
** Name: percept
** Description: print gold percept function
** Parameter: None
******************************************************/
	if(g == false)
		cout << "You see a glimmer nearby." << endl;
}

void Gold::reset() {
/******************************************************
** Name: reset
** Description: change g back to false so player doesn't have it at the start of the game
** Parameter: None
******************************************************/
	g = false;
}