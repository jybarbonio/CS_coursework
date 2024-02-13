/*
CharException.h
John Barbonio
6/4/2020
: This header file provides function definitions and (derived from <exception>) exception handling for Char.h to Char.cpp.
: Since the function code is somewhat short, CharException.h contains
: the cpp code and there's no corresponding cpp file as a result
*/
#ifndef CHAREXCEPTION
#define CHAREXCEPTION

#include <string>
using std::string;
using std::exception;

class CharException : public exception
{
protected:
	int error;
	std::string msg;
public:
	/*
	Function: Constructors
	Author: John Barbonio
	Date: 6/5/2020
	Desc: these constructors assign the data section either default or argument-passed values, along with an optional int error num
	I/O: n/a , (string) , (int, string) | n/a, n/a, n/a
	*/
	CharException() { this->error = 0, this->msg = "Unknown CH"; }
	CharException(std::string m) { this->error = -1, this->msg = m; }
	CharException(int error, std::string m) { this->error = error, this->msg = m; }

	/*
	Function: query
	Author: John Barbonio
	Date: 6/5/2020
	Desc: getter that obtains the error message from where an error is thrown in code
	I/O: n/a, const char pointer
	*/
	virtual const char* query() { return msg.c_str(); }

	/*
	Function: getMessage
	Author: John Barbonio
	Date: 6/5/2020
	Desc: getter that returns the message from where the error was thrown in code
	I/O: n/a, const char arr
	*/
	virtual std::string getMessage() { return this->msg; }
	/*
	Function: getCode
	Author: John Barbonio
	Date: 6/5/2020
	Desc: getter that returns the error code set by where the error was thrown in code
	I/O: n/a, int
	*/
	virtual int getCode() { return this->error; }
};

#endif