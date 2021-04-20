/******************************************************
** Program: hand.cpp
** Author: Patrick Liang
** Date: 04/25/2020
** Description: Hand class function implementation file
** Input: hand.h
** Output: None
******************************************************/
#include "hand.h"
#include <iostream>

using namespace std;

Hand::Hand() {
/******************************************************
** Name: Hand
** Description: Default constructor for the hand class
** Input: None
** Output: None
******************************************************/
	n_cards = 7;
	cards = new Card[n_cards];
}

void Hand::get_hand(int& index, Deck d) {
/******************************************************
** Name: get_hand
** Description: getting the first 7 cards from the deck
** Input: deck_index and the deck
** Output: None
******************************************************/
	for (int i = 0; i < n_cards; i++) {
		cards[i] = d.pass_card(index);
		index++;
	}
}

Card Hand::play_card(int index) {
/******************************************************
** Name: play_card
** Description: playing a card and getting rid of that card from the hand
** Input: index for hand
** Output: The card being played
******************************************************/
	n_cards--;
	Card temp;
	temp = cards[index];
	if (n_cards == 0) {
		return temp;
	}
	Card* c = new Card[n_cards];
	int j = 0;
	for (int i = 0; i < n_cards; i++) {
		if (i == index) {
			j++;
		}
		c[i] = cards[j];
		j++;
	}
	delete[] cards;
	cards = c;
	return temp;
}

void Hand::draw_card(Card given) {
/******************************************************
** Name: draw_card
** Description: drawing a card and adding that card to the hand
** Input: a card from the deck
** Output: None
******************************************************/
	n_cards++;
	Card* c = new Card[n_cards];
	for (int i = 0; i < (n_cards - 1); i++) {
		c[i] = cards[i];
	}
	c[n_cards - 1] = given;
	delete[] cards;
	cards = c;
}

bool Hand::check(Card top) {
/******************************************************
** Name: check
** Description: check if any of the cards in the hand can be played
** Input: the top card in the pile
** Output: A boolean variable
******************************************************/
	for (int i = 0; i < n_cards; i++) {
		if (cards[i].get_rank() == top.get_rank()) {
			return true;
		}
		if (cards[i].get_suit() == top.get_suit()) {
			return true;
		}
		if (cards[i].get_rank() == 7) {
			return true;
		}
	}
	return false;
}

void Hand::print_hand() {
/******************************************************
** Name: print_hand
** Description: Print every card in the hand
** Input: None
** Output: None
******************************************************/
	cout << "You have " << n_cards << " cards." << endl;
	for (int i = 0; i < n_cards; i++) {
		cout << "[" << i << "] ";
		cards[i].print_card();
	}
}

int Hand::get_n_cards() {
/******************************************************
** Name: get_n_hands
** Description: getter for how many cards in the hand
** Input: None
** Output: int n_cards;
******************************************************/
	return n_cards;
}

Card Hand::pass_card(int hand_index) {
/******************************************************
** Name: pass_card
** Description: pass a card in the end
** Input: hand_index
** Output: The card selected
******************************************************/
	return cards[hand_index];
}
Hand::~Hand() {
/******************************************************
** Name: ~Hand
** Description: Destructor for the hand class, deleting the cards array
** Input: None
** Output: None
******************************************************/
	delete[] this->cards;
}