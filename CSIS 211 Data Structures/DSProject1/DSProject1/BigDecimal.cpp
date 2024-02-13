/*
BigDecimal.cpp
John Barbonio
6/4/2020
: BigDecimal.cpp defines the function functionality of complex type BigDecimal that will
be used to house Char types defined by Char.h
*/
#include "BigDecimal.h"

/*
Function: Constructor BigDecimal
Author: John Barbonio
Date: 6/5/2020
Desc: constructor that sets the "has decimal" (hasDec) flag to false and adds 3 default chars  "0.0" to the vector as Char types
I/O: n/a, n/a
*/
BigDecimal::BigDecimal() 
{
	/*
	this->container.push_back(new Char('0'));
	this->container.push_back(new Char('.'));
	this->container.push_back(new Char('0'));
	*/
	//this->hasDec = false;
	this->equals("0.0");
}
/*
Function: Constructor BigDecimal(string)
Author: John Barbonio
Date: 6/5/2020
Desc: constructor that sets the "has decimal" (hasDec) flag to false and adds the chars of string to the vector as Char types
I/O: string, n/a
*/
BigDecimal::BigDecimal(std::string value)
{
	//this->hasDec = false;
	this->equals(value);
}
/*
Function: equals(char)
Author: John Barbonio
Date: 6/5/2020
Desc: func that sweeps the passed char and verifies if it's 1. a valid number and
2. if it is, then adds it to the vector of the data section. vector is also cleared as it sets
the array as equal to something else.
I/O: char, n/a
*/
void BigDecimal::equals(char ch) 
{	
	this->hasDec = false;

	if (!isdigit(static_cast<int>(ch)))
	{
		throw BigDecimalException("Invalid Numeral BD");
	}
	else
	{
		this->container.clear();
		this->container.push_back(new Char(ch));
	}
}
/*
Function: equals(string)
Author: John Barbonio
Date: 6/5/2020
Desc: func that iterates through each char of the passed string and verifies if it's 1. all valid numbers and has only ONE '.' and
2. if it is, adds each char to the vector of the data section. vector is also cleared as it sets the array as equal to something 
else. Also, if the string is invalidated by a non-number or an extra '.', the BigDecimal vector is deleted and an error is thrown
I/O: string, n/a
*/
void BigDecimal::equals(std::string value) 
{
	this->hasDec = false;

	this->container.clear();
	for (unsigned int i = 0; i < value.length(); i++)
	{
		if (std::isdigit(value[i]))
		{
			this->container.push_back(new Char(value[i]));
		}
		else if (value[i] == '.' && this->hasDec != true) 
		{
			this->hasDec = true;
			this->container.push_back(new Char(value[i]));
		}
		else 
		{
			i = value.length();
			this->container.pop_back();	// bail on this addition to the vector as it has invalid chars,
			// throws before it is added to the vector in main
			throw BigDecimalException("Invalid Numeral BD");
		}
	}
}
/*
Function: add(BigDecimal)
Author: John Barbonio
Date: 6/5/2020
Desc: func adds the data sections of two BigDecimal types (via getters if their section as in double + double), uses
a temp BigDecimal as intermediary to add the two, and to properly return it as a BigDecimal instead of a double
I/O: BigDecimal, BigDecimal
*/
BigDecimal BigDecimal::add(BigDecimal b) 
{
	BigDecimal temp_bg;
	std::ostringstream oss;
	double temp = (this->toDouble() + b.toDouble());

	// setprecision is used to maintain accuracy after casting from double to string (for reasons it loses accuracy at the edge decimals)
	oss << std::setprecision(this->container.size() - 1) << temp;
	std::string stemp = oss.str();
	temp_bg.equals(stemp);
	return temp_bg;
}
/*
Function: sub(BigDecimal)
Author: John Barbonio
Date: 6/5/2020
Desc: func subs the data sections of two BigDecimal types (via getters if their section as in double - double), uses
a temp BigDecimal as intermediary to sub the two, and to properly return it as a BigDecimal instead of a double
I/O: BigDecimal, BigDecimal
*/
BigDecimal BigDecimal::sub(BigDecimal b)
{
	BigDecimal temp_bg;
	std::ostringstream oss;
	double temp = (this->toDouble() - b.toDouble());

	// setprecision is used to maintain accuracy after casting from double to string (for reasons it loses accuracy at the edge decimals)
	oss << std::setprecision(this->container.size() - 1) << temp;
	std::string stemp = oss.str();
	temp_bg.equals(stemp);
	return temp_bg;
}
/*
Function: toDouble const
Author: John Barbonio
Date: 6/5/2020
Desc: const func getter that returns a double type of the data section vector assembled as one variable
I/O: n/a , double
*/
double BigDecimal::toDouble() const
{
	std::ostringstream oss;
	oss << std::setprecision(this->container.size() - 1) << this->toString();
	std::string stemp = oss.str();
	return std::stod(stemp);
}
/*
Function: toString const
Author: John Barbonio
Date: 6/5/2020
Desc: const func getter that returns a string type of the data section vector assembled as one variable
I/O: n/a , string
*/
std::string BigDecimal::toString() const
{
	std::string temp;
	for(unsigned int i = 0; i < this->container.size(); i++)
	{
		temp = temp + this->container[i]->toString();
	}
	return temp;
}
/*
Function: at
Author: John Barbonio
Date: 6/5/2020
Desc: const Char func getter that returns a Char type of the specific index of the data section vector
I/O: n/a , Char
*/
Char BigDecimal::at(int index) const
{
	Char temp;
	if (index > this->container.size() || index < 0)
	{
		// prints the last element of the array instead of the index is above the number length
		temp.equals(*this->container[this->container.size() - 1]);
		throw BigDecimalException("Error index out of range.");
	}
	else
	{
		temp.equals(*this->container[index]);
	}
	return temp;


}
/*
Function: wholeNumber
Author: John Barbonio
Date: 6/5/2020
Desc: returns only the whole number portion of the data section as one variable i.e. 542 of 542.56
I/O: n/a , int
*/
int BigDecimal::wholeNumber() 
{
	std::string temp;
	for(unsigned int i = 0; i < this->container.size(); i++) 
	{
		if (this->container.at(i)->toChar() == '.') 
		{
			i = this->container.size();
		}
		else 
		{
			temp += this->container.at(i)->toChar();
		}
	}
	return std::stoi(temp);
}
/*
Function: fraction
Author: John Barbonio
Date: 6/5/2020
Desc: returns only the decimal (fractional) portion of the data section as one variable i.e. .56 of 542.56
I/O: n/a , double
*/
double BigDecimal::fraction() 
{
	bool decimal_flag = false;
	std::string temp;
	for (unsigned int i = 0; i < this->container.size(); i++)
	{
		if (decimal_flag == true)
		{
			temp += this->container.at(i)->toChar();
		}

		if (this->container.at(i)->toChar() == '.')
		{
			decimal_flag = true;
			temp += this->container.at(i)->toChar();
		}
	}
	return std::stod(temp);
}