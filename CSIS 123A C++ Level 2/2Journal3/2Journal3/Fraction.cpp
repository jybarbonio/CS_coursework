#include <iostream>
#include "Fraction.h"

using namespace std;

Fraction::Fraction() 
{
	this->create();
	this->setFraction(1, 1);
}
Fraction::Fraction(int num, int den)
{
	this->create();
	this->setFraction(num, den);
}
void Fraction::create() 
{
	this->num = new int;
	this->den = new int;
}
void Fraction::destroy() 
{
	delete num;
	delete den;
}
Fraction::Fraction(const Fraction &f) 
{
	this->create();
	this->setFraction(f.getNum(), f.getDen());
}
void Fraction::setFraction(int n, int d)
{
	*this->num = n;
	*this->den = d;
}
Fraction Fraction::add(const Fraction &f)
{
	Fraction tmp;
	*tmp.num = (*this->num * *f.den) + (*f.num * *this->den);
	*tmp.den = (*f.den * *this->den);
	return tmp;
}

Fraction Fraction::sub(const Fraction &f)
{
	Fraction tmp;
	*tmp.num = (*this->num * *f.den) - (*f.num * *f.den);
	*tmp.den = (*f.den * *this->den);
	return tmp;
}
Fraction Fraction::mul(const Fraction &f)
{
	Fraction tmp;
	*tmp.num = (*this->num) * (*f.num);
	*tmp.den = (*this->den) * (*f.den);
	return tmp;
}
Fraction Fraction::div(const Fraction &f)
{
	Fraction tmp;
	*tmp.num = *this->num * *f.den;
	*tmp.den = *this->den * *f.num;

	if (tmp.den < 0)
	{
		*tmp.den *= -1;
		*tmp.num *= -1;
	}
	return tmp;
}
void Fraction::printFraction()
{
	cout << this->num << "/" << den << endl;
}
int Fraction::getDen() const
{
	return *this->den;
}
int Fraction::getNum() const
{
	return *this->num;
}
Fraction Fraction::operator+(const Fraction &f) 
{
	return this->add(f);
}
Fraction Fraction::operator-(const Fraction &f) 
{
	return this->sub(f);
}
Fraction Fraction::operator*(const Fraction &f)
{
	return this->mul(f);
}
Fraction Fraction::operator/(const Fraction &f)
{
	return this->div(f);
}
Fraction &Fraction::operator=(const Fraction &f) 
{
	this->setFraction(f.getDen(), f.getDen());
	return *this;
}
istream &operator >> (istream &input, Fraction &fr) 
{
	cout << "Enter a numerator" << endl;
	input >> *fr.num;
	cout << "Enter a denominator" << endl;
	input >> *fr.num;

	return input;
}
ostream &operator << (ostream &output, const Fraction &fr)
{
	output << "Numerator: " << fr.getNum() << "/" << fr.getDen();

	return output;
}