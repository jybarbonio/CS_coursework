#include <iostream>
#include "Double.h"

using namespace std;

void Double::equals(double d) 
{
	db = d;		//sets db in private to whatever d is set to in main
}
double Double::toDouble() 
{
	return this->db;
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