//MAIN.CPP

/*
John Barbonio
0518876
3 February 2020
CSIS 123A-3694
Professor Rickman
Assignment 3: Overloaded Functions
*/

#include <iostream>
#include <conio.h>
//removed cstdlib from old strcpy

using namespace std;

#include "Menu.h"
#include "Integer.h"
#include "Double.h"

void func1();
void func2();
void func3();
void func4();
void Exit();

Menu m;	/*is it ok if this is in the field and not within the main method like what Stevenson did?
		I need it here to use waitKey properly*/

int main()
{

	m.addMenu("1. Add", func1);
	m.addMenu("2. Subtract", func2);
	m.addMenu("3. Multiply", func3);
	m.addMenu("4. Divide", func4);
	m.addMenu("5. Exit", Exit);

	m.runMenu();
}
void func1()	/*removed the "seemingly" unnecessary cin statements and chars and replaced them with waitKey, functionality seems the same
				if not better since there isn't the extra cinput*/
{
	Integer i1(13), i3;

	i3 = i1.add(3);
	i3.print();

	Double d1(1.5), d3;

	d3 = d1.add(13);
	d3.print();

	m.waitKey();
}
void func2()
{
	Integer i1(15), i3;

	i3 = i1.sub(5);
	i3.print();

	Double d1(19.5), d3;

	d3 = d1.sub(5);
	d3.print();

	m.waitKey();
}
void func3()
{
	Integer i1(10), i3;

	i3 = i1.mul(3);
	i3.print();

	Double d1(1.5), d3;

	d3 = d1.mul(4);
	d3.print();

	m.waitKey();
}
void func4()
{
	Integer i1(20), i3;

	i3 = i1.div(4);
	i3.print();

	Double d1(60), d3;

	d3 = d1.div(12.5);
	d3.print();

	m.waitKey();
}
void Exit()
{
	cout << "Goodbye" << endl;
	exit(0);
}