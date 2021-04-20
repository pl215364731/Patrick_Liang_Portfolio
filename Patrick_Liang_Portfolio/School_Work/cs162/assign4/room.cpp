/******************************************************
** Program: room.cpp
** Author: Patrick Liang
** Date: 05/22/2020
** Description: Room class cpp file
** Input: room.h, event.h
** Output: None
******************************************************/
#include "room.h"
#include "event.h"
#include <iostream>
#include <string>

using namespace std;

Room::Room() {
/******************************************************
** Name: Room
** Description: Room class constructor
** Parameter: None
******************************************************/
	e = NULL;
}
void Room::encounter() {
/******************************************************
** Name: encounter
** Description: encounter function that runs the event encounter function
** Parameter: None
******************************************************/
	e->encounter();
}
void Room::percept() {
/******************************************************
** Name: percept
** Description: run the event percept function
** Parameter: None
******************************************************/
	e->percept();
}

string Room::get_name() {
/******************************************************
** Name: get_name
** Description: get the event's name
** Parameter: None
******************************************************/
	return e->get_name();
}

Event* Room::get_event() {
/******************************************************
** Name: get_event
** Description: get the event pointer
** Parameter: None
******************************************************/
	return e;
}

void Room::set_event(Event * eve) {
/******************************************************
** Name: set_event
** Description: set a event to the member variable
** Parameter: None
******************************************************/
	e = eve;
}

void Room::reset() {
/******************************************************
** Name: reset
** Description: runs the event reset function
** Parameter: None
******************************************************/
	e->reset();
}

