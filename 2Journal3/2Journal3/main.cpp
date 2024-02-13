/*
John Barbonio
0518876
11/4/2018
Journal 5 Dynamic Memory
*/

#include <iostream>
#include "Fraction.h"

using namespace std;

int main()
{
	Fraction f1, f2(1, 2), f3;

	cin >> f1;
	f3 = f1 + f2;
	cout << f3 << endl;

	f1.destroy();
	f2.destroy();
	f3.destroy();

	system("pause");
	return 0;
}
