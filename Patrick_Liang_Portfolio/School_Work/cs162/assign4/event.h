/******************************************************
** Program: event.h
** Author: Patrick Liang
** Date: 05/22/2020
** Description: event class header file
** Input: None
** Output: None
******************************************************/
#ifndef event_h
#define event_h
#include <string>

using namespace std;

class Event {
public:
	string get_name();
	virtual void encounter() = 0;
	virtual void percept() = 0;
	virtual void set_w();
	virtual void reset();

protected:
	string name;
};
#endif
