/******************************************************
** Program: player.cpp
** Author: Patrick Liang
** Date: 05/22/2020
** Description: Player class cpp file
** Input: player.h
** Output: None
******************************************************/
#include "player.h"
#include <iostream>
#include <ctime>
#include <string>
#include <stdlib.h>

using namespace std;

Player::Player(int s) {
/******************************************************
** Name: Player
** Description: player class constructor
** Parameter: int size of the map
******************************************************/
	srand(time(NULL));
	size = s;
	row = rand() % size;
	col = rand() % size;
	e_row = row;
	e_col = col;
	arrows = 3;
	game_over = false;
	gold = false;
	wumpus = true;
	for (int i = 0; i < size; i++) {
		vector<Room> temp;
		cave.push_back(temp);
		for (int j = 0; j < size; j++) {
			Room r;
			cave[i].push_back(r);
		}
	}
}

void Player::input(string& s) {
/******************************************************
** Name: input
** Description: get a string from the input stream
** Parameter: string s
******************************************************/
	getline(cin, s);
}

void Player::find_empty_room(int& x, int& y) {
/******************************************************
** Name: find_empty_room
** Description: find a room with no events
** Parameter: int x, int y
******************************************************/
	srand(time(NULL));
	do {
		x = rand() % size;
		y = rand() % size;
	} while ((y == col && x == row) || (y == e_col && x == e_row) || (cave[x][y].get_event() != NULL));
}

void Player::assign_room() {
/******************************************************
** Name: assign_room
** Description: randomly assign the right amount of events to the map
** Parameter: None
******************************************************/
	int x, y;
	find_empty_room(x, y);
	cave[x][y].set_event(&b);
	find_empty_room(x, y);
	cave[x][y].set_event(&g);
	find_empty_room(x, y);
	cave[x][y].set_event(&p);
	find_empty_room(x, y);
	cave[x][y].set_event(&w);
	find_empty_room(x, y);
	cave[x][y].set_event(&b);
}

void Player::print_grid_line() {
/******************************************************
** Name: print_grid_line
** Description: print part of the map
** Parameter: None
******************************************************/
	cout << "+";
	for (int i = 0; i < size; i++)
		cout << "---+";
	cout << "\n";
}

void Player::print_grid_space(int r) {
/******************************************************
** Name: print_grid_space
** Description: print part of the map
** Parameter: int r
******************************************************/
	cout << "|";
	for (int i = 0; i < size; i++) {
		if (i == col && r == row) {
			cout << " * |";
		}
		else {
			cout << "   |";
		}
	}
	cout << "\n";
}

void Player::print_grid() {
/******************************************************
** Name: print_grid
** Description: using above functions, print the whole map
** Parameter: None
******************************************************/
	print_grid_line();
	for (int i = 0; i < size; i++) {
		print_grid_space(i);
		print_grid_line();
	}
}

void Player::cheat_grid_space(int r) {
/******************************************************
** Name: cheat_grid_space
** Description: print part of cheat view of the map
** Parameter: int r
******************************************************/
	cout << "|";
	for (int i = 0; i < size; i++) {
		if (i == col && r == row)
			cout << " * |";
		else if (i == e_col && r == e_row)
			cout << " e |";
		else if (cave[r][i].get_event() != NULL) {
			if (cave[r][i].get_name() == "bat")
				cout << " b |";
			if (cave[r][i].get_name() == "pit")
				cout << " p |";
			if (cave[r][i].get_name() == "gold") {
				if (gold == false)
					cout << " g |";
				else 
					cout << "   |";
			}
			if (cave[r][i].get_name() == "wumpus") {
				if (wumpus == true)
					cout << " w |";
				else
					cout << "   |";
			}
				
		}
		else
			cout << "   |";
	}
	cout << "\n";
}

void Player::cheat_grid() {
/******************************************************
** Name: cheat_grid
** Description: print cheat view of the map
** Parameter: None
******************************************************/
	print_grid_line();
	for (int i = 0; i < size; i++) {
		cheat_grid_space(i);
		print_grid_line();
	}
}

void Player::move() {
/******************************************************
** Name: move
** Description: a move player function with error handling
** Parameter: None
******************************************************/
	string s;
	bool b = true;
	while (b) {
		input(s);
		switch (s[0]) {
		case 'w':
			if ((row - 1) < 0)
				continue;
			row -= 1;
			b = false;
			break;
		case 'a':
			if ((col - 1) < 0)
				continue;
			col -= 1;
			b = false;
			break;
		case 's':
			if ((row + 1) >= size)
				continue;
			row += 1;
			b = false;
			break;
		case 'd':
			if ((col + 1) >= size)
				continue;
			col += 1;
			b = false;
			break;
		case ' ': arrow(s[1]);
			break;
		default:
			cout << "Invalid Input" << endl;
			break;
		}
	}
}

