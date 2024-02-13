/*
BigDecimalException.cpp
John Barbonio
6/4/2020
: This header file provides function definitions and (derived from CharException) exception handling for BigDecimal.h to BigDecimal.cpp.
: Since the function code is somewhat short, BigDecimalException.h contains
: the cpp code and there's no corresponding cpp file as a result
*/
#ifndef BIGDECIMALEXCEPTION
#define BIGDECIMALEXCEPTION

#include "CharException.h"
using std::exception;
using std::string;

class BigDecimalException : public CharException
{
public:
	/*
	Function: Constructors
	Author: John Barbonio
	Date: 6/5/2020
	Desc: Constructors that set the (derived) data section of CharException to either default or arg-passed values.
	There is no need to rewrite function since they serve the exact same purpose for BigDecimal
	I/O: n/a, (string), (int, string) | n/a, n/a, n/a
	*/
	BigDecimalException() { this->error = 0, this->msg = "Unknown BD"; }
	BigDecimalException(std::string m) { this->error = -1, this->msg = m; }
	BigDecimalException(int error, std::string m) { this->error = error, this->msg = m; }

	/*
	Function: query
	Author: John Barbonio
	Date: 6/5/2020
	Desc: getter that as a derived class substitues the base func in CharException and 
	obtains the message from where the error was thrown in code
	I/O: n/a, const char arr
	*/
	// virtual const char* query() { return msg.c_str(); }
	/*
	Function: getMessage
	Author: John Barbonio
	Date: 6/5/2020
	Desc: getter that as a derived class substitues the base func in CharException and
	returns the message from where the error was thrown in code
	I/O: n/a, string
	*/
	// virtual std::string getMessage() { return this->msg; }
	/*
	Function: getCode
	Author: John Barbonio
	Date: 6/5/2020
	Desc: getter that as a derived class substitues the base func in CharException and
	obtains the error code set by where the error was thrown in code
	I/O: n/a, int
	*/
	// virtual int getCode() { return this->error; }

};

#endif