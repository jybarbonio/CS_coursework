//MENU.H

/*
John Barbonio
0518876
21 January 2020
CSIS 123A-3694
Professor Rickman
Assignment 2 - Class Construction
*/

#ifndef MENU
#define MENU

const int MAXCOUNT = 20;
struct menuItem
{
	void (*func)();
	string descript;
};
class Menu
{
private:
	menuItem mi[MAXCOUNT];
	int count;
	void runSelection();
public:
	Menu();
	void addMenu(const string Description, void (*f)());
	void runMenu();
	void waitKey();
};

#endif
