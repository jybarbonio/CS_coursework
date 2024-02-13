/*
BinaryTreeException.h
John Barbonio
7/1/2020
: This header file is derived from exception and is meant to report errors related to BinaryTree.h or its derivatives
*/
#pragma once

#include <string>
using std::string;
using std::exception;

class BinaryTreeException : public exception
{
protected:
	int error;
	std::string msg;
public:
	/*
	Function: constructors
	Author: John Barbonio
	Date: 7/2/2020
	Desc: these constructors define and take as parameters error messages and error codes. used by the programmer to catch errors in code
	I: n/a
	O: n/a
	*/
	BinaryTreeException() { this->error = 0, this->msg = "Unknown BinaryTree related error."; }
	BinaryTreeException(std::string m) { this->error = -1, this->msg = m; }
	BinaryTreeException(int error, std::string m) { this->error = error, this->msg = m; }

	/*
	Function:
	Author: John Barbonio
	Date:  7/2/2020
	Desc: these functions return error messages thrown in code, and/or error codes
	I: n/a
	O: n/a
	*/
	virtual const char* query() { return msg.c_str(); }
	virtual std::string getMessage() { return this->msg; }
	virtual int getCode() { return this->error; }
};