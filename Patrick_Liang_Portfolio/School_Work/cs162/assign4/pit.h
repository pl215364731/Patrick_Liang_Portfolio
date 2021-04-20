/******************************************************
** Program: pit.h
** Author: Patrick Liang
** Date: 05/22/2020
** Description: Pit class header file
** Input: event.h
** Output: None
******************************************************/
#ifndef pit_h
#define pit_h
#include "event.h"

class Pit : public Event {
public:
	Pit();
	void encounter();
	void percept();
};

#endif
