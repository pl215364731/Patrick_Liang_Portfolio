/******************************************************
** Program: room.h
** Author: Patrick Liang
** Date: 05/22/2020
** Description: Room class header file
** Input: event.h
** Output: None
******************************************************/
#ifndef room_h
#define room_h
#include "event.h"
#include <iostream>


class Room {
private:
	Event* e;
public:
	Room();
	void encounter();
	void percept();
	string get_name();
	Event* get_event();
	void set_event(Event*);
	void reset();
};
#endif
