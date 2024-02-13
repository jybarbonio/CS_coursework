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
	static Menu *pInstance;
	vector <menuItem> mi;
	void runSelection();
public:
	Menu();
	void addMenu(string Description, void(*f)());
	void runMenu();
	void waitKey();
	static Menu *Instance();
};
#endif