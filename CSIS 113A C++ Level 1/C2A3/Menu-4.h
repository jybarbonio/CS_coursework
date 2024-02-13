//MENU.H

/*
John Barbonio
0518876
3 February 2020
CSIS 123A-3694
Professor Rickman
Assignment 3: Overloaded Functions
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
	void addMenu(const string Description, void (*f)(void));
	void runMenu();
	void waitKey();
};

#endif
