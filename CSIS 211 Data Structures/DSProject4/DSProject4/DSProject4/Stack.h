/*
Stack.h
John Barbonio
6/27/2020
: This header file derives from LinkedList and is a LIFO data structure with an ability to push, pop, and peek data
to store Pairs
*/

#pragma once

#include "Node.h"
#include "LinkedList.h"


template <class T>
class Stack : public LinkedList<T>
{
private:
	Node<T>* top = this->Head;
public:
	Stack();
	bool empty();
	bool full();

	void push(T element);
	T pop();
	T peek();
};
/*
Function: Stack constructor
Author: John Barbonio
Date: 6/27/2020
Desc: this constructor sets the top Node to NULL
I: n/a
O: n/a
*/
template <class T>
Stack<T>::Stack()
	: top(NULL)
{
}
/*
Function: empty
Author: John Barbonio
Date: 6/27/2020
Desc: this function checks if the stack is either full or empty and returns a corresponding bool
I: n/a
O: bool
*/
template <class T>
bool Stack<T>::empty() 
{
	return this->top == NULL ? true : false;
}
/*
Function: full
Author: John Barbonio
Date: 6/27/2020
Desc: this function checks if the stack is either full or empty and returns a corresponding bool
I: n/a
O: bool
*/
template <class T>
bool Stack<T>::full()
{
	return this->top != NULL ? true : false;

}
/*
Function: push
Author: John Barbonio
Date: 6/27/2020
Desc: this function adds an element to the end/top of the stack/underlying linked list and rechains the Nodes
I: T template
O: n/a
*/
template <class T>
void Stack<T>::push(T element)
{
	this->addToEnd(element);

	while(this->Head->Next != NULL) 
	{
		this->Head = this->Head->Next;
	}
	this->top = this->Head;
	// "pointer to keep track of the top?"
}
/*
Function: pop
Author: John Barbonio
Date: 6/27/2020
Desc: this function removes an element at the top of the stack and returns the removed element back
I: n/a
O: T template
*/
template <class T>
T Stack<T>::pop()
{
	if(this->Head != NULL) 
	{
		Node<T>* deletePtr = this->top;
		this->top = this->top->Prev;
		this->Head = this->Head->Prev;

		T temp = deletePtr->Data;

		delete deletePtr;

		if(this->Head == NULL) 
		{
			if(temp != T()) 
			{
				return temp;
			}
			else 
			{
				//throw LinkedListException("Warning: Stack is empty.");
				return T();
			}
		}
		else 
		{
			this->top->Next = NULL;
			return temp;
		}
	}
	else 
	{
		throw LinkedListException("Warning: Stack is empty or you have hit the end.");
		return T();
	}
}
/*
Function: peek
Author: John Barbonio
Date: 6/27/2020
Desc: this function looks at an element at the end of the stack and returns a copy, without modifying the original
I: n/a
O: n/a
*/
template <class T>
T Stack<T>::peek() 
{
	this->top = this->Head;

	if (this->top == NULL)
	{
		std::cout << "Stack is empty" << std::endl;
		throw LinkedListException("Warning: Stack is empty.");
		return T();
	}
	else 
	{
		while (this->top->Next != NULL)
		{
			this->top = this->top->Next;
		}
		return this->top->Data;
	}
}