/*
John Barbonio
0518876
Assignment 2 Class Construction
21 October 2018
*/
#include <iostream>
#include "Integer.h"
#include "Double.h"

using namespace std;

int main()
{
	Integer in1(2), in2, in3(2);
	cout << in1.toInt() << endl;
	cout << in2.toInt() << endl;

	cout << in1.add(6).toInt() << endl;
	cout << in1.sub(6).toInt() << endl;
	cout << in1.mul(6).toInt() << endl;
	cout << in1.div(6).toInt() << endl;

	cout << endl;

	Double db1(3.14), db3;
	cout << db1.toDouble() << endl;
	cout << db3.toDouble() << endl;

	db3 = db1.add(3.14);
	cout << db3.toDouble() << endl;

	cout << db1.add(3.14).toDouble() << endl;
	cout << db1.sub(3.14).toDouble() << endl;
	cout << db1.mul(3.14).toDouble() << endl;
	cout << db1.div(3.14).toDouble() << endl;

	system("pause");
	return 0;
}