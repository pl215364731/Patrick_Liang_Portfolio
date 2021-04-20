/******************************************************
** Program: hand.h
** Author: Patrick Liang
** Date: 04/25/2020
** Description: Hand class header file
******************************************************/
#ifndef hand_h
#define hand_h
#include "deck.h"

class Hand {
private:
	Card* cards;
	int n_cards; //number of cards in the hand
public:
	Hand();
	void get_hand(int&, Deck);
	Card play_card(int);
	void draw_card(Card);
	bool check(Card);
	void print_hand();
	int get_n_cards();
	Card pass_card(int);
	~Hand();
};



#endif
