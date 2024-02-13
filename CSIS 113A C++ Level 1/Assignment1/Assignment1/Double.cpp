#include <iostream>
#include "Double.h"
#include <String>
#include <sstream>

using namespace std;

Double::Double()
{
	this->equals(0.0);
}
Double::Double(double dub)
{
	this->create();
	this->equals(dub);
}
Double::Double(int num)
{
	this->create();
	this->equals(num);
}
void Double::create()
{
	this->dub = new double;
	this->num = new int;
}
void Double::destroy()
{
	delete dub;
	delete num;
}
Double::Double(const Double &d)
{
	this->create();
	this->equals(d.toDouble());
}
void Double::equals(double d)
{
	*dub = d;
}
double Double::toDouble() const
{
	return *this->dub;
}
Double Double::add(const Double &d)
{
	Double tmp;
	tmp.equals(this->toDouble() + d.toDouble());
	return tmp;
}
Double Double::sub(const Double &d)
{
	Double tmp;
	tmp.equals(this->toDouble() - d.toDouble());
	return tmp;
}
Double Double::mul(const Double &d)
{
	Double tmp;
	tmp.equals(this->toDouble() * d.toDouble());
	return tmp;
}
Double Double::div(const Double &d)
{
	Double tmp;
	tmp.equals(this->toDouble() / d.toDouble());
	return tmp;
}
Double Double::add(double dub)
{
	Double tmp;
	tmp.equals(this->toDouble() + dub);
	return tmp;
}
Double Double::sub(double dub)
{
	Double tmp;
	tmp.equals(this->toDouble() - dub);
	return tmp;
}
Double Double::mul(double dub)
{
	Double tmp;
	tmp.equals(this->toDouble() * dub);
	return tmp;
}
Double Double::div(double dub)
{
	Double tmp;
	tmp.equals(this->toDouble() / dub);
	return tmp;
}
void Double::print()
{
	cout << dub << endl;
}
Double Double::operator+(const Double &d)
{
	return this->add(d);
}
Double Double::operator-(const Double &d)
{
	return this->sub(d);
}
Double Double::operator*(const Double &d)
{
	return this->mul(d);
}
Double Double::operator/(const Double &d)
{
	return this->div(d);
}
Double &Double::operator=(const Double &d)
{
	this->equals(d.toDouble());
	return *this;
}
Double &Double::operator=(const string &s)
{
	this->equals(s.toString());
}
string Double::toString() const
{
	stringstream s;
	s << this->toDouble();
	return s.str();
}