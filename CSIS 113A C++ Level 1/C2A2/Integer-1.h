//INTEGER.H

/*
John Barbonio
0518876
21 January 2020
CSIS 123A-3694
Professor Rickman
Assignment 2 - Class Construction
*/

#ifndef INTEGER
#define INTEGER

class Integer 
{
private:
	int in;
public:
	void equals(int i);
	Integer add(const Integer &ia);
	Integer sub(const Integer &ia);
	Integer mul(const Integer &ia);
	Integer div(const Integer &ia);
	int toInt();	//return a primitive int
	double toDouble();	//return a primitive double
	void printInt();
};

#endif
