/******************************************************
** Program: card.h
** Author: Patrick Liang
** Date: 04/25/2020
** Description: Card class header file
******************************************************/
#ifndef card_h
#define card_h

class Card {
private:
	int rank;
	int suit;
public:
	Card();
	int get_rank();
	int get_suit();
	void set_rank(int);
	void set_suit(int);
	void print_card();
	Card& operator=(const Card);
};

#endif
