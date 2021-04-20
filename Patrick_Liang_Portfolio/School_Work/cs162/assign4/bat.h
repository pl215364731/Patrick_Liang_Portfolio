/******************************************************
** Program: bat.h
** Author: Patrick Liang
** Date: 05/22/2020
** Description: Bat class header file
** Input: event.h
** Output: None
******************************************************/
#ifndef bat_h
#define bat_h
#include "event.h"

class Bat : public Event {
private:
public:
	Bat();
	void encounter();
	void percept();
};

#endif
