#pragma once
#include <string>
#include "Double.h"

using std::string;

class Integer
{
private:
	int num;
public:
	void equals(int n);
	void equals(const Integer &i);
	void equals(string s);
	int toInt();
	Integer add(int num);
	Integer sub(int num);
	Integer mul(int num);
	Integer div(int num);

	int toInt() const;
	string toString() const;

	Integer add(const Integer &f);
	Integer sub(const Integer &f);
	Integer mul(const Integer &f);
	Integer div(const Integer &f);
	bool operator == (const Integer &i);
	bool operator - (const Integer &i);
	bool operator * (const Integer &i);
	bool operator / (const Integer &i);

	void print();

	Integer();
	Integer(int num);
	~Integer();
};