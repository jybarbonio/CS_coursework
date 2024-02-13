#pragma once
#include <string>
#include "Integer.h"

using std::string;

class Double
{
private:
	double dub;
	int num;
public:
	Double();
	Double(double dub);
	Double(int num);
	Double(const Double &d);

	void equals(double d);
	void equals(const Double &d);
	double toDouble() const;
	Double add(const Double &d);
	Double sub(const Double &d);
	Double mul(const Double &d);
	Double div(const Double &d);

	Double add(double dub);
	Double sub(double dub);
	Double mul(double dub);
	Double div(double dub);

	double toDouble() const;
	string toString() const;

	void print();

	Double operator + (const Double &d);
	Double operator - (const Double &d);
	Double operator * (const Double &d);
	Double operator / (const Double &d);
	Double &operator = (const Double &d);
	Double &operator=(const string &s);
	bool operator == (const Double &d);
	bool operator == (double d);
	bool operator != (const double &d);
	bool operator != (double);


	void create();
	void destroy();
};