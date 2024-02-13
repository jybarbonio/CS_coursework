#include <iostream>
#include "Double.h"

using namespace std;

Double::Double()
{
	this->equals(0.0);
}
Double::Double(double dub)
{
	this->equals(dub);
}
Double::Double(int num)
{
	this->equals(dub);
}
Double::Double(Double &d)
{
	this->equals(d.toDouble());
}
void Double::equals(double d)
{
	dub = d;
}
double Double::toDouble()
{
	return this->dub;
}
Double Double::add(Double &d)
{
	Double tmp;
	tmp.equals(this->toDouble() + d.toDouble());
	return tmp;
}
Double Double::sub(Double &d)
{
	Double tmp;
	tmp.equals(this->toDouble() - d.toDouble());
	return tmp;
}
Double Double::mul(Double &d)
{
	Double tmp;
	tmp.equals(this->toDouble() * d.toDouble());
	return tmp;
}
Double Double::div(Double &d)
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