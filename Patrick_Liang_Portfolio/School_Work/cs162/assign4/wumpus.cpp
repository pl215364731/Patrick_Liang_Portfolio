/******************************************************
** Program: wumpus.cpp
** Author: Patrick Liang
** Date: 05/22/2020
** Description: Wumpus class cpp file
** Input: wumpus.h
** Output: None
******************************************************/
#include "wumpus.h"
#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

Wumpus::Wumpus() {
/******************************************************
** Name: Wumpus
** Description: Wumpus class constructor
** Parameter: None
******************************************************/
	w = true;
	name = "wumpus";
}

void Wumpus::encounter() {
/******************************************************
** Name: encounter
** Description: print encounter with wumpus
** Parameter: None
******************************************************/
	if (w == true) {
		cout << "You have entered the room with the wumpus, he is not very happy to see you." << endl;
		cout << "Game Over" << endl;
	}
}

void Wumpus::percept() {
/******************************************************
** Name: percept
** Description: print percept for wumpus
** Parameter: None
******************************************************/
	if(w == true)
		cout << "You smell a terrible stench." << endl;
}

void Wumpus::set_w() {
/******************************************************
** Name: set_w
** Description: set w to false when wumpus is killed
** Parameter: None
******************************************************/
	w = false;
}

void Wumpus::reset() {
/******************************************************
** Name: reset
** Description: when the game resets, wumpus comes back to life
** Parameter: None
******************************************************/
	w = true;
}
