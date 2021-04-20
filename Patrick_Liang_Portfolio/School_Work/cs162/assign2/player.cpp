/******************************************************
** Program: player.cpp
** Author: Patrick Liang
** Date: 04/25/2020
** Description: Player class function implementation file
** Input: player.h
** Output: None
******************************************************/
#include "player.h"
#include <iostream>

Player::Player() {
	
}

Hand& Player::get_hand() {
/******************************************************
** Name: get_hand
** Description: getter for hand in the player class
** Input: None
** Output: None
******************************************************/
	return hand;
}

int Player::bot_card(Card top) {
/******************************************************
** Name: bot_card
** Description: The function that makes the bot plays the first card it can play
** Input: Card top
** Output: an integer that is an index to the computer's hand
******************************************************/
	for (int i = 0; i < hand.get_n_cards(); i++) {
		if (top.get_rank() == 7) {
			if (hand.pass_card(i).get_suit() == top.get_suit()) {
				return i;
			}
			if (hand.pass_card(i).get_rank() == 7) {
				return i;
			}
		}
		else {
			if (hand.pass_card(i).get_rank() == top.get_rank()) {
				return i;
			}
			if (hand.pass_card(i).get_suit() == top.get_suit()) {
				return i;
			}
			if (hand.pass_card(i).get_rank() == 7) {
				return i;
			}
		}
	}
}

