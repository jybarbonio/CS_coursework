#pragma once
#include "Double.h"

class Integer 
{
private:
	int num;
public:
	void equals(int n);
	int toInt();
	Integer add(const Integer &f);
	Integer sub(const Integer &f);
	Integer mul(const Integer &f);
	Integer div(const Integer &f);
	void print();

	Integer();
};