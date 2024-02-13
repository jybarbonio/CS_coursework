#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

#include "Menu.h"
#include "Integer.h"
#include "Double.h"

void func1();
void func2();
void func3();
void Exit();

int main()
{
	Menu m;
	m.addMenu("1. Function1 ", func1);
	m.addMenu("2. Function2 ", func2);
	m.addMenu("3. Function3 ", func3);
	m.addMenu("4. EXIT ", Exit);

	m.runMenu();

}
void func1()
{
	Menu m;
	Double d1(12.2), d3;
	d3 = d1.add(5.3);
	d3.print();
	cout << endl;
	system("pause");
}
void func2()
{
	Menu m;
	cout << "hello from func2";
	cout << endl;
	system("pause");
}
void func3()
{
	Menu m;
	cout << "hello from func3";
	cout << endl;
	system("pause");
}
void Exit()
{
	cout << "Exit";
	cout << endl;
	system("pause");
	exit(0);
}