//FRACTION.CPP

#include <iostream>
#include "Fraction.h"
#include <string>

using namespace std;

Fraction::Fraction() //default
{
	this->setFraction(1, 1);
}
Fraction::Fraction(string input) 
{
	string tmp = input;

	for (int i = 0; i < input.length(); i++)
	{
		if (input.at(i) >= 48 && input.at(i) <= 57)
		{
			tmp[i] = input[i];
		}
	}
	int first = static_cast<int>(tmp[0]);
	int second = static_cast<int>(tmp[1]);

	this->setFraction(first, second);
}
void Fraction::setFraction(int n, int d)
{
	this->num = n;
	this->den = d;
}
Fraction Fraction::add(const Fraction &f) 
{
	Fraction tmp;
	tmp.num = (this->num * f.den) + (f.num * this->den);
	tmp.den = (f.den * this->den);
	return tmp;
}

Fraction Fraction::sub(const Fraction &f) 
{
	Fraction tmp;
	tmp.num = (this->num *2) -  (f.num);
	tmp.den = (f.den * this->den) / 2;
	return tmp;
}
Fraction Fraction::mul(const Fraction &f)
{
	Fraction tmp;
	tmp.num = (this->num) * (f.num);
	tmp.den = (this->den) * (f.den);
	return tmp;
}
Fraction Fraction::div(const Fraction &f)
{
	Fraction tmp;
	tmp.num = (this->num * f.den);
	tmp.den = (this->den * f.num);

	if (tmp.den < 0)
		tmp.den *= -1;

	return tmp;
}
void Fraction::printFraction() 
{
	cout << this->num << "/" << this->den << endl;
}