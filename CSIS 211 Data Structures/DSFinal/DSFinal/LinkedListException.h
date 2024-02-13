/*
LinkedListException.h
John Barbonio
7/23/2020
: This header file is derived from exception and is meant to report errors related to LinkedList
*/
#pragma once

#include <string>
using std::string;
using std::exception;

class LinkedListException : public exception 
{
protected:
	int error;
	std::string msg;
public:
	/*
	Function: constructors
	Author: John Barbonio
	Date: 6/27/2020
	Desc: these constructors define and take as parameters error messages and error codes. used by the programmer to catch errors in code
	I: n/a
	O: n/a
	*/
	LinkedListException() { this->error = 0, this->msg = "Unknown LL error."; }
	LinkedListException(std::string m) { this->error = -1, this->msg = m; }
	LinkedListException(int error, std::string m) { this->error = error, this->msg = m; }

	/*
	Function: 
	Author: John Barbonio
	Date: 6/27/2020
	Desc: these functions return error messages thrown in code, and/or error codes
	I: n/a
	O: n/a
	*/
	virtual const char* query() { return msg.c_str(); }
	virtual std::string getMessage() { return this->msg; }
	virtual int getCode() { return this->error; }
};