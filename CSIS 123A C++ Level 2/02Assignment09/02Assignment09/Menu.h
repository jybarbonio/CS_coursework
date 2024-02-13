#ifndef MENU		//a header file does nothing more than keep track of definitions
#define MENU

#include <string>
#include <vector>

using std::string;
using std::vector;

namespace john
{
	const int MAXCOUNT = 20;
	struct menuItem
	{
		void(*func) ();
		string descript;
		vector<int> mi;
	};
	class Menu
	{
	private:
		vector<menuItem> mi;
		int count;
		void runSelection();
		static Menu *pInstance;
	public:
		Menu();
		void addMenu(string Description, void(*f)());
		void runMenu();
		void waitKey();
		static Menu *Instance();
	};
}
#endif
