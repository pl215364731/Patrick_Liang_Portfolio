/******************************************************
** Program: game.h
** Author: Patrick Liang
** Date: 04/25/2020
** Description: Game class header file
******************************************************/
#ifndef game_h
#define game_h
#include "deck.h"
#include "player.h"

class Game {
private:
	Deck cards;
	Player players[2];
	Card top;
public:
	Game(int&);
	void input(int&);
	void error_handle(int&);
	bool users_turn(int&, int&);
	void users_play(int&);
	bool coms_turn(int &);
	void run(int&, int&);
	void compare_n_cards();
};

#endif