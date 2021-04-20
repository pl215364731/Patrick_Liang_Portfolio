/******************************************************
** Program: deck.cpp
** Author: Patrick Liang
** Date: 04/25/2020
** Description: Deck class function implementation file
** Input: deck.h
** Output: None
******************************************************/
#include "deck.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

Deck::Deck() {
/******************************************************
** Name: Deck
** Description: Default constructor for the deck class
** Input: None
** Output: A Card array filled with all 52 cards
******************************************************/
	n_cards = 52;
	int card_index = 0;
	for (int i = 0; i < 13; i++) {
		for (int j = 0; j < 4; j++) {
			cards[card_index].set_rank(i);
			cards[card_index].set_suit(j);
			card_index++;
		}
	}
}

void Deck::shuffle() {
/******************************************************
** Name: shuffle
** Description: a function that shuffles the deck
** Input: None
** Output: None
******************************************************/
	srand(time(NULL));
	Deck d;
	for (int i = 0; i < n_cards; i++) {
		int random = rand() % 52;
		while (d.cards[random].get_rank() == -1) {
			random = rand() % 52;
		}
		this->cards[i] = d.cards[random];
		d.cards[random].set_rank(-1);
	}
}

Card Deck::pass_card(int& deck_index) {
/******************************************************
** Name: pass_card
** Description: passing the value of a card in the deck
** Input: deck_index
** Output: None
******************************************************/
	return cards[deck_index];
}