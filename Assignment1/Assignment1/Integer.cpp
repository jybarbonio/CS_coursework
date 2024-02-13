#include <iostream>
#include <string>
#include <sstream>
#include "Integer.h"

using namespace std;

Integer::Integer()
{
	this->equals(0);
}
Integer::Integer(int num)
{
	this->equals(num);
}
void Integer::equals(int n)
{
	num = n;
}
void Integer::equals(const Integer &num) 
{
	this->equals(num.toInt());
	this->nan = false;
}
void Integer::equals(string s)
{
	this->isNan(s);
	if (!this->isNan())
		this->data = stod(s);
	else
		this->data = 0.0;
}
int Integer::toInt()
{
	return this->num;
}
string Integer::toString() const 
{
	stringstream ss;
	ss << this->toInt();
	return ss.str();
}
Integer Integer::add(const Integer &f)
{
	Integer tmp;
	tmp.num = num;
	return tmp;
}
Integer Integer::sub(const Integer &f)
{
	Integer tmp;
	tmp.num = num;
	return tmp;
}
Integer Integer::mul(const Integer &f)
{
	Integer tmp;
	tmp.num = num;
	return tmp;
}
Integer Integer::div(const Integer &f)
{
	Integer tmp;
	tmp.num = num;
	return tmp;
}
void Integer::print()
{
	cout << num << endl;
}
Integer &Integer::operator (int i) 
{
	
}
Integer &Integer::operator  (string s) 
{
	this->equals(s);
	return *this;
}
void Integer::isNan(string s)
{
	string::iterator p;
	for (p = s.begin(); p < s.end(); p++)
	{
		if (!isdigit(*p))
		{
			return;
		}
	}
	this->nan = false;
	return;
}
Integer::~Integer() 
{
	
}