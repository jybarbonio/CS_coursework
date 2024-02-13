/*
John Barbonio
0518876
18 November 2018
Assignment 1 Recursion
*/

#include <iostream>
#include "Menu.h"
#include "Double.h"
#include "Integer.h"

#include <chrono>
#include <thread>

using namespace std;

using john::Menu;
using john::Double;
using john::Integer;

void doubleAdd();
void doubleSub();
void doubleMul();
void doubleDiv();
void Exit();

int main()
{
	Menu *m = Menu::Instance();
	m->addMenu("1. Add ", doubleAdd);
	m->addMenu("2. Sub ", doubleSub);
	m->addMenu("3. Mul ", doubleMul);
	m->addMenu("4. Div ", doubleDiv);
	m->addMenu("5. EXIT ", Exit);

	m->runMenu();

	system("pause");
	return 0;
}
void doubleAdd()
{
	Double d1("1.234");
	d1.equals(1.234);
	cout << d1.toString() << endl;


	cout << d1 << endl;

	Menu *m = Menu::Instance();
	m->waitKey();
}
void doubleSub()
{
	Double d(10), d3;
	d3 = d.sub(2.5);
	d3.print();

	Integer i(8), i3;
	i3 = i.sub(10);
	i3.print();
	Menu *m = Menu::Instance();
	m->waitKey();
}
void doubleMul()
{
	Double d(10.5), d3;
	d3 = d.mul(4);
	d3.print();

	Integer i(5), i3;
	i3 = i.mul(5);
	i3.print();
	Menu *m = Menu::Instance();
	m->waitKey();
}
void doubleDiv()
{
	Double d(60), d3;
	d3 = d.div(5);
	d3.print();

	Integer i(10), i3;
	i3 = i.div(5);
	i3.print();
	Menu *m = Menu::Instance();
	m->waitKey();
}
void Exit()
{
	cout << "Exiting";
	for (int i = 0; i < 2; i++)
	{
		for (int i = 0; i < 4; i++)
		{
			char p = 124;
			char p2 = 47;
			char p3 = 45;
			char p4 = 92;

			this_thread::sleep_for(chrono::milliseconds(60));
			system("CLS");
			cout << p;
			this_thread::sleep_for(chrono::milliseconds(60));
			system("CLS");
			cout << p2;
			this_thread::sleep_for(chrono::milliseconds(60));
			system("CLS");
			cout << p3;
			this_thread::sleep_for(chrono::milliseconds(60));
			system("CLS");
			cout << p4;
		}
	}
	system("CLS");
	cout << "Done!" << endl;
	this_thread::sleep_for(chrono::milliseconds(100));
	exit(0);
}
