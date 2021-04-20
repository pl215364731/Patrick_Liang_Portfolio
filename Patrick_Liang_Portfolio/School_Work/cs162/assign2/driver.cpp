/******************************************************
** Program: driver.cpp
** Author: Patrick Liang
** Date: 04/25/2020
** Description: Play a game of crazy eights with the computer
** Input: All the classes
** Output: None
******************************************************/
#include <iostream>
#include "card.h"
#include "deck.h"
#include "hand.h"
#include "player.h"
#include "game.h"

using namespace std;

int main() {
	int input = 0;
	while (input == 0) {
		int player_index = 0;
		int index = 0;
		Game game(index);
		game.run(index, player_index);
		cout << "Do you want to play again?" << endl;
		cout << "[0]Yes\n[1]No" << endl;
		cin >> input;
		while (true) {
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
	return 0;
}