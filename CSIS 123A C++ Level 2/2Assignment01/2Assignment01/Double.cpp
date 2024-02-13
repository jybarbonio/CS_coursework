#include <iostream>
#include "Double.h"

using namespace std;

Double::Double()	//default constructor
{
	this->equals(0.0);
}
Double::Double(double d) 
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
double Double::toDouble() const
{
	return this->dub;
}
Double Double::add(const double d)
{
	Double temp;
	temp.equals(this->toDouble() + dub);
	return temp;
}
Double Double::add(const Double &f)
{
	Double temp;
	this->equals(this->toDouble() + f.toDouble());
	return temp;
}
Double Double::sub(const Double &f)
{
	Double temp;
	temp.dub = dub;
	return temp;
}
Double Double::mul(const Double &f)
{
	Double temp;
	temp.dub = dub;
	return temp;
}
Double Double::div(const Double &f)
{
	Double temp;
	temp.dub = dub;
	return temp;
}
void Double::print()
{
	cout << dub << endl;
}