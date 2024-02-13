#pragma once
#include "Integer.h"

class Double
{
private:
	double dub;
public:
	void equals(double d);
	double toDouble();
	Double add(const Double &f);
	Double sub(const Double &f);
	Double mul(const Double &f);
	Double div(const Double &f);
	void print();

	Double();
	Double(double dub);
	Double(int num);
	Double(Integer &in);
};