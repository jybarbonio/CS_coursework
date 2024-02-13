#ifndef MENU		//a header file does nothing more than keep track of definitions
#define MENU

#include <string>

const int MAXCOUNT = 20;
struct menuItem
{
	void(*func) ();
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
	void addMenu(const char *Description, void(*f)());
	void runMenu();
	void waitKey();

};

#endif