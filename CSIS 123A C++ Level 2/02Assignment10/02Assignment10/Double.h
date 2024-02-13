#include <iostream>

using std::string;

#ifndef DOUBLE
#define DOUBLE

using std::istream;
using std::ostream;

namespace john {

	class Double
	{
	private:
		double db;
		bool isNaN();
		bool nan;
	public:
		Double();
		Double(const Double &d);
		Double(double pd);
		Double(int pi);
		Double(const string s);

		void equals(double pd);
		void equals(string s);
		double toDouble() const;
		string toString() const;
		bool isNaN(string s);
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
		Double &operator = (const string s);
		Double &operator == (const Double &d);
		Double &operator != (const Double &d);

		friend ostream &operator << (ostream &output, Double &d);
		friend istream &operator >> (istream &input, Double &d);
	};
}

#endif
