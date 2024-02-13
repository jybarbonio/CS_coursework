#include <iostream>
#ifndef FRACTION
#define FRACTION

using std::istream;
using std::ostream;

using std::string;

class Fraction
{
private:
	static int count;
	int num;
	int den;
public:
	~Fraction();
	static void printCount();

	void setFraction(int n, int d);
	Fraction add(const Fraction &f);
	Fraction sub(const Fraction &f);
	Fraction mul(const Fraction &f);
	Fraction div(const Fraction &f);
	int getNum() const;
	int getDen() const;	//accessor functions
	void printFraction();

	string getFractionn() const;
	string getFractiond() const;

	void reduce();
	int gcd(int num1, int rem);

	//Constructors
	Fraction();
	Fraction(int num, int den);
	//Operator Overloads
	Fraction operator + (const Fraction &f);
	Fraction operator - (const Fraction &f);
	Fraction operator * (const Fraction &f);
	Fraction operator / (const Fraction &f);
	Fraction &operator = (const Fraction &f);

	friend istream &operator >> (istream &input, Fraction &fr);
	friend ostream &operator << (ostream &output, const Fraction &fr);


};
#endif
