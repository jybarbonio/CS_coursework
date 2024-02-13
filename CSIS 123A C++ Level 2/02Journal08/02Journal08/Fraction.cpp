#include <iostream>
#include "Fraction.h"
#include <string>
#include <sstream>

using namespace std;

int Fraction::count = 0;

Fraction::~Fraction()
{
	Fraction::count++;
}

Fraction::Fraction()
{
	this->setFraction(1, 1);
}
void Fraction::printCount()
{
	cout << "There are " << Fraction::count << " Instances" << endl;
}
Fraction::Fraction(int num, int den)
{
	this->setFraction(num, den);
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
	tmp.den = (f.den * den);
	return tmp;
}

Fraction Fraction::sub(const Fraction &f)
{
	Fraction tmp;
	tmp.num = (this->num * f.den) - (f.num * f.den);
	tmp.den = (f.den * this->den);
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
	tmp.num = this->num * f.den;
	tmp.den = this->den * f.num;

	if (tmp.den < 0)
	{
		tmp.den *= -1;
	}
	if (tmp.num < 0)
		tmp.num *= -1;

	return tmp;
}
void Fraction::printFraction()
{
	cout << this->num << "/" << den << endl;
}
string Fraction::getFractionn() const
{
	stringstream ss;
	ss << this->getNum();
	return ss.str();
}
string Fraction::getFractiond() const
{
	stringstream ss;
	ss << this->getDen();
	return ss.str();
}
int Fraction::getDen() const
{
	return this->den;
}
int Fraction::getNum() const
{
	return this->num;
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
	input >> fr.num;
	cout << "Enter a denominator" << endl;
	input >> fr.num;

	return input;
}
ostream &operator << (ostream &output, const Fraction &fr)
{
	output << "Numerator: " << fr.getNum() << "/" << fr.getDen();

	return output;
}
void Fraction::reduce() 
{
	int rdc = 0; //reduced value
	if (this->den > this->num)
		rdc = this->gcd(this->den, this->num);
	else if (this->den < this->num)
		rdc = this->gcd(this->num, this->den);
	else
		rdc = this->gcd(this->num, this->den);

	this->den /= rdc;
	this->num /= rdc;
}
int Fraction::gcd(int num1, int rem) 
{
	if (rem == 0)
		return(num1);
	else
		return gcd(rem, num1 % rem);
}