//MENU.H

/*
John Barbonio
0518876
10 February 2020
CSIS 123A-3694
Professor Rickman
Assignment 4: Vectors
*/

#include <vector>

#ifndef MENU
#define MENU

struct menuItem
{
	void (*func)();
	string descript;
};
class Menu
{
private:
	std::vector<menuItem> mi;
	void runSelection();
public:
	Menu();
	void addMenu(const string Description, void (*f)(void));
	void runMenu();
	void waitKey();
};

#endif
