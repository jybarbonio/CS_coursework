//INTEGER.CPP

/*
John Barbonio
0518876
3 February 2020
CSIS 123A-3694
Professor Rickman
Assignment 3: Overloaded Functions
*/

#include <iostream>
#include "Integer.h"

using namespace std;

Integer::Integer()
{
	this->equals(0);
}
Integer::Integer(int i)
{
	this->equals(i);
}
Integer::Integer(const Integer &i)
{
	this->equals(i.in);
}
void Integer::equals(int i)
{
	in = i;
}
Integer Integer::add(int i) 
{
	return this->in + i;
}
Integer Integer::sub(int i)
{
	return this->in - i;
}
Integer Integer::mul(int i)
{
	return this->in * i;
}
Integer Integer::div(int i)
{
	return this->in / i;
}
Integer Integer::add(const Integer &i)
{
	Integer temp;
	temp.in = (in + i.in);
	return temp;
}
Integer Integer::sub(const Integer &i)
{
	Integer temp;
	temp.in = (in - i.in);
	return temp;
}
Integer Integer::mul(const Integer &i)
{
	Integer temp;
	temp.in = (in * i.in);
	return temp;
}
Integer Integer::div(const Integer &i)
{
	Integer temp;
	temp.in = (in / i.in);

	if (temp.in < 0)
	{
		temp.in *= -1;
	}
	return temp;
}
int Integer::toInt() const	//return a primitive int
{
	return in;
}
double Integer::toDouble() const
{
	return static_cast<double>(in);		//cast int to double
}
void Integer::print()
{
	cout << in << endl;
}