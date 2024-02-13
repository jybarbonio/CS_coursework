#include <iostream>
#include <string>
#include "Player.h"

using namespace std;

int main()
{
	Player p("glenn", 750);

	cout << p.getName() << " average is " << p.getAverage() << endl;

	system("pause");
	return 0;
}