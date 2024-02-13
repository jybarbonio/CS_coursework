#include <iostream>
#include "Double.h"
#include "Integer.h"

using namespace std;

Double::Double() 
{
	db = 0.0;
}
Double::Double(Double &d)
{
	db = d.toDouble();
}
Double::Double(double pd) 
{
	db = pd;
}
Double::Double(int pi) 
{
	db = static_cast<int>(pi);
}
void Double::equals(double pd)
{
	db = pd;		//sets db in private to whatever d is set to in main
}
double Double::toDouble() const
{
	return static_cast<double>(db);		//converts to double in case it is not
}
Double Double::add(double pd) 
{
	Double temp;
	temp.equals(this->toDouble() + pd);
	return temp;
}
Double Double::sub(double pd)
{
	Double temp;
	temp.equals(this->toDouble() - pd);
	return temp;
}
Double Double::mul(double pd)
{
	Double temp;
	temp.equals(this->toDouble() * pd);
	return temp;
}
Double Double::div(double pd)
{
	Double temp;
	temp.equals(this->toDouble() / pd);
	return temp;
}
Double Double::add(const Double &d)
{
	Double temp;
	temp.db = db;
	return temp;
}
Double Double::sub(const Double &d)
{
	Double temp;
	temp.db = db;
	return temp;
}
Double Double::mul(const Double &d)
{
	Double temp;
	temp.db = db;
	return temp;
}
Double Double::div(const Double &d)
{
	Double temp;
	temp.db = db;
	return temp;
}
void Double::print()
{
	cout << db << endl;
}