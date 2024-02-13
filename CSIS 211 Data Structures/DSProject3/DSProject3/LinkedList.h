/*
LinkedList.h
John Barbonio
6/20/2020
: This header file is the provides a LinkedList structure and its expected functions. It is designed to be data-type agnostic and PairList utilizes it
to store Pairs
*/

#pragma once

#include "Node.h"
#include "PairList.h"
#include <iostream>
#include <string>

using std::string;
using std::iostream;

template <class T>
class LinkedList 
{
protected:
	Node<T>* Head = NULL;
public:
	void addToEnd(T data);
	void insert(T search, T data);
	void deleteNode(T search);
	bool contains(T search);

	void printList();
};
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
void LinkedList<T>::insert(T search, T data) 
{
	// parses LinkedList looking for corresponding data section that matches parameter "search"
	Node<T>* p = this->Head;

	while (p->Data != search) 
	{
		p = p->Next;

		if(p->Next == NULL) 
		{
			Node<T>* n = new Node<T>;

			std::cout << "No Nodes match that parameter. Template type garbage returned." << std::endl;
			n->Data = T();

			n->Next = p->Next;
			p->Next = n;
			return;
		}
	}

	Node<T>* n = new Node<T>;
	n->Data = data;

	n->Next = p->Next;
	p->Next = n;
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
	while(p->Next->Data != search)
	{
		p = p->Next;
		if (p->Next == NULL)
		{
			std::cout << "Could not find Node that matches the specified parameter" << std::endl;
			return;
		}
	}

	Node<T>* deletePtr = p->Next; // moves pointer at what is to be deleted
	p->Next = p->Next->Next;	// connects the Node pointer to the Next Node after the what it currently points to is deleted

	delete deletePtr;
}
template <class T>
void LinkedList<T>::printList() 
{
	Node<T>* p = this->Head;
	while(p != NULL) 
	{
		std::cout << p->Data << std::endl;
		p = p->Next;
	}
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
	Node<T>* temp = this->Head;

	while(temp != NULL) 
	{
		if(temp->Data == search) 
		{
			return true;
		}
		else 
		{
			std::cout << "contains does not match" << std::endl;
			return false;
		}
	}
	return false;
}