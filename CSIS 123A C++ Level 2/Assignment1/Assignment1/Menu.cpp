#include <iostream>
#include <cstdlib>
#include <string>
#include <conio.h>
#include <vector>

using namespace std;

#include "Menu.h"

Menu::Menu()
{

}
Menu *Menu::pInstance = NULL;
Menu *Menu::Instance() 
{
	if (pInstance == NULL)
		pInstance = new Menu;
}
void Menu::addMenu(string Description, void (*f)()) 
{
	menuItem temp;
	temp.func = f;
	temp.descript = Description;
	this->mi.push_back(temp);
	count++;
}
void Menu::runMenu() 
{
	for(;;) 
	{
		system("CLS");
		for(int i = 0; i < count; i++)
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
	if (select <= count)
		this->mi[select - 1].func();
}
void Menu::waitKey()
{

	cout << "Press any key to continue" << endl;
	while (!_kbhit());
	_getch();
	fflush(stdin);
}
