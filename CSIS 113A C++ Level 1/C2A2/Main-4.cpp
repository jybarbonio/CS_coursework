//MAIN.CPP

/*
John Barbonio
0518876
21 January 2020
CSIS 123A-3694
Professor Rickman
Assignment 2 - Class Construction
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
Integer i1, i2, i3;
Double d1, d2, d3;

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
	i1.equals(20);
	i2.equals(5);
	i3 = i1.add(i2);
	i3.printInt();

	d1.equals(18.8);
	d2.equals(2.2);
	d3 = d1.add(d2);
	d3.printInt();

	m.waitKey();
}
void func2()
{
	i1.equals(20);
	i2.equals(5);
	i3 = i1.sub(i2);
	i3.printInt();

	d1.equals(18.8);
	d2.equals(2.2);
	d3 = d1.sub(d2);
	d3.printInt();

	m.waitKey();
}
void func3()
{
	i1.equals(20);
	i2.equals(5);
	i3 = i1.mul(i2);
	i3.printInt();

	d1.equals(18.8);
	d2.equals(2.2);
	d3 = d1.mul(d2);
	d3.printInt();

	m.waitKey();
}
void func4() 
{
	i1.equals(20);
	i2.equals(5);
	i3 = i1.div(i2);
	i3.printInt();

	d1.equals(25.5);
	d2.equals(5.1);
	d3 = d1.div(d2);
	d3.printInt();

	m.waitKey();
}
void Exit()
{
	cout << "Goodbye" << endl;
	exit(0);
}