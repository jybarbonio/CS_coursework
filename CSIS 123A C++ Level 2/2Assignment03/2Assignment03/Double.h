#pragma once
#include "Integer.h"

class Double
{
private:
	double dub;
	int num;
public:
	void equals(double d);
	double toDouble();
	Double add(Double &d);
	Double sub(Double &d);
	Double mul(Double &d);
	Double div(Double &d);

	Double add(double dub);
	Double sub(double dub);
	Double mul(double dub);
	Double div(double dub);

	void print();

	Double();
	Double(double dub);
	Double(int num);
	Double(Double &d);
};