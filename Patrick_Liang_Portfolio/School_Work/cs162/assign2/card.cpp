/******************************************************
** Program: card.cpp
** Author: Patrick Liang
** Date: 04/25/2020
** Description: Card class function implementation file
** Input: card.h
** Output: None
******************************************************/
#include <iostream>
#include "card.h"

using namespace std;

Card::Card() {
/******************************************************
** Name: Card
** Description: Default constructor for the Card class
** Input: Member variables of the class
** Output: 0 for both rank and suit
******************************************************/
	rank = 0;
	suit = 0;
}
int Card::get_rank() {
/******************************************************
** Name: get_rank
** Description: accessors for rank
** Input: None
** Output: rank
******************************************************/
	return rank;
}

int Card::get_suit() {
/******************************************************
** Name: get_suit
** Description: accessors for suit
** Input: None
** Output: suit
******************************************************/
	return suit;
}
void Card::set_rank(int r) {
/******************************************************
** Name: set_rank
** Description: mutator for rank
** Input: int r
** Output: None
******************************************************/
	rank = r;
}
void Card::set_suit(int s) {
/******************************************************
** Name: set_suit
** Description: mutator for suit
** Input: int s
** Output: None
******************************************************/
	suit = s;
}

Card& Card::operator=(const Card c) {
/******************************************************
** Name: operator=
** Description: assignment operator overload
** Input: Card c
** Output: this card
******************************************************/
	rank = c.rank;
	suit = c.suit;
	return *this;
}

void Card::print_card() {
/******************************************************
** Name: print_card
** Description: print this card
** Input: None
** Output: None
******************************************************/
	string suits[] = { "Diamonds","Clubs","Hearts","Spades" };
	string values[] = { "Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King" };
	cout << values[rank] << " of " << suits[suit] << endl;
}
