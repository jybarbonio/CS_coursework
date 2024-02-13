/*
John Barbonio
CSIS 123A-3694
Proffesor Rickman
Assignment 1 - Creating a Menu
*/

#include <iostream>
#include <conio.h>
//removed cstdlib from old strcpy

using namespace std;

#include "Menu.h"

void func1();
void func2();
void func3();
void Exit();

Menu m;	/*is it ok if this is in the field and not within the main method like what Stevenson did?
		I need it here to use waitKey properly*/

int main() 
{

	m.addMenu("1. Function 1 ", func1);
	m.addMenu("2. Function 2 ", func2);
	m.addMenu("3. Function 3 ", func3);
	m.addMenu("4. Exit ", Exit);

	m.runMenu();
}
void func1()	/*removed the "seemingly" unnecessary cin statements and chars and replaced them with waitKey, functionality seems the same
				if not better since there isn't the extra cinput*/
{
	cout << "hello from function 1" << endl;
	m.waitKey();
}
void func2() 
{
	cout << "hello from function 2" << endl;
	m.waitKey();
}
void func3()
{
	cout << "hello from function 3" << endl;
	m.waitKey();
}
void Exit()
{
	cout << "Goodbye" << endl;
	exit(0);
}