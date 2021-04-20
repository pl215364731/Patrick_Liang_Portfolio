/******************************************************
** Program: bat.cpp
** Author: Patrick Liang
** Date: 05/22/2020
** Description: Bat class cpp file
** Input: bat.h
** Output: None
******************************************************/
#include "bat.h"
#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

Bat::Bat() {
/******************************************************
** Name: Bat
** Description: Bat class constructor
** Parameter: None
******************************************************/
	name = "bat";
}

void Bat::encounter() {
/******************************************************
** Name: encounter
** Description: encounter bat function
** Parameter: None
******************************************************/
	cout << "An angry bat grabs you and started flying" << endl;
}
void Bat::percept() {
/******************************************************
** Name: percept
** Description: print bat percept
** Parameter: None
******************************************************/
	cout << "You hear wings flapping." << endl;
}