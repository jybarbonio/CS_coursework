#ifndef DOUBLE
#define DOUBLE

class Double 
{
private:
	double dub;

public:
	Double();
	Double(double d);
	Double(Double &d);

	void equals(double d);
	double toDouble() const;
	Double add(const double d);
	Double add(const Double &f);
	Double sub(const Double &f);
	Double mul(const Double &f);
	Double div(const Double &f);
	void print();

};
#endif