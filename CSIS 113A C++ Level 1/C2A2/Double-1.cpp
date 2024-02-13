//INTEGER.CPP

/*
John Barbonio
0518876
21 January 2020
CSIS 123A-3694
Professor Rickman
Assignment 2 - Class Construction
*/

#include <iostream>
#include "Double.h"

using namespace std;

void Double::equals(double d)
{
	db = d;
}
Double Double::add(const Double &da)
{
	Double temp;
	temp.db = (db + da.db);
	return temp;
}
Double Double::sub(const Double &da)
{
	Double temp;
	temp.db = (db - da.db);
	return temp;
}
Double Double::mul(const Double &da)
{
	Double temp;
	temp.db = (db * da.db);
	return temp;
}
Double Double::div(const Double &da)
{
	Double temp;
	temp.db = (db / da.db);

	if (temp.db < 0)
	{
		temp.db *= -1;
	}
	return temp;
}
double Double::toDouble()	//return a primitive int
{
	return db;
}
int Double::toInt()
{
	return static_cast<int>(db);		//cast int to double
}
void Double::printInt()
{
	cout << db << endl;
}