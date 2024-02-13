 #include <iostream>
#include "Integer.h"

using namespace std;

Integer::Integer()
{
	this->equals(0);
}
void Integer::equals(int n) 
{
	num = n;
}
int Integer::toInt()
{
	return this->num;
}
Integer Integer::add(const Integer &f) 
{
	Integer tmp;
	tmp.num = num;
	return tmp;
}
Integer Integer::sub(const Integer &f) 
{
	Integer tmp;
	tmp.num = num;
	return tmp;
}
Integer Integer::mul(const Integer &f)
{
	Integer tmp;
	tmp.num = num;
	return tmp;
}
Integer Integer::div(const Integer &f)
{
	Integer tmp;
	tmp.num = num;
	return tmp;
}
void Integer::print() 
{
	cout << num << endl;
}