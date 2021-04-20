/******************************************************
** Program: pit.cpp
** Author: Patrick Liang
** Date: 05/22/2020
** Description: Pit class cpp file
** Input: pit.h
** Output: None
******************************************************/
#include "pit.h"
#include <iostream>

using namespace std;

Pit::Pit() {
/******************************************************
** Name: Pit
** Description: Pit class constructor
** Parameter: None
******************************************************/
	name = "pit";
}
void Pit::encounter() {
/******************************************************
** Name: encounter
** Description: pit encounter function, game is over if this happens
** Parameter: None
******************************************************/
	cout << "You walked into a bottomless pit" << endl;
	cout << "Game Over" << endl;
}
void Pit::percept() {
/******************************************************
** Name: percept
** Description: print pit percept
** Parameter: None
******************************************************/
	cout << "You feel a breeze." << endl;
}
