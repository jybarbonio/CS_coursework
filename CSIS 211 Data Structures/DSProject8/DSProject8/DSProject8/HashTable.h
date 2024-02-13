/*
HashTable.h
John Barbonio
7/9/2020
: This header file defines the functions of HashTable.cpp, it is derived from vector and is vaguely like a vector array of linkedlists,
those linkedlists containing Logs
*/

#pragma once

#include <vector>
using std::vector;
#include <iterator>
using std::iterator;
#include <fstream> 
using std::fstream;

#include "Log.h"
#include "LinkedList.h"

// the end user doesn't need to use the actual vector functions if the goal is to only serve as a specialized vector for hashing
class HashTable : private std::vector<LinkedList<Log>>
{
private:
	const int TABLE_SIZE;

	// initializes vector hash table
	void initHashTable();
	//hash

	// NOTE: Assignment suggests using some internal functions to solve problems
public:
	HashTable() : TABLE_SIZE(53)
		{ this->initHashTable(); }
	HashTable(int tablesize) : TABLE_SIZE(tablesize)
		{ this->initHashTable(); }

	void loadFile();

	double hash(double key);
	int hash(char* s, int tablesize);
	void addHash(int index, std::string name, std::string number);

	void search();
	// int search
	
	void printTable();
};