//DOUBLE.H

/*
John Barbonio
0518876
21 January 2020
CSIS 123A-3694
Professor Rickman
Assignment 2 - Class Construction
*/

#ifndef DOUBLE
#define DOUBLE

class Double
{
private:
	double db;
public:
	void equals(double d);
	Double add(const Double &d);
	Double sub(const Double &d);
	Double mul(const Double &d);
	Double div(const Double &d);
	double toDouble();
	int toInt();
	void printInt();
};

#endif