/*
PairList.h
John Barbonio
6/11/2020
: This header file provides both the function definitions and function code for PairList.h, template classes cannot have a corresponding ccp file.
It extends std::vector using type Pair<T> to both store and and handle the values of a Pair object with the abiity to add, delete, or read them from the vector.
*/
#pragma once

#include "Pair.h"

#include <vector>
using std::vector;

template <class T>
class PairList : public std::vector<Pair<T>>
{
private:
	class std::vector<Pair<T>>::iterator it;
public:
	void addPair(T first, T second);
	void addPair(Pair<T> pair);
	void deletePair(T first, T second);

	T getFirst(T second);
	T getSecond(T first);

	void printList();

};
/*
Function: addPair(T first, T second)
Author: John Barbonio
Date: 6/11/2020
Desc: This function pushes back the vector with a Pair with the two variables within that being set by the passed parameters
I: template var, template var (goes into a Pair object, which is then added to the PairList vector)
O: n/a
*/
template <class T>
void PairList<T>::addPair(T first, T second)
{
	this->push_back(Pair<T>(first, second));
}
/*
Function: addPair(Pair<T> pair)
Author: John Barbonio
Date: 6/11/2020
Desc: This function pushes back the vector with an already existing Pair object
I: Pair<T>
O: n/a
*/
template <class T>
void PairList<T>::addPair(Pair<T> pair) 
{
	this->push_back(pair);
}
/*
Function: deletePair(T first, T second)
Author: John Barbonio
Date: 6/11/2020
Desc: This function sweeps the vector with an iterator and deletes the closest-to-the-front instance of the Pair with the specified passed parameters, and erases
the slot in the vector, reducing its size
I: template var, template var
O: n/a
*/
template <class T>
void PairList<T>::deletePair(T first, T second)
{
	bool match = false;
	for (this->it = this->begin(); it != this->end(); )
	{
		Pair<T> test = *this->it;

		if (test.getFirst() == first && test.getSecond() == second)
		{
			match = true;
			std::cout << "Found! Deleted first instance closest to the the start (begin) of the vector." << std::endl;
			this->it = this->erase(this->it);	// vector erase function increments the iterator. If vector is empty, it iterates vector over the end, causing error
			this->it = this->end();	// stops at first deletion
			return;
		}
		else
		{
			std::cout << "Not the Pair specified to be deleted" << std::endl;
			++this->it;
		}
	}
	if (this->it == this->end() && match == false)
	{
		std::cout << "Could not find a Pair TO DELETE that matches the specified parameters" << std::endl;
	}
}
/*
Function: getFirst(T second)
Author: John Barbonio
Date: 6/11/2020
Desc: This function sweeps the vector with an iterator to find a corresponding first value that is paired with a second value that matches the passed
parameter, returning the closest match found at the bottom of the stack.
I: template var
O: template var (specified in main via PairList vector type)
*/
template <class T>
T PairList<T>::getFirst(T second)
{
	for (this->it = this->begin(); this->it != this->end(); ++this->it)
	{
		Pair<T> test = *this->it;

		if (test.getSecond() == second)
		{
			return test.getFirst();
		}
		else
		{
			std::cout << "Second does not match" << std::endl;
		}
	}
	if(this->it == this->end()) 
	{
		std::cout << "Could not find any Pair with the specified second parameter" << std::endl;
		return T();
	}
}
/*
Function: getSecond(T first)
Author: John Barbonio
Date: 6/11/2020
Desc: This function sweeps the vector with an iterator to find a corresponding second value that is paired with a first value that matches the passed
parameter, returning the closest match found at the bottom of the stack.
I: template var
O: template var (specified in main via PairList vector type)
*/
template <class T>
T PairList<T>::getSecond(T first)
{
	for (this->it = this->begin(); this->it != this->end(); ++this->it)
	{
		Pair<T> test = *this->it;

		if (test.getFirst() == first)
		{
			return test.getSecond();
		}
		else
		{
			std::cout << "First does not match" << std::endl;
		}
	}
	if (this->it == this->end())
	{
		std::cout << "Could not find any Pair with the specified first parameter" << std::endl;
		return T();
	}
}
/*
Function: printList()
Author: John Barbonio
Date: 6/11/2020
Desc: This function sweeps the vector with an iterator and prints the values of all the Pairs present within the vector
I: template var
O: template var (specified in main via PairList vector type)
*/
template <class T>
void PairList<T>::printList() 
{
	this->it = this->begin();
	if(this->begin() == this->end())	// this means vector is empty
	{
		std::cout << "Cannot print. Vector is empty." << std::endl;
	}
	else 
	{
		for (this->it = this->begin(); this->it != this->end(); ++this->it)
		{
			Pair<T> test = *this->it;
			std::cout << test.getFirst() << " | " << test.getSecond() << std::endl;
		}
	}
}