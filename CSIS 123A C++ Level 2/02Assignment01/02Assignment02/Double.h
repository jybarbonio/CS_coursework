#pragma once

class Double {
private:
	double db;
public:
	void equals(double d);
	double toDouble();
	Double add(const Double &d);
	Double sub(const Double &d);
	Double mul(const Double &d);
	Double div(const Double &d);
	void print();
};