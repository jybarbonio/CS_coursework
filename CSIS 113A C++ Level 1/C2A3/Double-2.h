//DOUBLE.H

/*
John Barbonio
0518876
3 February 2020
CSIS 123A-3694
Professor Rickman
Assignment 3: Overloaded Functions
*/

#include "Integer.h"

#ifndef DOUBLE
#define DOUBLE

class Double
{
private:
	double db;
public:
	void equals(double d);

	Double add(double d);
	Double sub(double d);
	Double mul(double d);
	Double div(double d);

	Double add(const Double &d);
	Double sub(const Double &d);
	Double mul(const Double &d);
	Double div(const Double &d);
	double toDouble() const;
	int toInt() const;
	void print();

	Double();
	Double(double d);
	Double(const Double &d);
	Double(const Integer &i);
};

#endif
