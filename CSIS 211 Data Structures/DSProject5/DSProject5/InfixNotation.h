/*
InfixNotation.h
John Barbonio
6/27/2020
: This header file processes an infix notation expression utilizing the RPN format. utilizes a stack in-part to solve the equations
*/

#pragma once

#include "RPN.h"

class InfixNotation : public RPN
{
private:
	bool isOperator(std::string c);
	bool isOperand(std::string s);
public:
	std::string infixToPostfix(std::string expression);
	std::string doPrecedence(std::string token, std::string postfix);
	int precedence(string x);
};
/*
Function: infixToPostfix(std::string)
Author: John Barbonio
Date: 6/27/2020
Desc: this constructor takes in the expression to be translated and returns an RPN format
I: std::string
O: n/a
*/
std::string InfixNotation::infixToPostfix(std::string expression) 
{
	std::string postfix = "";

	for (unsigned int i = 0; i < expression.length(); i++)
	{
		std::stringstream ss;
		ss.clear();
		ss << expression[i];
		if(this->isOperand(ss.str()))
		{
			postfix += ss.str() + " ";
		}
		else if(ss.str() == "(") 
		{
			this->push(ss.str());
		}
		else if (ss.str() == ")") 
		{
			std::string topToken = this->pop();
			while(topToken != "(") 
			{
				postfix += topToken + " ";
				topToken = this->pop();
			}
		}
		else 
		{
			while(this->Head != NULL && this->precedence(this->peek()) >= this->precedence(ss.str())) 
			{
				postfix += this->pop() + " ";
			}
			this->push(ss.str());
		}
	}
	while(this->Head != NULL) 
	{
		postfix += this->pop() + " ";
	}
	return postfix;
}
/*
Function: doPrecedence(string, string)
Author: John Barbonio
Date: 6/27/2020
Desc: pushes and pops elements of the expression based on their operator precedence
I: string, string
O: string
*/
std::string InfixNotation::doPrecedence(std::string token, std::string postfix)
{
	if(this->precedence(token) > this->precedence(this->peek())) 
	{
		this->push(token);
	}
	else if (this->precedence(token) == this->precedence(this->peek())) 
	{
		postfix += this->pop() + " ";
		this->push(token);
	}
	else if (this->precedence(token) < this->precedence(this->peek())) 
	{
		postfix += this->pop() + " ";
	}
	return postfix;
}
/*
Function: precedence(string)
Author: John Barbonio
Date: 6/27/2020
Desc: returns a number of precedence based on what the string (operator) passed to it is
I: string, string
O: n/a
*/
int InfixNotation::precedence(std::string x) 
{
	if (x == "+" || x == "-") {	return 1; }
	if (x == "*" || x == "/" || x == "%") {	return 2; }
	if (x == "^") { return 3; }

	return 0;
}
/*
Function: isOperator(string)
Author: John Barbonio
Date: 6/27/2020
Desc: returns a bool on whether the string passed to it is actually an operator or not
I: string
O: bool
*/
bool InfixNotation::isOperator(std::string c)
{
	return c == "+" || c == "-" || c == "*" || c == "/" || c == "^" || c == "(" || c == ")";
}
/*
Function: isOperand(string)
Author: John Barbonio
Date: 6/27/2020
Desc: returns a bool on whether the string passed or it's isOperator test is an operand (parentheses)
I: string
O: bool
*/
bool InfixNotation::isOperand(std::string s)
{
	if(!this->isOperator(s) && s != ")" && s != "(") 
	{
		return true;
	}
	else 
	{
		return false;
	}
}
