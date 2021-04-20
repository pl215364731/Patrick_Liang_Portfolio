/******************************************************
** Program: wumpus.h
** Author: Patrick Liang
** Date: 05/22/2020
** Description: Wumpus class header file
** Input: event.h
** Output: None
******************************************************/
#ifndef wumpus_h
#define wumpus_h
#include "event.h"

class Wumpus : public Event {
	bool w;
public:
	Wumpus();
	void encounter();
	void percept();
	void set_w() override;
	void reset() override;
};

#endif

