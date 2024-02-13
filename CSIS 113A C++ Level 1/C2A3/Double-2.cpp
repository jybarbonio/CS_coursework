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
#include "Double.h"

using namespace std;

Double::Double()
{
	this->equals(0.0);	//default number
}
Double::Double(double d)
{
	this->equals(d);
}
Double::Double(const Double &d)
{
	this->equals(d.db);
}
Double::Double(const Integer &i)
{
	Double temp;
	this->equals(i.toDouble());		
	/*or I guess the inbuilt toDouble within this class could be used, isn't having toInt and toDouble in both
	classes kind of repetitive?*/
}
void Double::equals(double d)
{
	db = d;
}
Double Double::add(double d) 
{
	return this->db + d;
}
Double Double::sub(double d)
{
	return this->db - d;
}
Double Double::mul(double d)
{
	return this->db * d;
}
Double Double::div(double d)
{
	return this->db / d;
}
Double Double::add(const Double &d)
{
	Double temp;
	temp.db = (db + d.db);
	return temp;
}
Double Double::sub(const Double &d)
{
	Double temp;
	temp.db = (db - d.db);
	return temp;
}
Double Double::mul(const Double &d)
{
	Double temp;
	temp.db = (db * d.db);
	return temp;
}
Double Double::div(const Double &d)
{
	Double temp;
	temp.db = (db / d.db);

	if (temp.db < 0)
	{
		temp.db *= -1;
	}
	return temp;
}
double Double::toDouble() const	//return a double
{
	return db;
}
int Double::toInt() const
{
	return static_cast<int>(db);		//cast double to int
}
void Double::print()
{
	cout << db << endl;
}