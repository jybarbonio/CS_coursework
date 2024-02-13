//INTEGER.H

/*
John Barbonio
0518876
10 February 2020
CSIS 123A-3694
Professor Rickman
Assignment 4: Vectors
*/

#ifndef INTEGER
#define INTEGER

using std::istream;
using std::ostream;

class Integer
{
private:
	int in;
public:
	//constructors
	Integer();
	Integer(int i);
	Integer(const Integer& i);

	int getInt() const;	//const because it is only passing the value, no modification
	void equals(int i);

	Integer add(int i);
	Integer sub(int i);
	Integer mul(int i);
	Integer div(int i);

	Integer add(const Integer& i);
	Integer sub(const Integer& i);
	Integer mul(const Integer& i);
	Integer div(const Integer& i);
	int toInt() const;		//return a primitive int
	void print();

	//overloads
	Integer operator + (const Integer& i);
	Integer operator - (const Integer& i);
	Integer operator * (const Integer& i);
	Integer operator / (const Integer& i);

	//Friend functions, I think these will be replaced later on?
	friend std::istream& operator >> (istream& input, Integer &i);
	friend std::ostream& operator << (ostream& output, const Integer &i);
};

#endif
