#include <iostream>
#include "Integer.h"
#include "Double.h"

using namespace std;

namespace john {

	Integer::Integer()
	{
		this->equals(0);
	}
	Integer::Integer(const Integer &i)
	{
		this->equals(i.toInt());
	}
	Integer::Integer(int pi)
	{
		this->equals(pi);
	}
	Integer::Integer(double pd)
	{
		this->equals(static_cast<double>(pd));
	}
	void Integer::equals(int pi)
	{
		this->in = pi;
	}
	int Integer::toInt() const
	{
		return this->in;		//converts to int in case it is not
	}
	Integer Integer::add(int pi)
	{
		Integer temp;
		temp.equals(this->toInt() + pi);
		return temp;
	}
	Integer Integer::sub(int pi)
	{
		Integer temp;
		temp.equals(this->toInt() - pi);
		return temp;
	}
	Integer Integer::mul(int pi)
	{
		Integer temp;
		temp.equals(this->toInt() * pi);
		return temp;
	}
	Integer Integer::div(int pi)
	{
		Integer temp;
		temp.equals(this->toInt() / pi);
		return temp;
	}
	Integer Integer::add(const Integer &i)
	{
		Integer temp;
		temp.in = this->in + i.in;
		return temp;
	}
	Integer Integer::sub(const Integer &i)
	{
		Integer temp;
		temp.in = this->in - i.in;
		return temp;
	}
	Integer Integer::mul(const Integer &i)
	{
		Integer temp;
		temp.in = this->in * i.in;
		return temp;
	}
	Integer Integer::div(const Integer &i)
	{
		Integer temp;
		temp.in = this->in / i.in;
		return temp;
	}
	void Integer::print()
	{
		cout << in << endl;
	}
	Integer Integer::operator + (const Integer &i)
	{
		return this->add(i);
	}
	Integer Integer::operator - (const Integer &i)
	{
		return this->sub(i);
	}
	Integer Integer::operator * (const Integer &i)
	{
		return this->mul(i);
	}
	Integer Integer::operator / (const Integer &i)
	{
		return this->div(i);
	}
	Integer &Integer::operator = (const Integer &i)
	{
		this->equals(i.toInt());
		return *this;
	}
	Integer &Integer::operator == (const Integer &i)
	{
		if (this->in == i.in)
		{
			cout << "equal" << endl;
		}
		else
		{
			cout << "not equal" << endl;
		}
		return *this;
	}
	Integer &Integer::operator != (const Integer &i)
	{
		operator==(i.toInt());
		return *this;
	}
	istream &operator >> (istream &input, Integer &i)
	{
		cout << "1 Enter a number" << endl;
		input >> i.in;

		return input;
	}
}
