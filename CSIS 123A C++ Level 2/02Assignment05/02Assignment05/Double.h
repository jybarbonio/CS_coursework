#include <iostream>

#ifndef DOUBLE
#define DOUBLE

using std::istream;
using std::ostream;

class Double
{
private:
	double db;
public:
	Double();
	Double(const Double &d);
	Double(double pd);
	Double(int pi);

	void equals(double pd);
	double toDouble() const;
	Double add(double pd);
	Double sub(double pd);
	Double mul(double pd);
	Double div(double pd);
	Double add(const Double &d);
	Double sub(const Double &d);
	Double mul(const Double &d);
	Double div(const Double &d);
	void print();

	Double operator + (const Double &d);
	Double operator - (const Double &d);
	Double operator * (const Double &d);
	Double operator / (const Double &d);
	Double &operator = (const Double &d);
	Double &operator == (const Double &d);
	Double &operator != (const Double &d);

	friend ostream &operator << (ostream &output, const Double &d);
	friend istream &operator >> (istream &input, Double &d);
};

#endif
