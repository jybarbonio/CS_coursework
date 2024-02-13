//INTEGER.H

/*
John Barbonio
0518876
3 February 2020
CSIS 123A-3694
Professor Rickman
Assignment 3: Overloaded Functions
*/

#ifndef INTEGER
#define INTEGER

class Integer
{
private:
	int in;
public:
	void equals(int i);

	Integer add(int i);
	Integer sub(int i);
	Integer mul(int i);
	Integer div(int i);

	Integer add(const Integer &i);
	Integer sub(const Integer &i);
	Integer mul(const Integer &i);
	Integer div(const Integer &i);
	int toInt() const;		//return a primitive int
	double toDouble() const;	//return a primitive double
	void print();

	//constructors
	Integer();
	Integer(int i);
	Integer(const Integer &i);
	//Integer(const Double &d); not asked for/needed?
};

#endif
