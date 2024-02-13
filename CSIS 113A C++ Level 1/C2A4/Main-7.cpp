//MAIN.CPP

/*
John Barbonio
0518876
10 February 2020
CSIS 123A-3694
Professor Rickman
Assignment 4: Vectors
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

void doubleAdd();

void Exit();

Menu m;	/*is it ok if this is in the field and not within the main method like what Stevenson did?
		I need it here to use waitKey properly*/

int main()
{

	m.addMenu("1. Add", func1);
	m.addMenu("2. Subtract", func2);
	m.addMenu("3. Multiply", func3);
	m.addMenu("4. Divide", func4);
	m.addMenu("5. Add Doubles", doubleAdd);
	m.addMenu("6. Exit", Exit);

	m.runMenu();
}
void func1()
{
	Integer i1, i2, i3;	//there seems to be a serious crashing issues when if I input a double for cin >> i1, i2, the program breaks, I will add a func to handle doubles

	cin >> i1;
	cin >> i2;
	i3 = i1 + i2;
	cout << i3;

	m.waitKey();
}
void func2()
{
	Integer i1(15), i3;

	i3 = i1 - 5;
	cout << i3;

	Double d1(19.5), d2, d3;

	cin >> d1;
	cin >> d2;

	d3 = d1 - d2;
	cout << d3;

	m.waitKey();
}
void func3()
{
	Integer i1(10), i3;

	i3 = i1 * 3;
	cout << i3;

	Double d1(1.5), d3;

	d3 = d1 * 4;
	cout << d3;

	m.waitKey();
}
void func4()
{
	Integer i1(20), i3;

	i3 = i1 / 4;
	cout << i3;

	Double d1(60), d3;

	d3 = d1 / 12.5;
	d3.print();

	m.waitKey();
}
void doubleAdd()
{
	Double d1, d2, d3;

	cin >> d1;		//you asked for input from the user, but im not sure if you wanted all the friend funcs and operators to be implemented
	cin >> d2;		//not sure if you were just asking for the actual operator overload or just using cin on temp variables and setting d1, d2 as them

	d3 = d1 + d2;
	cout << d3;

	m.waitKey();
}
void Exit()
{
	cout << "Goodbye" << endl;
	exit(0);
}