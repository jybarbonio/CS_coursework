/*
Queue.h
John Barbonio
7/23/2020
: This header file is a FIFO data structure derived from LinkedList with an ability to add Nodes to the end,
but elements are removed from the front
*/

#pragma once

#include "LinkedList.h"

const int MAXQUEUE = 10;
const int QFULL = MAXQUEUE;
const int QEMPTY = 0;
const int EMPTY = -1;

template <class T>
class Queue : protected LinkedList<T> 
{
private:
	int items[MAXQUEUE];
	int head;
	int tail;

	Node<T>* p_tail = new Node<T>;

public:
	Queue();

	bool isEmpty();
	bool isFull();

	bool enqueue(T data);
	void dequeue();
	T peek();
};
/*
Function: Queue constructor
Author: John Barbonio
Date: 6/27/2020
Desc: sets the head to an empty size and tail to an empty size
I: n/a
O: n/a
*/
template <class T>
Queue<T>::Queue() 
	: head(QEMPTY), tail(QEMPTY)
{
		
}
/*
Function: isEmpty
Author: John Barbonio
Date: 6/27/2020
Desc: returns a bool based on whether the queue is empty or not
I: n/a
O: bool
*/
template <class T>
bool Queue<T>::isEmpty() 
{
	return this->head == this->tail;
}
/*
Function: isFull
Author: John Barbonio
Date: 6/27/2020
Desc: returns a bool based on whether the queue is full or not
I: n/a
O: bool
*/
template <class T>
bool Queue<T>::isFull()
{
	if((this->tail + 1) % MAXQUEUE == this->head) 
	{
		return true;
	}
	else 
	{
		return false;;
	}
}
/*
Function: enqueue(T data)
Author: John Barbonio
Date: 6/27/2020
Desc: returns a bool based on whether the parameter is successfully added to the Queue
I: T template
O: bool
*/
template <class T>
bool Queue<T>::enqueue(T data) 
{
	if(this->isFull()) 
	{
		return false;
	}

	this->addToFront(data);

	Node<T>* n = new Node<T>;
	n->Data = data;
	
	this->p_tail->Next = n;
	n->Next = NULL;
	n->Prev = this->p_tail;
	this->p_tail = this->p_tail->Next;

	return true;
}
/*
Function: dequeue
Author: John Barbonio
Date: 6/27/2020
Desc: removes an element from the front of the Queue and rechains the Nodes, Head is moved to front
I: n/a
O: void
*/
template <class T>
void Queue<T>::dequeue() 
{
	/*
	if(this->isEmpty()) 
	{
		return EMPTY;
	}
	*/

	while(this->Head->Prev != NULL) 
	{
		this->Head = this->Head->Prev;
	}
	Node<T>* deletePtr = this->Head;
	Node<T>* r = deletePtr;
	this->Head = this->Head->Next;


	delete deletePtr;

	if(this->Head != NULL) 
	{
		this->Head->Prev = NULL;
	}
}
/*
Function: peek
Author: John Barbonio
Date: 6/27/2020
Desc: returns data at the top of the Queue
I: n/a
O: T template
*/
template <class T>
T Queue<T>::peek() 
{
	return this->Head->Data;
}