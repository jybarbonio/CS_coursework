//MAIN.CPP

#include <iostream>
#include <string>
#include "Fraction.h"

using namespace std;

int main() 
{
	string in;
	cin >> in;

	Fraction f1(in), f2(in), f3;

	//Fraction f1(1, 4), f2(1, 2), f3;

	f3 = f1.mul(f2);
	f3.printFraction();

	system("pause");
	return 0;
}