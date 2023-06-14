/**********************************************************
** Program: assign2_game.cpp
** Authors: Patrick Liang
** Date: 01/26/2020
** Description: make a text adventure game
***********************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int output(string question, string answer)
{
	cout << question << endl;
	cout << answer << endl;
	return 0;

}

int game()
{
	srand(time(NULL));
	short points = 0; /*short is used here because I needed an small integer. Min for short is -32768 and max is 32,767*/
	output("You are a normal college student who just got out of a boring class. \n"
		"You see a girl walking on the opposite sidewalk with a binder in one hand and a phone in another. \n"
		"She is so focused on her phone that she tripped and fell. \n"
		"All the paper in the binder is now lying on the ground. What do you do? \n",
		"[1]Help her pick up her paper \n[2]Keep walking like you saw nothing");

	short input; /*input is only going to be either 1,2 or 3 so short is used. Min for short is -32768 and max is 32,767.*/
	cin >> input;

	if (input == 1) //1
	{
		cout << "\n";
		points += 10;
		output("The girl wants to thank you by buying you a drink, do you want to go with her?\n",
			"[1]Go with her \n[2]Don't go");
		cin >> input;

		if (input == 1)//1,1
		{
			cout << "\n";
			points += 10;
			output("You and the girl sit down at a starbucks.\n"
				"She tells you that her name is Airwrecka.\n"
				"She just moved here this term and is still getting used to the school.\n"
				"Since she just moved here, she has no friends. What do you say?",
				"[1]Things can only get better.\n[2]I can be your friend!");
			cin >> input;

			if (input == 1)//1,1,1
			{
				cout << "\n";
				points -= 100;
				cout << "You have literally picked the worst response." << endl;
				cout << "Your score is " << points << "\nGame Over" << endl;

				return 0;
			}
			else if (input == 2)//1,1,2
			{
				cout << "\n";
				points += 50;
				cout << "Airwrecka is happy to hear you say that!\n"
					"You are also getting excited thinking about all the time you are going to spend with her." << endl;
				cout << "Your score is " << points << "\nCongrats!" << endl;

				return 0;
			}
			else
			{
				cout << "\n";
				cout << "Invalid choice" << endl;
				return 1;
			}
		}
		else if (input == 2)//1,2
		{
			/*no points awarded*/
			cout << "\n";
			cout << "You get back to your dorm and sit down in front of your desk.\n"
				"You try to start your homework but can't help to contemplate on why you feel so lonely...\n"
				"Your score is " << points << "\nGame Over" << endl;
			return 0;
		}
		else
		{
			cout << "\n";
			cout << "Invalid choice" << endl;
			return 1;
		}
	}

	else if (input == 2)//2
	{
		/*no points awarded for this option*/
		cout << "\n";
		output("You are walking back to your dorm, there is a coffee shop on your way back.\n",
			"[1]Go in to the coffee shop \n[2]Keep walking back to your dorm");
		cin >> input;

		if (input == 1)//2,1
		{
			cout << "\n";
			points += 5;
			cout << "You ordered a cup of coffee and sat down at a table.\n"
				"The cashier seem to be staring at you." << endl;
			int randomNumber = rand() % 2;
			if (randomNumber == 0)//2,1,0
			{
				cout << "[1]Confront her\n[2]Pretend you didn't see that" << endl;
				cin >> input;

				if (input == 1)//2,1,0,1
				{
					cout << "\n";
					points += 5;
					output("You ask the cashier why she was staring at you.\n"
						"She tells you that you did not pay for your drink.",
						"[1]Pay for the drink\n[2]Leave the coffee shop");
					cin >> input;

					if (input == 1)//2,1,0,1,1
					{
						/*no points awarded for this option*/
						cout << "\n";
						cout << "You reach into your pocket to get your wallet, but then realizes that you forgot it at home.\n"
							"The girl seems to noticed the fact that you did not bring your wallet from your awkward face expression.\n"
							"To make this less awkward, you decided to leave the shop." << endl;
						cout << "Your score is " << points << "\nGame Over" << endl;
						return 0;
					}
					else if (input == 2)//2,1,0,1,2
					{
						cout << "\n";
						points -= 50;
						cout << "You leave the coffee shop out of embarrassment.\n"
							"Without the coffee, you end up falling asleep after getting back to your dorm, missing all of your classes for the rest of the day." << endl;
						cout << "Your score is " << points << "\nGame Over" << endl;
					}
					else
					{
						cout << "\n";
						cout << "Invalid choice" << endl;
						return 1;
					}
				}
				else if (input == 2)//2,1,0,2
				{
					/*no points awarded for this option*/
					cout << "\n";
					cout << "You sat at the table for 10 minutes and your drink never arrived. \n"
						"You start to wonder why it's taking so long but then you remembered that you never paid. \n"
						"Without the coffee, you end up falling asleep after getting back to your dorm, missing all of your classes for the rest of the day." << endl;
					cout << "Your score is " << points << "\nGame Over" << endl;
				}
			}

			else//2,1,1
			{
				cout << "[1]Stare at her until she comes over and talk to you\n[2]Confront her" << endl;
				cin >> input;

				if (input == 1 || input == 2)
				{
					cout << "\n";
					points += 100;
					cout << "She seems to be nervous when she tries to talk to you.\n"
						"You never understood why until she handed you your coffee latte with a heart drawn onto it." << endl;
					cout << "Your score is " << points << "\nCongrats!" << endl;
				}
			}
		}
		else if (input == 2)//2,2
		{
			cout << "\n";
			cout << "You arrive at your dorm and sit down in front of your desk.\n"
				"You try to start your homework but can't help to contemplate on why you feel so lonely...\n"
				"Your score is " << points << "\nGame Over" << endl;
			return 0;
		}
		else
		{
			cout << "\n";
			cout << "Invalid choice" << endl;
			return 1;
		}
	}
	else
	{
		cout << "\n";
		cout << "Invalid choice" << endl;
		return 1;
	}
}

int main()
{
	short input;

	bool end = true;
	while (end)
	{
		game();
		cout << "\nDo you want to play again?" << endl;
		cout << "[1]Yes [2]No" << endl;
		cin >> input;
		cout << "\n";
		
		if (input != 1)
		{
			end = false;
		}
	}
	return 0;

}