#ifndef MENU		//a header file does nothing more than keep track of definitions
#define MENU

#include <string>
#include <vector>

struct menuItem
{
void(*func) ();
string descript;
};
class Menu 
{
private:
	vector <menuItem> mi;
	int count;
	void runSelection();
public:
	Menu();
	void addMenu(string Description, void(*f)());
	void runMenu();
	void waitKey();
	void skip();

};

#endif