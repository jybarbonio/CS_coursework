/*
John Barbonio
0518876
4/11/2018
Assignment 6: More Complex Types
*/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

#include "Menu.h"
#include "Integer.h"
#include "Double.h"

void doubleAdd();
void func2();
void func3();
void Exit();

int main() 
{

	Menu m;
	m.addMenu("1. Add Doubles", doubleAdd);
	m.addMenu("2. Function2 ", func2);
	m.addMenu("3. Function3 ", func3);
	m.addMenu("4. EXIT ", Exit);

	m.runMenu();

}
void doubleAdd() 
{
	string c;
	Double db1(3.14), db3;
	cout << db1.add(3.14).toDouble() << endl;
	Menu m;		//just seeing how I can put cout << endl in a function to be called rather than retyping it three times
	m.skip();
	system("pause");
}
void func2()
{
	string c;
	cout << "hello from func2";
	Menu m;
	m.skip();
	system("pause");
}
void func3()
{
	string c;
	cout << "hello from func3";
	Menu m;
	m.skip();
	system("pause");
}
void Exit()
{
	cout << "Exit";
	cout << endl;
	system("pause");
	exit(0);
}