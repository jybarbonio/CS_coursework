#include <iostream>

#ifndef INTEGER
#define INTEGER

using std::istream;
using std::ostream;

namespace john {
	class Integer
	{
	private:
		int in;
	public:
		Integer();
		Integer(const Integer &i);
		Integer(int pi);
		Integer(double pd);

		void equals(int pi);
		int toInt() const;
		Integer add(int pi);
		Integer sub(int pi);
		Integer mul(int pi);
		Integer div(int pi);
		Integer add(const Integer &i);
		Integer sub(const Integer &i);
		Integer mul(const Integer &i);
		Integer div(const Integer &i);
		void print();

		Integer operator + (const Integer &i);
		Integer operator - (const Integer &i);
		Integer operator * (const Integer &i);
		Integer operator / (const Integer &i);
		Integer &operator = (const Integer &i);
		Integer &operator == (const Integer &i);
		Integer &operator != (const Integer &i);

		friend ostream &operator << (ostream &output, Integer &i);
		friend istream &operator >> (istream &input, Integer &i);

		void writeInts();
		void readInts();
	};

}

#endif

