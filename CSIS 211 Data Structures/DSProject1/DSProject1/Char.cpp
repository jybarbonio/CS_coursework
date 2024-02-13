/*
Char.cpp
John Barbonio
6/4/2020
: This cpp file defines the functionality of the function definitions in Char.h
*/
#include "Char.h"

/*
Function: Char
Author: John Barbonio
Date: 6/5/2020
Desc: This function sets the single data section of char to binary zero
I/O: n/a , n/a
*/
Char::Char() 
{
	this->data = NULL;
}
/*
Function: Char(char c)
Author: John Barbonio
Date: 6/5/2020
Desc: This function sets the single data section of char to arg char c
I/O: char , n/a
*/
Char::Char(char c)
{
	this->equals(c);
}
/*
Function: Char(int c)
Author: John Barbonio
Date: 6/5/2020
Desc: This function sets the single data section of char to arg char c
I/O: int , n/a
*/
Char::Char(int c)
{
	this->equals(c);
}
/*
Function: Char(string c)
Author: John Barbonio
Date: 6/5/2020
Desc: This function sets the single data section of char to arg string c, throws a warning exception if string is over one char in size
I/O: string , n/a
*/
Char::Char(std::string c)
{
	if (c.size() > 1) 
	{
		throw CharException("Warning: passed string is over one char long, assigning only the first char of string.");
		this->equals(c[0]);
	}
	else 
	{
		this->equals(c[0]);
	}
}
/*
Function: Char(Char&)
Author: John Barbonio
Date: 6/5/2020
Desc: This function sets the single data section of this char to another Char data section
I/O: Char& , n/a
*/
Char::Char(const Char& c)
{
	this->equals(c);
}
/*
Function: equals(char)
Author: John Barbonio
Date: 6/5/2020
Desc: This void func sets the single data section of char to arg char
I/O: char , n/a
*/
void Char::equals(char c)
{
	this->data = c;
}
/*
Function: equals(int)
Author: John Barbonio
Date: 6/5/2020
Desc: This void func sets the single data section of char to arg int (casted to char)
I/O: int , n/a
*/
void Char::equals(int c)
{
	if(c < 32 || c > 127) 
	{
		throw CharException("Invalid Character CH");
	}
	else 
	{
		this->data = static_cast<char>(c);
	}
}
/*
Function: equals(Char&)
Author: John Barbonio
Date: 6/5/2020
Desc: This void func sets the single data section of char to another Char data section
I/O: Char& , n/a
*/
void Char::equals(const Char& c)
{
	this->data = c.data;
}
/*
Function: toChar() const
Author: John Barbonio
Date: 6/5/2020
Desc: This char func returns this data section as type char
I/O: n/a , char
*/
char Char::toChar() const
{
	return static_cast<char>(this->data);
}
/*
Function: toInt() const
Author: John Barbonio
Date: 6/5/2020
Desc: This int func returns this data section as type int
I/O: n/a , int
*/
int Char::toInt() const
{
	return static_cast<int>(this->data);
}
/*
Function: toString() const
Author: John Barbonio
Date: 6/5/2020
Desc: This string func returns this data section as type string
I/O: n/a , string
*/
std::string Char::toString() const
{
	std::string temp;
	std::stringstream ss;
	ss << this->data;
	ss >> temp;
	return temp;
}
/*
Function: toHexString() const
Author: John Barbonio
Date: 6/5/2020
Desc: This string func returns this data section as type string reinterpreted as hexadecimal
I/O: n/a , string (hex)
*/
std::string Char::toHexString() const
{
	std::string temp;
	std::stringstream ss;
	ss << std::hex << this->toInt();
	ss >> temp;
	return temp;
}
/*
Function: operator + (char c)
Author: John Barbonio
Date: 6/5/2020
Desc: This overloaded string operator func adds functionality to handle adding complex Char with primitive char
I/O: char , string
*/
std::string Char::operator + (char c)
{
	std::string temp = this->toString() + c;
	return temp;
}
/*
Function: operator + (Char&)
Author: John Barbonio
Date: 6/5/2020
Desc: This overloaded string operator func adds functionality to handle adding complex Char with another Char(&)
I/O: Char& , string
*/
std::string Char::operator + (const Char& c)
{
	std::string temp = this->toString() + c.toString();
	return temp;
}