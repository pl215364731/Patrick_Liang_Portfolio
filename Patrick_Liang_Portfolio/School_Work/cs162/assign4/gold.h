/******************************************************
** Program: gold.h
** Author: Patrick Liang
** Date: 05/22/2020
** Description: Gold class header file
** Input: event.h
** Output: None
******************************************************/
#ifndef gold_h
#define gold_h
#include "event.h"

class Gold : public Event {
	bool g;
public:
	Gold();
	void encounter();
	void percept();
	void reset() override;
};

#endif
