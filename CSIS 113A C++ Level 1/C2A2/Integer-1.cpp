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
#include "Integer.h"

using namespace std;

void Integer::equals(int i) 
{
	in = i;
}
Integer Integer::add(const Integer &ia) 
{
	Integer temp;
	temp.in = (in + ia.in);
	return temp;
}
Integer Integer::sub(const Integer &ia) 
{
	Integer temp;
	temp.in = (in - ia.in);
	return temp;
}
Integer Integer::mul(const Integer &ia) 
{
	Integer temp;
	temp.in = (in * ia.in);
	return temp;
}
Integer Integer::div(const Integer &ia) 
{
	Integer temp;
	temp.in = (in / ia.in);

	if(temp.in < 0) 
	{
		temp.in *= -1;
	}
	return temp;
}
int Integer::toInt()	//return a primitive int
{
	return in;
}
double Integer::toDouble() 
{
	return static_cast<double>(in);		//cast int to double
}
void Integer::printInt() 
{
	cout << in << endl;
}