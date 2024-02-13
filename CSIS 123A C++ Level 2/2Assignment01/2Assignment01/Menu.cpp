#include <iostream>
#include <cstdlib>
#include <string>
#include <conio.h>

using namespace std;

#include "Menu.h"

Menu::Menu()
	: count(0)
{

}
void Menu::addMenu(const char *Description, void(*f)(void))
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
	cout << "Please select a function by typing its number" << endl;
	cin >> select;
	select -= 1;
	this->mi[select].func();
}
void Menu::waitKey()
{

	cout << "Press any key to continue" << endl;
	while (!_kbhit());

	fflush(stdin);
}