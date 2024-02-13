#pragma once
#include "Integer.h"

class Double
{
private:
	double *dub;
	int *num;
public:
	void equals(double d);
	double toDouble() const;
	Double add(const Double &d);
	Double sub(const Double &d);
	Double mul(const Double &d);
	Double div(const Double &d);

	Double add(double dub);
	Double sub(double dub);
	Double mul(double dub);
	Double div(double dub);

	void print();

	
	Double();
	Double(double dub);
	Double(int num);
	Double(const Double &d);

	Double operator + (const Double &d);
	Double operator - (const Double &d);
	Double operator * (const Double &d);
	Double operator / (const Double &d);
	Double &operator = (const Double &d);
	Double &operator=(const string &s);

	void create();
	void destroy();

	string toString() const;
};