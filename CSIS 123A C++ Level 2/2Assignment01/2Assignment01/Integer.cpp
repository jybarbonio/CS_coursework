#include <iostream>
#include "Integer.h"

using namespace std;

Integer::Integer()		//default constructor
{
	this->equals(0.0);
}
Integer::Integer(int i) 
{

}
void Integer::equals(int i) 
{
	in = i;
}
int Integer::toInt() 
{
	return this->in;
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