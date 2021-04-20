/******************************************************
** Program: event.cpp
** Author: Patrick Liang
** Date: 05/22/2020
** Description: Event class cpp file
** Input: event.h
** Output: None
******************************************************/
#include "event.h"

using namespace std;

string Event::get_name() {
/******************************************************
** Name: get_name
** Description: return name
** Parameter: None
******************************************************/
   	return name;
}

void Event::set_w() {
/******************************************************
** Name: set_w
** Description: a virtual function to move wumpus
** Parameter: None
******************************************************/
    return;
}

void Event::reset() {
/******************************************************
** Name: reset
** Description: reset everything to the beginning of the map
** Parameter: None
******************************************************/
    return;
}
