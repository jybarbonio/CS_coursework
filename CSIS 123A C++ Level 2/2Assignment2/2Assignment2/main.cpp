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
	Integer in1, in2, in3;
	in1.equals(2);
	in3 = in1.add(in2);
	in3.print();

	in1.equals(2);
	in3 = in1.sub(in2);
	in3.print();

	in1.equals(2);
	in3 = in1.mul(in2);
	in3.print();

	in1.equals(2);
	in3 = in1.div(in2);
	in3.print();

	Double db1, db2, db3;
	db1.equals(3.14);
	db3 = db1.add(db2);
	db3.print();

	db1.equals(3.14);
	db3 = db1.sub(db2);
	db3.print();

	db1.equals(3.14);
	db3 = db1.mul(db2);
	db3.print();

	db1.equals(3.14);
	db3 = db1.div(db2);
	db3.print();

	system("pause");
	return 0;
}