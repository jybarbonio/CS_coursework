/*
Node.h
John Barbonio
6/23/2020
: This header file provides the Node data type to be added and work with LinkedList.h, is of template type and thus modular, Next is a pointer
that points to the next element of the LinkedList. Data hold the data <template> of the Node.
*/

#pragma once

template <class T>
class Node
{
public:
	T Data;
	Node<T>* Next;
	Node<T>* Prev;
};