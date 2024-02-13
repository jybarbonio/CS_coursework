/*
John Barbonio
0518876
11/4/2018
Journal 6 Static Members
*/

#include <iostream>
#include "Fraction.h"

using namespace std;

int main()
{
	Fraction f1(3, 4), f2(1, 2), f3;

	Fraction::printCount();

	f3 = f1 + f2;
	f3.printFraction();

	Fraction::printCount();

	system("pause");
	return 0;
}
