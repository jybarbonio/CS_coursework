#include <iostream>
#include <ctime>
#include <string>

using namespace std;

struct Player //these struc defs need to go first before the prototyping so that the prototypes recognize the "Player" type
{
	char Name[50];
	double average;
};

void printPlayerAverage(Player p, string player[], int avg[]);
void getPlayerAverage(Player* plr, string player[], int avg[]);

int main()
{
	Player p, p1;

	string player[5];
	int avg[5];

	getPlayerAverage(&p, player, avg);
	p1 = p;

	system("pause");
	return 0;
}
void getPlayerAverage(Player* plr, string player[], int avg[])
{
	for (int i = 0; i < 5; i++)
	{
		cout << "Enter the player's name" << endl;
		cin >> plr->Name;

		cout << "Enter the player's average" << endl;
		cin >> plr->average;

		player[i] = plr->Name;
		avg[i] = plr->average;
	}
	Player p1 = *plr;

	printPlayerAverage(p1, player, avg);
}
void printPlayerAverage(Player p, string player[], int avg[])
{
	for (int i = 0; i < 5; i++)
	{
		cout << player[i] << " is hitting " << avg[i] << endl;
	}
}