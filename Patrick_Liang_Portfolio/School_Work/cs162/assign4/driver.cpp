/******************************************************
** Program: driver.cpp
** Author: Patrick Liang
** Date: 05/22/2020
** Description: driver function for wumpus game
** Input: player.h
** Output: None
******************************************************/
#include "player.h"
#include <string>

using namespace std;

int main(int argc, char** argv) {
/******************************************************
** Name: main
** Description: driver function
** Parameter: argc, argv
******************************************************/
	if (argc != 3 || stoi(argv[1]) < 4) {
		cout << "Invalid command arguments" << endl;
		return 0;
	}
	int i = 2;
	do{
		Player p1(stoi(argv[1]));
		p1.assign_room();
		p1.turn(argv[2][0], i);
	}while (i == 2);
	return 0;
}
