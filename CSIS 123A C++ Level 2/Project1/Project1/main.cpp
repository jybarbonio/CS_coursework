/*
John Barbonio
0518876
1 September, 2018
Assignment 8: The While Loop
*/

#include <iostream>
#include <random>
#include <ctime>
#include <ctype.h>

using namespace std;

int main()
{
	char ht;		//heads or tails option char
	char yn;		//yes or no to play and for replays
	int coin;		//the coin denominated by 0 heads 1 tails
	int bank = 10;		//player starts with a bank of $10
	bool state = false;		//game is set not to run until user chooses it to run

	cout << "Welcome to coin flipper. Each game costs $1.\n";
	cout << "A correct guess wins you $2!\n";
	cout << "\nWould you like to play?(y/n?)\n";

	cin >> yn;		//gets user input to play or not
	switch(toupper(yn))		//get char input Y or N regardless of capitalization
	{
	case 'Y':		//case Y sets gamestate to true
		state = true;
		cout << "\nOK!\n";
				break;
	case 'N':		//otherwise gamestate is false
		cout << "\nNow closing. You have $" << bank << endl;
		state = false;
		break;
	default:
		cout << "invalid input\nnow closing\n";
		state = false;
	}

	while(state)		//while loop for game to be repeated
	{
		srand(static_cast<unsigned int>(time(0)));		//random seeding?
		cout << "Your bank is $" << bank << endl;		//tells you your current money

		cout << "Heads or tails? This costs $1 (h/t)\n";		//asks player to choose a coin side (0 or 1)
		coin = rand() % 2;		//random 0 or 1 coin toss
		//cout << coin << endl; // used for cheating to see heads or tails before answer (used for debugging)
		bank--;		//it costs a dollar to play
		cin >> ht;	//gets heads or tails input

		switch(toupper(ht))
		{
		case 'H':
			if (coin == 0)		//if coin is == 0 (heads), then player wins $2, if it was a 1, then player loses
			{
				bank += 2;		//the conditional operator was not friendly to both a cout statement and a logical operator
				cout << "Congrats! You won $2 You now have $" << bank << endl;
			}
			else 
			{
				cout << "Sorry, it was a tails. Good luck next time!\n";
			}
			break;
		case 'T':
			if (coin == 1)		//if coin == 1 (tails), then they win $2, otherwise the player loses
			{
				bank += 2;		//the conditional operator was not friendly to both a cout statement and a logical operator
				cout << "Congrats! You won $2 You now have $" << bank << endl;
			}
			else
			{
				cout << "Sorry, it was a heads. Good luck next time!\n";
			}
			break;
		default:
			cout << "Invalid input. Defaulted to heads. ";		//if input is not an h or t, then input defaults to h
			if (coin == 0)
			{
				bank += 2;
				cout << "Congrats! You won $2 You now have $" << bank << endl;
			}
			else
			{
				cout << "Sorry, it was a tails. Good luck next time!\n";
			}
		}

		cout << "\nReplay?\n";
		cin >> yn;
		cout << endl;		//for console neatness

		switch(toupper(yn))		//yes or no option to replay
		{
		case 'Y':
			state = true;
			break;
		case 'N':
			cout << "Thank you for playing! You now have $" << bank << endl;
			state = false;
			break;
		default:
			cout << "invalid input. Thank you for playing! You now have $" << bank << endl;
			state = false;
		}
		if (bank == 0)		//checks if player is out of money, kicks them out
		{
			cout << "You're outta money! Get outta here!\n";
			state = false;
		}
	}

	system("pause");		//needed because VS keeps auto closing
	return 0;
}