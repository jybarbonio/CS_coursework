/*
BigDecimal.h
John Barbonio
6/4/2020
: this header file defines the properties and functions of a complex type BigDecimal that will
be used to house Char types defined by Char.h
*/
#ifndef BIGDECIMAL
#define BIGDECIMAL

#include "Char.h"
#include "BigDecimalException.h"
#include <vector>
using std::vector;

class BigDecimal 
{
private:
	bool hasDec;
	std::vector<Char*>container;
public:
	// Constructors
	BigDecimal();	// tested
	BigDecimal(std::string value);	// tested

	// Mutators
	void equals(char ch);	// tested
	void equals(std::string value);	// tested

	BigDecimal add(BigDecimal b);	// tested
	BigDecimal sub(BigDecimal b);	// tested

	// Accessors
	double toDouble() const;	// tested (strange automatic precision reduction when returned and printed), performance/accuracy thing?
	std::string toString() const;	// tested
	Char at(int index) const;	// tested

	int wholeNumber();	// tested
	double fraction();	// tested, watch the if statement ladder
};

#endif