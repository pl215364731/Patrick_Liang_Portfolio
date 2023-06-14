Name: Patrick Liang
ONID: 933288774
Section: CS 161-020
Assignment 5, due 3/8/2020

Description:

This program is a monster treasure chest. You can add, remove, randomly 
generate, swap, and display a monster in this chest. Each monster has a
name, number of hands, its threat level, and its value.

Instructions:

1) Compile the program with

g++ assign5_treasure.cpp -o assign5_treasure

2) Run the program with

./assign5_treasure

3) The program will start of by asking you the size of the treasure chest.
Input the number of rows and columns to show the menu. After inputting the
size, you should see something like this:
[][][][][]
[][][][][]
[][][][][]
[][][][][]
Total value of 0 items: $0

1) Add monster
2) Remove monster
3) Add random monster
4) Display monster
5) Swap monster
6) Quit

Each option will prompt you to input the location you want to work with. If 
you choose 3, the program will prompt you with:
Enter row:
Enter column:

And then it will random generate all the variables of that monster and store
it in the location given by you.

4) Limitations:
-Inputs cannot be letters when it is asking for menu options or location of the
monster.
-There is no way to change the size of the chest.