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

void intAdd();
void intSub();
void intMul();
void intDiv();

void doubleAdd();
void doubleSub();
void doubleMul();
void doubleDiv();
void doubleString();
void Exit();

int main() 
{

	Menu* m = Menu::Instance();
	m->addMenu("1. Add Integers", intAdd);
	m->addMenu("1. Add Integers", intSub);
	m->addMenu("1. Add Integers", intMul);
	m->addMenu("1. Add Integers", intDiv);

	m->addMenu("1. Add Doubles", doubleAdd);
	m->addMenu("1. Add Doubles", doubleSub);
	m->addMenu("1. Add Doubles", doubleMul);
	m->addMenu("1. Add Doubles", doubleDiv);
	m->addMenu("4. EXIT ", Exit);

	m->runMenu();

}
void intAdd() 
{
	Menu *m = Menu::Instance();
	int a, b;
	cout << "Enter two ints" << endl;
	cin >> a >> b;
	Integer *x = new Integer(a);
	Integer *y = new Integer(b);

	Integer *z = new Integer();
	z->equals(x->add(*y));

	cout << "The sum is " << z->toInt() << endl;
	m->waitKey();
}
void intSub()
{
	Menu *m = Menu::Instance();
	int a, b;
	cout << "Enter two ints" << endl;
	cin >> a >> b;
	Integer *x = new Integer(a);
	if (x == NULL)
	{
		cout << "Cannot allocate memory" << endl;		//memory allocation warning
		return;
	}
	Integer *y = new Integer(b);

	Integer *z = new Integer();
	z->equals(x->sub(*y));

	cout << "The sum is " << z->toInt() << endl;
	m->waitKey();
}
void intMul()
{
	Menu *m = Menu::Instance();
	int a, b;
	cout << "Enter two ints" << endl;
	cin >> a >> b;
	Integer *x = new Integer(a);
	Integer *y = new Integer(b);

	Integer *z = new Integer();
	z->equals(x->mul(*y));

	cout << "The sum is " << z->toInt() << endl;
	m->waitKey();
}
void intDiv()
{
	Menu *m = Menu::Instance();
	int a, b;
	cout << "Enter two ints" << endl;
	cin >> a >> b;
	Integer *x = new Integer(a);
	Integer *y = new Integer(b);

	Integer *z = new Integer();
	z->equals(x->div(*y));

	cout << "The sum is " << z->toInt() << endl;
	m->waitKey();
}
void doubleAdd() 
{
	double a, b;
	cout << "Enter two doubles " << endl;
	cin >> a >> b;
	Double *x = new Double(a);
	Double *y = new Double(b);
	Double->equals(x->add(*y));

	cout << "The sum is " << z->toDouble() << endl;
}
void doubleSub()
{
	double a, b;
	cout << "Enter two doubles " << endl;
	cin >> a >> b;
	Double *x = new Double(a);
	Double *y = new Double(b);
	Double->equals(x->sub(*y));

	cout << "The sum is " << z->toDouble() << endl;
}
void doubleMul()
{
	double a, b;
	cout << "Enter two doubles " << endl;
	cin >> a >> b;
	Double *x = new Double(a);
	Double *y = new Double(b);
	Double->equals(x->mul(*y));

	cout << "The sum is " << z->toDouble() << endl;
}
void doubleDiv()
{
	double a, b;
	cout << "Enter two doubles " << endl;
	cin >> a >> b;
	Double *x = new Double(a);
	Double *y = new Double(b);
	Double->equals(x->div(*y));

	cout << "The sum is " << z->toDouble() << endl;
}
void doubleString() 
{
	string s1 = "12.22";
	string s2 = "5.6";
	Integer d1(s1);
	Integer d2(s2);


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