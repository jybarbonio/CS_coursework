#include <iostream>
#include "slist.h"
using namespace std;

int main()
{
	try 
	{
		slist sl;
		sl.addFront(4);
		sl.addRear(6);
		sl.addRear(7);
		sl.addRear(8);
		sl.displayAll();
		cout << "6 found at index " << sl.search(6) << endl;

		sl.replace(0, 2);								// print index of searched-for elem 6
		sl.displayAll();											// print list
		cout << "8 found at index " << sl.search(8) << endl;		// print index of searched-for elem
		sl.replace(2, sl.search(8));								// replace pos 4 with elem 2
		sl.displayAll();											// print list
		cout << "X found at index " << sl.search(5) << endl;		// print index of searched-for elem 5, should not be found
		sl.replace(10, 7);											// replace pos 7 with elem 10, pos does not exist so it should error
	}
	catch (llist::Underflow u) 
	{
		cout << u.getUnderflowError() << endl;
		//exit(1);
	}
	catch (llist::OutOfRange o) 
	{
		cout << o.getOutOfRangeError() << endl;
		//exit(1);
	}
}