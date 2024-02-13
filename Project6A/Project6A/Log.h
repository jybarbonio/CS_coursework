/*
Log.h
John Barbonio
7/10/2020
: Log is a Data unit meant to be stored in the LinkedList, it keeps track of a name, number, and its own position within a LinkedList
*/

#pragma once

#include <iostream>
using std::iostream;

struct Log
{
	int position;
	std::string number;
	std::string name;
};