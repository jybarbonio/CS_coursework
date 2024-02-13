/*
HashTable.cpp
John Barbonio
7/9/2020
: This cpp file is a HashTable that stores names and phonenumbers, and searches them up using hashed versions of names
*/

#include "HashTable.h"

/*
Function: loadFile
Author: John Barbonio
Date: 7/10/2020
Desc: This function loads the names and phone numbers from a text file and loads those two vars into a Log, which is then stored
in a linked list at the vector index that the name hashes to
I: n/a
O: n/a
*/
void HashTable::loadFile() 
{
	std::ifstream infile("Hashdata.txt");
	std::string in;

	if(!infile) 
	{
		throw LinkedListException("Hashtable::loadFile : unable to load file for reading.");
	}
	while(std::getline(infile, in)) 
	{
		std::string name;
		std::string number;

		std::regex rgName("([A-Z]?[a-z]+)");
		std::regex rgNum("(\\(.[^;]+)");
		std::smatch match;

		std::regex_search(in, match, rgName);
		name = match.str();

		std::regex_search(in, match, rgNum);
		number = match.str();

		// regex not working correctly
		this->addHash(this->hash(&name[0], this->TABLE_SIZE), name, number);
	}
	infile.close();
}
/*
Function: initHashTable
Author: John Barbonio
Date: 7/10/2020
Desc: This function initializes the vector with empty linked lists with null heads
I: n/a
O: n/a
*/
void HashTable::initHashTable() 
{
	for(unsigned int i = 0; i < this->TABLE_SIZE; i++) 
	{
		LinkedList<Log>* t = new LinkedList<Log>;
		// head is empty, as in defined as NULL in LinkedList.h
		this->push_back(*t);
	}
}
/*
Function: hash
Author: John Barbonio
Date: 7/10/2020
Desc: This function returns the LinkedList index from a hashed double (unused but part of the assignment requirements)
I: double
O: double
*/
double HashTable::hash(double key)
{
	return std::fmod(key, this->TABLE_SIZE);
}
/*
Function: hash
Author: John Barbonio
Date: 7/10/2020
Desc: This function returns the LinkedList index which is then used to store a Log at that location of the HashTable
I: char*, int
O: int
*/
int HashTable::hash(char* s, int tablesize)
{
	char* p = s;
	int hashVal = 5381;

	while(*p)
	{
		hashVal *= 33;
		hashVal += static_cast<int>(*p++);
	}
	if((hashVal % tablesize) < 0)
	{
		return ((hashVal % tablesize) * -1);
	}
	return (hashVal % tablesize);
}
/*
Function: hash
Author: John Barbonio
Date: 7/10/2020
Desc: This function returns the LinkedList index which is then used to store a Log at that location of the HashTable
I: int, string, string
O: void
*/
void HashTable::addHash(int index, std::string name, std::string number)
{
	LinkedList<Log> t = this->at(this->hash(&name[0], this->TABLE_SIZE));

	Log log;
	log.name = name;
	log.number = number;
	log.position = t.getSize() + 1;

	this->at(index).addToEnd(log);
}
/*
Function: search
Author: John Barbonio
Date: 7/10/2020
Desc: This function goes to the index that the name parameter hashes to, and searches the linkedlist at that location
parsing for a name that matches said parameter, and prints out all the information of that Log among the linked list
I: void
O: void
*/
void HashTable::search()
{
	bool cont = true;
	char o;

	while(cont == true) 
	{
		std::cout << "Please enter a name:" << std::endl;
		std::string search;
		std::cin >> search;
		LinkedList<Log> t = this->at(this->hash(&search[0], this->TABLE_SIZE));
		std::cout << this->hash(&search[0], this->TABLE_SIZE) + 1 << " (" << t.linearSearch(search) << std::endl;
	
		std::cout << "Search for another name's number? y/n" << std::endl;
		std::cin >> o;
		switch(o) 
		{
		case 'y':
			cont = true;
			break;
		case 'n':
			cont = false;
			std::cout << "Exiting." << std::endl;
			return;
			break;
		default:
			break;
		}
	}
}
/*
Function: printTable
Author: John Barbonio
Date: 7/10/2020
Desc: This function prints all the contents of the hashtable
I: void
O: void
*/
void HashTable::printTable() 
{
	for(unsigned int i = 0; i < this->size(); i++) 
	{
		std::cout << "[ INDEX " << i + 1 << " ]" << std::endl;
		this->at(i).printList();
	}
	return;
}