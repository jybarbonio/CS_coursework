/*
PairList.h
John Barbonio
6/23/2020
: This header file provides both the function definitions and function code for PairList.h, template classes cannot have a corresponding ccp file.
It extends std::vector using type Pair<T> to both store and and handle the values of a Pair object with the abiity to add, delete, or read them from the vector.
Modifications have been made based on Professor Stevenson's code in the Unit 8 Discussion
*/
#pragma once

#include "Pair.h"
#include "LinkedList.h"

template <class T>
class PairList : public LinkedList<Pair<T>>
{
public:
	PairList();
	PairList(T first, T second);
	PairList(Pair<T> pair[], int size);

	void addPair(T first, T second);
	void addPair(const Pair<T>& pair);
	void deletePair(T first, T second);

	T getFirst(T second) const;
	T getSecond(T first) const;

	void printList();

};
/*
Function: PairList(void)
Author: John Barbonio (edited based on code from Unit 8 Discussion)
Date: 6/20/2020
Desc: This is a default constructor, does not do anything to the PairList (inherits vector)
I: n/a
O: n/a
*/
template <class T>
PairList<T>::PairList() 
{
	// blank
}
/*
Function: PairList(T first, T second)
Author: John Barbonio (edited based on code from Unit 8 Discussion)
Date: 6/20/2020
Desc: This is a constructor which has two parameters to add a single pair upon initialization to the PairList (inherited vector)
I: template, template
O: n/a
*/
template <class T>
PairList<T>::PairList(T first, T second)
{
	this->addPair(first, second);
}
/*
Function: PairList(array of pairs template, int)
Author: John Barbonio (edited based on code from Unit 8 Discussion)
Date: 6/18/2020
Desc: This is a constructor which has two parameters, a populated array, and the specified up-to size which to copy a pair array to this PairList
I: array of Pairs template, int
O: n/a
*/
template <class T>
PairList<T>::PairList(Pair<T> pair[], int size)
{
	Node<Pair<T>>* p = new Node<Pair<T>>;
	p = this->Head;

	for (unsigned int i = 0; i < size; i++) 
	{
		this->addPair(pair[i]);
	}
}
/*
Function: addPair(T first, T second)
Author: John Barbonio
Date: 6/20/2020
Desc: This function pushes back the vector with a Pair with the two variables within that being set by the passed parameters
I: template var, template var (goes into a Pair object, which is then added to the PairList vector)
O: n/a
*/
template <class T>
void PairList<T>::addPair(T first, T second)
{
	this->addToEnd(Pair<T>(first, second));
}
/*
Function: addPair(Pair<T>& pair)
Author: John Barbonio (edited based on code from Unit 8 Discussion)
Date: 6/20/2020
Desc: This function adds to the LinkedList an already existing Pair object, utilizes indirect addressing which is much more confident
than direct addressing in returning the correct address over different compilers/operating systems
I: Pair<T>&
O: n/a
*/
template <class T>
void PairList<T>::addPair(const Pair<T>& pair) 
{
	this->addToEnd(pair);
}
/*
Function: deletePair(T first, T second)
Author: John Barbonio (edited based on code from Unit 8 Discussion)
Date: 6/20/2020
Desc: This function sweeps the LinkedList with an pointer and deletes the closest-to-the-front instance of the Pair with the specified passed parameters, and erases
the slot in the LinkedList, reducing its size
I: template var, template var
O: n/a
*/
template <class T>
void PairList<T>::deletePair(T first, T second)
{
	Node<Pair<T>>* p = this->Head;

	// is there any way to avoid this first checking?
	if (p->Data.getFirst() == first || p->Data.getSecond() == second)
	{
		Node<Pair<T>>* t_deletePtr = p;
		this->Head = p->Next;

		delete t_deletePtr;

		return;	// only does one deletion then exits function
	}

	// checking of every Node after the first
	while (p->Next != NULL)
	{
		if (p->Next->Data.getFirst() == first && p->Next->Data.getSecond() == second)
		{
			Node<Pair<T>>* t_deletePtr = p->Next;
			p->Next = p->Next->Next;	// Next is deleted as it matches the parameters, reconnecting the ground to the Next existing link
			delete t_deletePtr;

			return;
		}
		p = p->Next;
	}
}
/*
Function: getFirst(T second)
Author: John Barbonio
Date: 6/20/2020
Desc: This function sweeps the vector to find a corresponding first value that is paired with a second value that matches the passed
parameter, returning the closest match found at the bottom of the stack. Iterator implementation has been removed and func simplified
I: template var
O: template var (specified in main via PairList vector type)
*/
template <class T>
T PairList<T>::getFirst(T second) const
{
	Node<Pair<T>>* p = new Node<Pair<T>>;
	p = this->Head;

	while (p != NULL)
	{
		if (p->Data.getSecond() == second)
		{
			return p->Data.getFirst();
		}
	}
	return T();
}
/*
Function: getSecond(T first)
Author: John Barbonio (edited based on code from Unit 8 Discussion)
Date: 6/29/2020
Desc: This function sweeps the LinkedList to find a corresponding second value that is paired with a first value that matches the passed
parameter, returning the closest match found at the bottom of the stack.
I: template var
O: template var (specified in main via PairList vector type)
*/
template <class T>
T PairList<T>::getSecond(T first) const
{
	Node<Pair<T>>* p = new Node<Pair<T>>;
	p = this->Head;

	while (p != NULL)
	{
		if (p->Data.getFirst() == first)
		{
			return p->Data.getSecond();
		}
	}
	return T();
}
/*
Function: printList()
Author: John Barbonio (edited based on code from Unit 8 Discussion)
Date: 6/20/2020
Desc: This function sweeps the LinkedList with an iterator and prints the values of all the Pairs present within the vector
I: template var
O: template var (specified in main via PairList vector type)
*/
template <class T>
void PairList<T>::printList() 
{
	Node<Pair<T>>* p = new Node<Pair<T>>;
	p = this->Head;

	while(p != NULL)
	{
		std::cout << p->Data.getFirst() << " | " << p->Data.getSecond() << std::endl;
		p = p->Next;
	}
}