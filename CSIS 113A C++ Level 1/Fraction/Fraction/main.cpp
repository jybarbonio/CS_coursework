#include <iostream>
#include "Fraction.h"

using namespace std;

int main() 
{
	Fraction f1, f2, f3;
	f1.setFraction(1, 2);
	f2.setFraction(3, 4);
	f3 = f1.add(f2);
	f3.printFraction();
	f3 = f1.sub(f2);
	f3.printFraction();
	f3 = f1.mul(f2);
	f3.printFraction();
	f3 = f1.div(f2);
	f3.printFraction();



	system("pause");
	return 0;
}