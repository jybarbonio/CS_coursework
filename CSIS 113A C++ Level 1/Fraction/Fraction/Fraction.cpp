#include <iostream>
#include "Fraction.h"

using namespace std;

void Fraction::setFraction(int n, int d)
{
	num = n;
	den = d;
}
Fraction Fraction::add(const Fraction &f) 
{
	Fraction tmp;
	tmp.num = (num * f.den) + (f.num * den);
	tmp.den = (f.den * den);
	return tmp;
}

Fraction Fraction::sub(const Fraction &f) 
{
	Fraction tmp;
	tmp.num = (num *2) -  (f.num);
	tmp.den = (f.den * den) / 2;
	return tmp;
}
Fraction Fraction::mul(const Fraction &f)
{
	Fraction tmp;
	tmp.num = (num) * (f.num);
	tmp.den = (den) * (f.den);
	return tmp;
}
Fraction Fraction::div(const Fraction &f)
{
	Fraction tmp;
	tmp.num = (num * f.den);
	tmp.den = (den * f.num);

	if (tmp.den < 0)
		tmp.den *= -1;

	if (tmp.num < 0)
		tmp.num *= -1;

	return tmp;
}
void Fraction::printFraction() 
{
	cout << num << "/" << den << endl;
}