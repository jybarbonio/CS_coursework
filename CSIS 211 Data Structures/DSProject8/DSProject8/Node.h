/*
Node.h
John Barbonio
7/9/2020
: This header file provides the Node data type to be added and work with LinkedList.h, is of template type and thus modular, Next is a pointer
that points to the next element of the LinkedList. Data hold the data <template> of the Node. int count is used for counting instances.
*/

#pragma once

#include <iostream>
using std::iostream;

template <class T>
class Node
{
public:
	T Data;
	Node<T>* Next;
	Node<T>* Prev;

	int height;
	Node() {}
	Node(const T& data, Node<T>* pr, Node<T>* nx, int h = 0) : Data(data), Prev(pr), Next(nx), height(h) {}
};