/******************************************************
** Program: player.h
** Author: Patrick Liang
** Date: 05/22/2020
** Description: player class header file
** Input: None
** Output: None
******************************************************/
#ifndef player_h
#define player_h
#include <vector>
#include "room.h"
#include "bat.h"
#include "gold.h"
#include "pit.h"
#include "wumpus.h"

using namespace std;

class Player {
private:
	int row;
	int col;
	int e_row;
	int e_col;
	int size;
	vector<vector<Room>> cave;
	int arrows;
	bool gold;
	bool wumpus;
	bool game_over;
	Bat b;
	Gold g;
	Pit p;
	Wumpus w;
public:
	Player(int);
	void input(string&);
	void find_empty_room(int&, int&);
	void assign_room();
	void print_grid_line();
	void print_grid_space(int);
	void print_grid();
	void cheat_grid_space(int);
	void cheat_grid();
	void move();
	void check_wumpus(int, int);
	void wumpus_run();
	void arrow(char);
	void percept();
	void encounter();
	void turn(char, int&);
	void same_map();
	void restart(char, int&);
};

#endif
