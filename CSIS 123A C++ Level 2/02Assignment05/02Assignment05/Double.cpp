#include <iostream>
#include "Double.h"
#include "Integer.h"

using namespace std;

Double::Double()
{
	this->equals(0.0);
}
Double::Double(const Double &d)
{
	this->equals(d.toDouble());
}
Double::Double(double pd)
{
	this->equals(pd);
}
Double::Double(int pi)
{
	this->equals(static_cast<int>(pi));
}
void Double::equals(double pd)
{
	this->db = pd;		//sets db in private to whatever d is set to in main
}
double Double::toDouble() const
{
	return this->db;		//converts to double in case it is not
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
	temp.db = this->db + d.db;
	return temp;
}
Double Double::sub(const Double &d)
{
	Double temp;
	temp.db = (this->db) - d.db;
	return temp;
}
Double Double::mul(const Double &d)
{
	Double temp;
	temp.db = (this->db) * (d.db);
	return temp;
}
Double Double::div(const Double &d)
{
	Double temp;
	temp.db = (this->db) / d.db;
	return temp;
}
void Double::print()
{
	cout << db << endl;
}
Double Double::operator + (const Double &d) 
{
	return this->add(d);
}
Double Double::operator - (const Double &d) 
{
	return this->sub(d);
}
Double Double::operator * (const Double &d)
{
	return this->mul(d);
}
Double Double::operator / (const Double &d)
{
	return this->div(d);
}
Double &Double::operator = (const Double &d) 
{
	this->equals(d.toDouble());
	return *this;
}
Double &Double::operator == (const Double &d) 
{
	if(this->db == d.db) 
	{
		cout << "equal" << endl;
	}
	else 
	{
		cout << "not equal" << endl;
	}
	return *this;
}
Double &Double::operator != (const Double &d) 
{
	operator==(d.toDouble());
	return *this;
}
ostream &operator << (ostream &output, const Double &d) 
{
	output << d.toDouble();
	return output;
}
istream &operator >> (istream &input, Double &d) 
{
	cout << "1 Enter a number" << endl;
	input >> d.db;

	return input;
}