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
void Double::equals(double d)
{
	dub = d;
}
Double::Double(Integer &in) 
{
	this->equals(in.toInt());
}
double Double::toDouble() 
{
	return this->dub;
}
Double Double::add(const Double &f)
{
	Double tmp;
	tmp.dub = dub;
	return tmp;
}
Double Double::sub(const Double &f)
{
	Double tmp;
	tmp.dub = dub;
	return tmp;
}
Double Double::mul(const Double &f)
{
	Double tmp;
	tmp.dub = dub;
	return tmp;
}
Double Double::div(const Double &f)
{
	Double tmp;
	tmp.dub = dub;
	return tmp;
}
void Double::print() 
{
	cout << dub << endl;
}