//MENU.CPP

/*
John Barbonio
0518876
3 February 2020
CSIS 123A-3694
Professor Rickman
Assignment 3: Overloaded Functions
*/

#include <iostream>
#include <conio.h>
//removed cstdlib from old strcpy

using namespace std;

#include "Menu.h"

Menu::Menu()
	: count(0)
{

}
void Menu::addMenu(const string Description, void (*f)(void))	//in order for this to use string instead of char* array, the string cannot be a pointer as it won't work
{
	if (count < MAXCOUNT)
	{
		this->mi[count].func = f;
		this->mi[count].descript = Description;
		count++;
	}
}
void Menu::runMenu()
{
	for (;;)
	{
		system("CLS");
		for (int i = 0; i < count; i++)
		{
			cout << this->mi[i].descript << endl;
		}
		runSelection();
	}
}
void Menu::runSelection()
{
	int select;
	cin >> select;
	if (select <= count)
		this->mi[select - 1].func();
}
void Menu::waitKey()
{

	cout << "Press any key to continue" << endl;
	while (!_kbhit()); // kbhit is depricated. use _kbhit

	fflush(stdin);
}