#include <iostream>
#include "Integer.h"
#include "Double.h"

using namespace std;

Integer::Integer()
{
	in = 0;
}
Integer::Integer(Integer &i)
{
	in = i.toInt();
}
Integer::Integer(int pi)
{
	in = pi;
}
Integer::Integer(double pd)
{
	in = static_cast<int>(pd);
}
void Integer::equals(int pi)
{
	in = pi;
}
int Integer::toInt() const
{
	return static_cast<int>(in);		//converts to int in case it is not
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
	temp.in = in;
	return temp;
}
Integer Integer::sub(const Integer &i)
{
	Integer temp;
	temp.in = in;
	return temp;
}
Integer Integer::mul(const Integer &i)
{
	Integer temp;
	temp.in = in;
	return temp;
}
Integer Integer::div(const Integer &i)
{
	Integer temp;
	temp.in = in;
	return temp;
}
void Integer::print()
{
	cout << in << endl;
}