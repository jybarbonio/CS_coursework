//DOUBLE.H

/*
John Barbonio
0518876
10 February 2020
CSIS 123A-3694
Professor Rickman
Assignment 4: Vectors
*/

#include "Integer.h"

using std::istream;
using std::ostream;

#ifndef DOUBLE
#define DOUBLE

class Double
{
private:
	double db;
public:

	Double();
	Double(double d);
	Double(const Double& d);
	Double(const Integer& i);

	double getDouble() const;
	void equals(double d);

	Double add(double d);
	Double sub(double d);
	Double mul(double d);
	Double div(double d);

	Double add(const Double& d);
	Double sub(const Double& d);
	Double mul(const Double& d);
	Double div(const Double& d);
	double toDouble() const;
	void print();

	//overloads
	Double operator + (const Double &d);
	Double operator - (const Double &d);
	Double operator * (const Double &d);
	Double operator / (const Double &d);

	//Friend functions, I think these will be replaced later on?
	friend std::istream &operator >> (istream &input, Double &d);
	friend std::ostream &operator << (ostream &output, const Double &d);
};

#endif
