/******************************************************
** Program: game.cpp
** Author: Patrick Liang
** Date: 04/25/2020
** Description: Game class function implementation file
** Input: game.h
** Output: None
******************************************************/
#include "game.h"
#include "card.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

Game::Game(int& deck_index) {
/******************************************************
** Name: Game
** Description: constructor for the game class. Shuffles the deck,
** and deal 7 cards to each player. The next card in the deck becomes
** the top card in the pile.
** Input: deck_index
** Output: None
******************************************************/
	cards.shuffle();
	players[0].get_hand().get_hand(deck_index, cards);
	players[1].get_hand().get_hand(deck_index, cards);
	top = cards.pass_card(deck_index);
	deck_index++;
}

void Game::input(int& player_index) {
/******************************************************
** Name: input
** Description: get input from the user
** Input: player_index
** Output: None
******************************************************/
	cin >> player_index;
	bool b = true;
	while(b){
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid input" << endl;
			cin >> player_index;
		}
		else {
			break;
		}
	}
}

void Game::error_handle(int& player_index) {
/******************************************************
** Name: error_handle
** Description: check if the card the player wanted to play is playable
** Input: player_index
** Output: None
******************************************************/
	bool b = true;
	while (b) {
		input(player_index);
		if (player_index >= players[0].get_hand().get_n_cards()) {
			cout << "You don't have that many cards, try again" << endl;
			continue;
		}
		if (players[0].get_hand().pass_card(player_index).get_rank() == 7) {
			b = false;
			continue;
		}
		if (players[0].get_hand().pass_card(player_index).get_rank() != top.get_rank()) {
			if (players[0].get_hand().pass_card(player_index).get_suit() != top.get_suit()) {
				cout << "You can't play this card" << endl;
				continue;
			}
		}
		if (players[0].get_hand().pass_card(player_index).get_rank() == top.get_rank()) {
			b = false;
		}
		if (players[0].get_hand().pass_card(player_index).get_suit() == top.get_suit()) {
			b = false;
		}	
	}
}

void Game::users_play(int& player_index) {
/******************************************************
** Name: users_play
** Description: playing part of user's turn, including suit selection for the wild card
** Input: player_index
** Output: None
******************************************************/
	players[0].get_hand().print_hand();
	error_handle(player_index);
	top = players[0].get_hand().play_card(player_index);
	if (top.get_rank() == 7) { //if the card is 8
		cout << "What suit do you want your opponent to play next?" << endl;
		string suits[] = { "Diamonds","Clubs","Hearts","Spades" };
		cout << "[0]Diamonds\n[1]Clubs\n[2]Hearts\n[3]Spades" << endl;
		input(player_index);
		top.set_suit(player_index);
	}
}

bool Game::users_turn(int & deck_index, int& player_index) {
/******************************************************
** Name: users_turn
** Description: This function goes through one user's turn
** Input: deck_index, player_index
** Output: returns true or false depending on if the player gets to play a card
******************************************************/
	cout << "\nThe top card is:";
	top.print_card(); //prints the top card
	cout << "\n";
	while (!(players[0].get_hand().check(top))) {
		cout << "You need to draw a card" << endl;
		players[0].get_hand().draw_card(cards.pass_card(deck_index));
		deck_index++;
		if (deck_index == 52) {
			cout << "All cards have been drawn" << endl;
			return false;
		}
	}
	users_play(player_index);
	return true;
}

bool Game::coms_turn(int & deck_index) {
/******************************************************
** Name: coms_turn
** Description: This function goes through one computer's turn
** Input: deck_index
** Output: returns true or false depending on if the computer gets to play a card
******************************************************/
	while (!(players[1].get_hand().check(top))) {
		players[1].get_hand().draw_card(cards.pass_card(deck_index));
		deck_index++;
		if (deck_index == 52) {
			cout << "All cards have been drawn" << endl;
			return false;
		}
	}

	int i = players[1].bot_card(top);
	top = players[1].get_hand().play_card(i);
	if (top.get_rank() == 7) {
		string suits[] = { "Diamonds","Clubs","Hearts","Spades" };
		srand(time(NULL));
		int j = rand() % 4;
		cout << "The computer played an 8, it picked " << suits[j] << endl;
		top.set_suit(j);
	}
	return true;
}

void Game::compare_n_cards() {
/******************************************************
** Name: compare_n_cards
** Description: When all cards are drawn, compare the amount
** of cards in each player's hand, the player with the least 
** amount of cards win.
** Input: None
** Output: print who wins
******************************************************/
	if (players[0].get_hand().get_n_cards() < players[1].get_hand().get_n_cards()) {
		cout << "You win!" << endl;
	}
	else if (players[1].get_hand().get_n_cards() < players[0].get_hand().get_n_cards()) {
		cout << "Computer wins!" << endl;
	}
	else {
		cout << "Draw" << endl;
	}
}

void Game::run(int& deck_index, int& player_index) {
/******************************************************
** Name: run
** Description: The flow of the whole game
** Input: deck_index, player_index
** Output: None
******************************************************/
	while (true) {
		bool p1 = users_turn(deck_index, player_index);
		if (players[0].get_hand().get_n_cards() == 0) {
			cout << "You win!" << endl;
			return;
		}
		if (!p1) {
			compare_n_cards();
			return;
		}
		bool p2 = coms_turn(deck_index);
		if ((players[1].get_hand().get_n_cards() == 0)) {
			cout << "Computer wins!" << endl;
			return;
		}
		if (!p2) {
			compare_n_cards();
			return;
		}
	}
}