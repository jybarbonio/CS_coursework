#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctype.h>

using namespace std;

int main() 
{
	cout << "Welcome! You can convert inches to millimeter, centimeter, and meters!\n";
	cout << "m - millimeter\nC - centimeters\nM - meters\n";

	double m, C, M;
	double inch;
	char op;

	cin >> op >> inch;

	switch(op) 
	{
	case 'm':
		inch *= 25.4;
		break;
	case 'c':
		inch *= 2.54;
		break;
	case'M':
		inch = 0.0254;
		break;
	default:
		cout << "Invalid!\n";
	}

	cout << inch << endl;

	system("pause");
	return 0;
}