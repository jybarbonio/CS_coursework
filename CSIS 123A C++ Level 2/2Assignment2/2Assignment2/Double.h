#pragma once

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
};