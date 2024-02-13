#include <iostream>
#include "Double.h"
#include "Integer.h"
#include <sstream>

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

namespace john {

	bool Double::isNaN()
	{
		return this->nan;
	}

	Double::Double()
	{
		this->equals(0.0);
	}
	Double::Double(const Double &d)
	{
		this->equals(d.toDouble());
	}
	Double::Double(double pd)
	{
		this->equals(pd);
	}
	Double::Double(int pi)
	{
		this->equals(static_cast<int>(pi));
	}
	Double::Double(const string s)
	{
		this->equals(s);
	}
	void Double::equals(double pd)
	{
		this->db = pd;		//sets db in private to whatever d is set to in main
	}
	void Double::equals(string s)
	{
		if (!this->isNaN())
			this->db = 0.0;
		else
			this->db = stod(s);
	}
	double Double::toDouble() const
	{
		return this->db;		//converts to double in case it is not
	}
	string Double::toString() const
	{
		stringstream ss;
		ss << this->toDouble();
		return ss.str();
	}
	bool Double::isNaN(string s)
	{
		this->nan = false;

		for (int i = 1; i < s.length(); i++)
		{
			if (isalpha(s[i]))
			{
				this->nan = true;
				break;
			}
		}
		return this->nan;
	}
	Double Double::add(double pd)
	{
		Double temp;
		temp.equals(this->toDouble() + pd);
		return temp;
	}
	Double Double::sub(double pd)
	{
		Double temp;
		temp.equals(this->toDouble() - pd);
		return temp;
	}
	Double Double::mul(double pd)
	{
		Double temp;
		temp.equals(this->toDouble() * pd);
		return temp;
	}
	Double Double::div(double pd)
	{
		Double temp;
		temp.equals(this->toDouble() / pd);
		return temp;
	}
	Double Double::add(const Double &d)
	{
		Double temp;
		temp.db = this->db + d.db;
		return temp;
	}
	Double Double::sub(const Double &d)
	{
		Double temp;
		temp.db = (this->db) - d.db;
		return temp;
	}
	Double Double::mul(const Double &d)
	{
		Double temp;
		temp.db = (this->db) * (d.db);
		return temp;
	}
	Double Double::div(const Double &d)
	{
		Double temp;
		temp.db = (this->db) / d.db;
		return temp;
	}
	void Double::print()
	{
		cout << db << endl;
	}
	Double Double::operator + (const Double &d)
	{
		return this->add(d);
	}
	Double Double::operator - (const Double &d)
	{
		return this->sub(d);
	}
	Double Double::operator * (const Double &d)
	{
		return this->mul(d);
	}
	Double Double::operator / (const Double &d)
	{
		return this->div(d);
	}
	Double &Double::operator = (const Double &d)
	{
		this->equals(d.toDouble());
		return *this;
	}
	Double &Double::operator = (const string s)
	{
		this->equals(s);
		return *this;
	}
	Double &Double::operator == (const Double &d)
	{
		if (this->db == d.db)
		{
			cout << "equal" << endl;
		}
		else
		{
			cout << "not equal" << endl;
		}
		return *this;
	}
	Double &Double::operator != (const Double &d)
	{
		operator==(d.toDouble());
		return *this;
	}
	ostream &operator << (ostream &output, Double &d) 
	{
		output << d.toDouble();
		return output;
	}
	istream &operator >> (istream &input, Double &d)
	{
		cout << "1 Enter a number" << endl;
		input >> d.db;

		return input;
	}
}