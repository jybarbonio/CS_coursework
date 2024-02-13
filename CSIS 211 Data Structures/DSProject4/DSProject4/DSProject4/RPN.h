/*
RPN.h
John Barbonio
6/27/2020
: This is a Reverse Polish Notation calculator that solves RPN format expressions, is derived from Stack whose template is set to std::string
*/

#pragma once

#include <sstream>
#include "Stack.h"

class RPN : public Stack<std::string> 
{
private:

public:
	RPN();
	RPN(std::string expression);
	void solve(std::string expression);
	void clear();
};
/*
Function: RPN constructor
Author: John Barbonio
Date: 6/27/2020
Desc: constructor which does nothing but is need when an instance is created
I: n/a
O: n/a
*/
RPN::RPN() 
{
}
/*
Function: RPN(string)
Author: John Barbonio
Date: 6/27/2020
Desc: constructor takes a string expression and passes it to the solve function
I: std::string
O: n/a
*/
RPN::RPN(std::string expression)
{
	this->solve(expression);
}
/*
Function: solve(string)
Author: John Barbonio
Date: 6/27/2020
Desc: function parses the RPN expression and returns the answer
I: std::string
O: n/a
*/
void RPN::solve(std::string expression)
{
	// 3 2 + 5 *
	std::string s1 = "";
	unsigned int i = 0;
	while(i < expression.length())
	{

		if(std::isdigit(expression[i]))
		{
			s1 += expression[i];
		}
		else if(expression[i] == ' ' && s1 != "")
		{
			this->push(s1);
			s1 = "";
		}
		else 
		{
			std::stringstream ss;
			double t1;
			double t2;

			switch(expression[i])
			{
			case '+':
				t1 = std::stod(this->pop());
				t2 = std::stod(this->pop());
				t1 += t2;
				ss << t1;

				this->push(ss.str());
				break;
			case '-':
				t1 = std::stod(this->pop());
				t2 = std::stod(this->pop());
				t1 -= t2;
				ss << t1;

				this->push(ss.str());
				break;
			case '*':
				t1 = std::stod(this->pop());
				t2 = std::stod(this->pop());
				t1 *= t2;
				ss << t1;

				this->push(ss.str());
				break;
			case '/':
				t1 = std::stod(this->pop());
				t2 = std::stod(this->pop());
				t1 /= t2;
				ss << t1;

				this->push(ss.str());
				break;
			default:
				break;
			}
		}
		i++;
	}
}
/*
Function: clear
Author: John Barbonio
Date: 6/27/2020
Desc: function clears the RPN stack after the answer is found
I: n/a
O: n/a
*/
void RPN::clear() 
{
	this->pop();
}