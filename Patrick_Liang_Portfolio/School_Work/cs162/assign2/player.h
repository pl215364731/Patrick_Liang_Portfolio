/******************************************************
** Program: player.h
** Author: Patrick Liang
** Date: 04/25/2020
** Description: Player class header file
******************************************************/
#ifndef player_h
#define player_h
#include "hand.h"
#include <iostream>

using namespace std;

class Player {
private:
	Hand hand;
	string name;
public:
	Player();
	Hand& get_hand();
	int bot_card(Card);
};
#endif