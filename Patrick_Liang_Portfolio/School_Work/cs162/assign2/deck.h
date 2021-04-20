/******************************************************
** Program: deck.h
** Author: Patrick Liang
** Date: 04/25/2020
** Description: Deck class header file
******************************************************/
#ifndef deck_h
#define deck_h
#include "card.h"

class Deck {
private:
	Card cards[52];
	int n_cards;
public:
	Deck();
	void shuffle();
	Card pass_card(int&);
};


#endif
