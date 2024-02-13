/*
John Barbonio
0518876
9 September, 2018
Assignment 12: Functions and the Math library
*/
#include <iostream>

using namespace std;

double pythagoras(double x, double y, char z);

int main() 
{
	double a, b, c;
	cout << "This is the Pythagorean Theorem. Enter sides A and B and I will solve for C" << endl;
	cin >> a >> b;
	c = pythagoras(a, b, 'c');
	cout << "Side C is equal to " << c << endl;
	cout << "Enter sides B and C and I will solve for A" << endl;
	cin >> b >> c;
	a = pythagoras(b, c, 'a');
	cout << "Side A is equal to " << a << endl;
	cout << "Enter sides A and C and I will solve for B" << endl;
	cin >> a >> c;
	b = pythagoras(a, c, 'b');
	cout << "Side B is equal to " << b << endl;

	system("pause");
	return 0;
}
double pythagoras(double x, double y, char z) 
{
	double solution = 0;
	switch(tolower(z)) 
	{
	case 'c':
		z = sqrt(pow(x, 2) + pow(y, 2));
		break;
	case 'a':
		y = sqrt(pow(z, 2) - pow(y, 2));
		break;
	case 'b':
		y = sqrt(pow(z, 2) - pow(y, 2));
		break;
	}
	return z;
}