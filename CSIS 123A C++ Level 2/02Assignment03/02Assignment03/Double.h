#ifndef DOUBLE
#define DOUBLE

class Double
{
private:
	double db;
public:
	Double();
	Double(Double &d);
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
};

#endif
