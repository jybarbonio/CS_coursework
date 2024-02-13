/*
Char.h
John Barbonio
6/4/2020
: This header file provides the function definitions of Char.cpp, a complex
: (wrapper?) around primitive char to be used in tandem with BigDecimal.h to BigDecimal.cpp
*/
#ifndef CHAR
#define CHAR

#include "CharException.h"
#include <iostream>
#include <sstream>
#include <iomanip>
using std::stringstream;

class Char 
{
private:
	char data;
public:
	// Constructors
	Char();	// tested
	Char(char c);	// tested
	Char(int c);	// tested
	Char(std::string c); // tested
	Char(const Char& c);	// tested

	// Mutators
	void equals(char c);	// tested
	void equals(int c);	// tested
	void equals(const Char& c);	// tested

	char toChar() const;	// tested
	int toInt() const;	// tested
	std::string toString() const;	// tested
	std::string toHexString() const;	// tested
	
	// overloaded operators
	std::string operator + (char c);	// tested, these only work in print or else the char in the data section would have to be an array
	std::string operator + (const Char& c);	// tested
};

#endif