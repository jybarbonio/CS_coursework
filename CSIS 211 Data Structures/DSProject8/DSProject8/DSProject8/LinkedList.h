/*
LinkedList.h
John Barbonio
7/9/2020
: This header file is defines a modified linked list made for a phonebook HashTable data structure, includes some Hashtable.h
specific functionality
to store Pairs
*/

#pragma once

#include <string>
using std::string;
#include <regex>
using std::regex;

#include "Node.h"
#include "Log.h"
#include "LinkedListException.h"

template <class T>
class LinkedList 
{
protected:
	Node<T>* Head = NULL;
public:
	LinkedList() {}
	void addToFront(T data);
	void addToEnd(T data);
	void insert(T search, T data, bool in_before = false);	// defaulted to adding after a specified Node data
	void deleteNode(T search);

	bool contains(T search);	// find?
	std::string linearSearch(std::string search);
	Node<T>* getHead() { return this->Head; }
	bool isEmpty() const;
	int getSize();

	void printList();
};
/*
Function: addToFront(T data)
Author: John Barbonio
Date: 6/27/2020
Desc: this function adds an element to the front of the LinkedList as well as rebind the Nodes to chain properly
I: T template
O: n/a
*/
template <class T>
void LinkedList<T>::addToFront(T data) 
{
	if (this->Head == NULL)
	{
		this->Head = new Node<T>;
		this->Head->Data = data;
		this->Head->Next = NULL;
		this->Head->Prev = NULL;
	}
	else
	{
		Node<T>* p = this->Head;

		while (p->Prev != NULL)
		{
			p = p->Prev;
		}

		Node<T>* n = new Node<T>;
		n->Data = data;
		n->Prev = NULL;

		p->Prev = n;
		n->Next = p;
	}
}
/*
Function: addToEnd(T) 
Author: John Barbonio
Date: 6/20/2020
Desc: This function creates a new node to be added and linked to the end of the Linked List
I: n/a
O: n/a
*/
template <class T>
void LinkedList<T>::addToEnd(T data) 
{
	if(this->Head == NULL)
	{
		this->Head = new Node<T>;
		this->Head->Data = data;
		this->Head->Next = NULL;
		this->Head->Prev = NULL;
	}
	else 
	{
		Node<T>* p = this->Head;

		while (p->Next != NULL)
		{
			p = p->Next;
		}

		Node<T>* n = new Node<T>;
		n->Data = data;
		n->Next = NULL;
		
		p->Next = n;
		n->Prev = p;
	}
}
/*
Function: insert(T, T)
Author: John Barbonio
Date: 6/20/2020
Desc: This function inserts a node at a specified position in the linked List
I: template, template
O: n/a
*/
template <class T>
void LinkedList<T>::insert(T search, T data, bool in_before) 
{
	// parses LinkedList looking for corresponding data section that matches parameter "search"
	while(this->Head->Prev != NULL) 
	{
		this->Head = this->Head->Prev;
	}


	Node<T>* p = this->Head;

	while (p->Data != search) 
	{
		p = p->Next;

		if (p->Next == NULL && p->Data != search)
		{
			throw LinkedListException("Warning in insert: no such element found.");
			return;
		}
	}

	Node<T>* n = new Node<T>;
	Node<T>* t = new Node<T>;

	n->Data = data;

	if(in_before == false) 
	{
		n->Next = p->Next;
		n->Prev = p;
		p->Next = n;

		t = n->Next;

		if(t != NULL) 
		{
			t->Prev = n;

		}
	}
	else 
	{
		n->Next = p;
		n->Prev = p->Prev;

		if(n->Prev != NULL) 
		{
			n->Prev->Next = n;
		}
		p->Prev = n;
	}
}
/*
Function: deleteNode(T)
Author: John Barbonio
Date: 6/20/2020
Desc: This function deletes a specific node that fits the parameters passed to it
I: template
O: n/a
*/
template <class T>
void LinkedList<T>::deleteNode(T search) 
{
	Node<T>* p = this->Head;

	if(p->Data == search) 
	{
		Node<T>* deletePtr = p;
		p = p->Next;
		this->Head = p;
		this->Head->Prev = NULL;
		delete deletePtr;

		return;
	}

	while(p->Next->Data != search) 
	{
		p = p->Next;
		if(p->Data == search) 
		{
			Node<T>* deletePtr = p->Next;
			p->Next = p->Next->Next;
			delete deletePtr;
			return;
		}
		if(p->Next == NULL) 
		{
			throw LinkedListException("Warning in deleteNode: No such element found.");
			return;
		}

	}

	Node<T>* deletePtr = p->Next;
	p->Next = p->Next->Next;

	if(p->Next != NULL) 
	{
		Node<T>* t = p->Next;
		t->Prev = p;
	}
		
	delete deletePtr;
}
/*
Function: contains(T)
Author: John Barbonio
Date: 6/20/2020
Desc: This function returns a boolean if a Node in the LinkedList matches the passed parameter
I: template
O: n/a
*/
template <class T>
bool LinkedList<T>::contains(T search) 
{
	Node<T>* p = this->Head;

	while (p->Data != search)
	{
		if (p->Next == NULL)
		{
			throw LinkedListException("Warning in contains: no such element found.");
			return false;
		}
		p = p->Next;
	}
	return true;
}
/*
Function: linearSearch (probe)
Author: John Barbonio
Date: 7/10/2020
Desc: This function probes the LinkedList for the parameter being searched for (compares search this->Head->Data.name)
I: std::string
O: std::string
*/
template <class T>
std::string LinkedList<T>::linearSearch(std::string search)
{
	int count = 0;
	if(this->Head == NULL)
	{
		throw LinkedListException("Critical Error in LinkedList<T>::countInstance. Were your nodes not rechained properly after deletion?");
		return 0;
	}
	std::regex rgName("([A-Z]?[a-z]+)");
	std::smatch match;

	// goes to front of LinkedList
	while(this->Head->Prev != NULL)
	{
		this->Head = this->Head->Prev;
	}
	while(this->Head->Next != NULL) 
	{
		std::regex_search(this->Head->Data.name, match, rgName);
		if(match.str() == search) 
		{
			return std::to_string(this->Head->Data.position) + ") " + this->Head->Data.name + " " + this->Head->Data.number;
		}
		this->Head = this->Head->Next;
	}
	std::regex_search(this->Head->Data.name, match, rgName);
	if(match.str() == search)
	{
		return std::to_string(this->Head->Data.position) + ") " + this->Head->Data.name + " " + this->Head->Data.number;
	}

	throw LinkedListException("Error in LinkedList::linearSearch : search parameter not found");
}
/*
Function: isEmpty
Author: John Barbonio
Date: 6/20/2020
Desc: This function returns a boolean if the LinkedList is empty or not
I: n/a
O: bool
*/
template <class T>
bool LinkedList<T>::isEmpty() const
{
	if(this->Head == NULL) 
	{
		return true;
	}
	else
	{
		return false;
	}
}
/*
Function: getSize
Author: John Barbonio
Date: 6/20/2020
Desc: This function returns the current Head pointer's Log position variable, to keep track of the size and is used to set the position
for added Logs
I: std::string
O: std::string
*/
template <class T>
int LinkedList<T>::getSize() 
{
	int count = 0;

	if(this->Head == NULL) 
	{
		return 0;
	}
	while(this->Head->Next != NULL)
	{
		this->Head = this->Head->Next;
	}
	return this->Head->Data.position;
}
/*
Function: printList(void)
Author: John Barbonio
Date: 6/20/2020
Desc: This function prints all of the elements of the LinkedList, and their position within said linkedlist
I: n/a
O: n/a
*/
template <class T>
void LinkedList<T>::printList()
{
	if(this->isEmpty()) 
	{
		std::cout << "LinkedList is empty" << std::endl;
		return;
	}

	while(this->Head->Prev != NULL) 
	{
		this->Head = this->Head->Prev;
	}


	Node<T>* p = this->Head;

	while(p->Next != NULL) 
	{
		p = p->Next;
	}

	while (p->Prev != NULL)
	{
		std::cout << "LL Pos: " << p->Data.position << " | " << p->Data.name << " | " << p->Data.number << std::endl;
		p = p->Prev;
	}
	std::cout << "LL Pos: " << p->Data.position << " | " << p->Data.name << " | " << p->Data.number << std::endl;
}