void Player::check_wumpus(int r, int c) {
/******************************************************
** Name: check_wumpus
** Description: check if the arrow hits the wumpus
** Parameter: int r, int c
******************************************************/
	if (cave[r][c].get_event() != NULL) {
		if (cave[r][c].get_name() == "wumpus") {
			wumpus = false;
			(cave[r][c].get_event())->set_w();
			cout << "You killed the wumpus" << endl;
		}
	}
}

void Player::wumpus_run() {
/******************************************************
** Name: wumpus_run
** Description: if the wumpus is still alive, it might run away
** Parameter: None
******************************************************/
	if (wumpus == true) {
		srand(time(NULL));
		int r = rand() % 4;
		if (r == 0) {
			return;
		}
		else {
			int x = 0, y = 0;
			find_empty_room(x, y);
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					if (cave[i][j].get_event() != NULL) {
						if (cave[i][j].get_name() == "wumpus") {
							cave[i][j].set_event(NULL);
						}
					}
				}
			}
			cave[x][y].set_event(&w);
		}
	}
}

void Player::arrow(char c) {
/******************************************************
** Name: arrow
** Description: takes in a direction and fire the arrow
** Parameter: char c
******************************************************/
	arrows--;
	if (arrows < 0) {
		cout << "You have no arrows left" << endl;
		return;
	}
	else {
		cout << "You fired an arrow, you have " << arrows << " arrow(s) left" << endl;
	}
	switch (c) {
	case 'w':
		for (int i = 1; i <= 3; i++) {
			if (row - i < 0)
				break;
			check_wumpus(row - i, col);
		}
		wumpus_run();
		break;
	case 'a':
		for (int i = 1; i <= 3; i++) {
			if (col - i < 0)
				break;
			check_wumpus(row, col - i);
		}
		wumpus_run();
		break;
	case 's':
		for (int i = 1; i <= 3; i++) {
			if (row + i == size - 1)
				break;
			check_wumpus(row + i, col);
		}
		wumpus_run();
		break;
	case 'd':
		for (int i = 1; i <= 3; i++) {
			if (col + i == size - 1)
				break;
			check_wumpus(row, col + i);
		}
		wumpus_run();
		break;
	default:
		cout << "Invalid Input" << endl;
		break;
	}
}

void Player::percept() {
/******************************************************
** Name: percept
** Description: The print percept function that checks every adjacent room
** Parameter: None
******************************************************/
	if ((row - 1) >= 0) {
		if (cave[row - 1][col].get_event() != NULL)
			cave[row - 1][col].percept();
	}
	if ((row + 1) < size) {
		if (cave[row + 1][col].get_event() != NULL)
			cave[row + 1][col].percept();
	}
	if ((col - 1) >= 0) {
		if (cave[row][col - 1].get_event() != NULL)
			cave[row][col - 1].percept();
	}
	if ((col + 1) < size) {
		if (cave[row][col + 1].get_event() != NULL)
			cave[row][col + 1].percept();
	}
}

void Player::encounter() {
/******************************************************
** Name: encounter
** Description: the master encounter function
** Parameter: None
******************************************************/
	if (cave[row][col].get_event() != NULL) {
		cave[row][col].encounter();
		if (cave[row][col].get_name() == "pit")
			game_over = true;
		if (cave[row][col].get_name() == "wumpus") {
			if(wumpus == true)
				game_over = true;
		}	
		if (cave[row][col].get_name() == "bat") {
			srand(time(NULL));
			row = rand() % size;
			col = rand() % size;
			encounter();
			return;
		}
		if (cave[row][col].get_name() == "gold") {
			gold = true;
			return;
		}
	}
	if (row == e_row && col == e_col && gold == true) {
		cout << "You have successfully escaped from the cave!" << endl;
		game_over = true;
	}
}

void Player::turn(char a, int& i) {
/******************************************************
** Name: turn
** Description: a function that goes through the turns of a player
** Parameter: char a, int i
******************************************************/
	while (game_over == false) {
		percept();
		if (a == 'f') {
			print_grid();
		}
		else {
			cheat_grid();
		}
		move();
		encounter();
	}
	restart(a, i);
}

void Player::same_map() {
/******************************************************
** Name: same_map
** Description: if the player decides to play the same map, this function resets everything
** Parameter: None
******************************************************/
	game_over = false;
	row = e_row;
	col = e_col;
	gold = false;
	wumpus = true;
	arrows = 3;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if(cave[i][j].get_event() != NULL)
				cave[i][j].reset();
		}
	}
	cin.clear();
	cin.ignore(256, '\n');
}

void Player::restart(char a, int& i) {
/******************************************************
** Name: restart
** Description: restart function used at the end of the game
** Parameter: char a, int i
******************************************************/
	cout << "Would you like to play again?" << endl;
	cout << "[1]Restart with the same map\n[2]Restart with a different map\n[3]Exit\n";
	cin >> i;
	switch (i) {
	case 1: same_map();
		turn(a, i);
		break;
	case 2: cin.clear();
		cin.ignore(256, '\n');
		return;
		break;
	case 3: return;
		break;
	default:
		cout << "Invalid Input" << endl;
		break;
	}
}