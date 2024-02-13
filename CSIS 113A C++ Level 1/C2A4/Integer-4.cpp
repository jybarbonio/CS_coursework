//INTEGER.CPP

/*
John Barbonio
0518876
10 February 2020
CSIS 123A-3694
Professor Rickman
Assignment 4: Vectors
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
Integer::Integer(const Integer& i)
{
	this->equals(i.in);
}
int Integer::getInt() const 
{
	return this->in;
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
Integer Integer::add(const Integer& i)
{
	Integer temp;
	temp.in = (in + i.in);
	return temp;
}
Integer Integer::sub(const Integer& i)
{
	Integer temp;
	temp.in = (in - i.in);
	return temp;
}
Integer Integer::mul(const Integer& i)
{
	Integer temp;
	temp.in = (in * i.in);
	return temp;
}
Integer Integer::div(const Integer& i)
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
	return static_cast<int>(in);
}
void Integer::print()
{
	cout << in << endl;
}
Integer Integer::operator + (const Integer &i)
{
	return this->add(i);
}
Integer Integer::operator - (const Integer &i) 
{
	return this->sub(i);
}
Integer Integer::operator * (const Integer &i) 
{
	return this->mul(i);
}
Integer Integer::operator / (const Integer &i) 
{
	return this->div(i);		//negative fraction result is checked in the div function
}
istream& operator >> (istream &input, Integer &i)
{
	cout << "Enter an int number" << endl;
	input >> i.in;
	return input;
}
ostream &operator << (ostream &output, const Integer &i) 
{
	output << "Value: " << i.getInt() << endl;
	return output;
}