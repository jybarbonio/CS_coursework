//MENU.CPP

/*
John Barbonio
0518876
10 February 2020
CSIS 123A-3694
Professor Rickman
Assignment 4: Vectors
*/

#include <iostream>
#include <conio.h>
//removed cstdlib from old strcpy

using namespace std;

#include "Menu.h"

Menu::Menu()
{

}
void Menu::addMenu(const string Description, void (*f)(void))	//in order for this to use string instead of char* array, the string cannot be a pointer as it won't work
{
	menuItem temp;		/*Thanks to Roosevelt in the Discussion for helping with this, I was trying earlier on to directly pass the parameters
	to the mi.push_back(Description, f) but it wasn't working and I got stuck*/
	temp.func = f;
	temp.descript = Description;
	this->mi.push_back(temp);
}
void Menu::runMenu()
{
	for (;;)
	{
		system("CLS");
		for (int i = 0; i < mi.size(); i++)		//basically the dynamic maxcount
		{
			cout << this->mi[i].descript << endl;	//not sure if this is the right way to index, I'm playing it safe and I'm not quite sure how to use a vector iterator
		}
		runSelection();
	}
}
void Menu::runSelection()
{
	int select;
	cin >> select;
	if (select <= mi.size())
		this->mi[select - 1].func();
}
void Menu::waitKey()
{

	cout << "Press any key to continue" << endl;
	while (!_kbhit()); // kbhit is depricated. use _kbhit

	fflush(stdin);
}