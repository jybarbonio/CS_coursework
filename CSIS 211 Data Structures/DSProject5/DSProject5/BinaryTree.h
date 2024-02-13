/*
AVLTree.h
John Barbonio
07/04/2020
: BinaryTree.h utilizes Nodes and is a basic data structure tree that has a Root, and values lesser than it to it's left, and those greater
than it to it's right. Parsing uses a "fanning out" from the Root of sorts.
*/

#pragma once

#include "Node.h"
#include "BinaryTreeException.h"

template <class T>
class BinaryTree : public Node<T>
{
protected:
	Node<T>* Root;

	void insert(T data, Node<T>*& n);
	void remove(T data, Node<T>*& n);
	Node<T>* findMin(Node<T>* root);
	Node<T>* findMax(Node<T>* root);
	bool contains(T data, Node<T>* n);
	void printTree(Node<T>* n) const;
public:
	BinaryTree();

	void insert(const T& data);					// insert(T data, Node<T>*& n) accessor
	void remove(const T& data);		// remove(T data, Node<T>*& n) accessor
	Node<T>* findMin();							// findMin(Node<T>* root) accessor
	Node<T>* findMax();							// findMax(Node<T>* root) accessor
	bool contains(T data);					// contains(T data, Node<T>* n) accessor

	bool isEmpty() const;
	void printTree() const;						// printTree
};
/*
Function: BinaryTree
Author: John Barbonio
Date: 07/04/2020
Desc: initializes a tree with an empty root
I: n/a
O: n/a
*/
template <class T>
BinaryTree<T>::BinaryTree() 
{
	this->Root = NULL;
}
/*
Function: insert
Author: John Barbonio
Date: 07/04/2020
Desc: accessor for insert function that takes this node parameter, adds a specified parameter to the node then the node to the tree
I: const T&
O: n/a
*/
/* Node<T>* &n points to the actual memory address to access and modify private variables, and ensure the right data is being accessed
- functions with by-reference pointer parameters should be hidden from the user. There is no need for them to tamper with these
*/
template <class T>
void BinaryTree<T>::insert(const T& data) 
{
	this->insert(data, this->Root);
}
/*
Function: remove
Author: John Barbonio
Date: 07/04/2020
Desc: accessor for remove function that takes this node parameter, removes node with specified parameter
I: const T&
O: n/a
*/
template <class T>
void BinaryTree<T>::remove(const T& data) 
{
	this->remove(data, this->Root);
}
/*
Function: findMin
Author: John Barbonio
Date: 07/04/2020
Desc: accessor for findMin, finds a min value from within the tree and returns a pointer to it
I: n/a
O: n/a
*/
template <class T>
Node<T>* BinaryTree<T>::findMin() 
{
	return this->findMin(this->Root);
}
/*
Function: findMax
Author: John Barbonio
Date: 07/04/2020
Desc: accessor for findMax, finds a max value from within the tree and returns a pointer to it
I: n/a
O: n/a
*/
template <class T>
Node<T>* BinaryTree<T>::findMax()
{
	return this->findMax(this->Root);
}
/*
Function: contains
Author: John Barbonio
Date: 07/04/2020
Desc: accessor for contains, which returns a bool if whether the passed parameter exists among the tree already
O: n/a
*/
template <class T>
bool BinaryTree<T>::contains(T data) 
{
	return this->contains(data, this->Root);
}
/*
Function: insert
Author: John Barbonio
Date: 07/04/2020
Desc: adds the parameter to a new Node which is then added to this tree (Root)
O: n/a
*/
template <class T>
void BinaryTree<T>::insert(T data, Node<T>* &n)
{
	if(n == NULL) 
	{
		n = new Node<T>;
		n->Data = data;
		n->Prev = NULL;
		n->Next = NULL;
	}
	else if(data < n->Data) 
	{
		this->insert(data, n->Prev);
	}
	else if(data > n->Data) 
	{
		this->insert(data, n->Next);
	}

	return;
}
/*
Function: remove
Author: John Barbonio
Date: 07/04/2020
Desc: using the passed data parameter, finds a node with data that matches it and deletes that node
I: T, Node<T>*&
O: n/a
*/
/*
- T data parameter is what is to be searched to be removed from the tree, also Visual Studio keeps formatting where I put my ampersands
*/
template <class T>
void BinaryTree<T>::remove(T data, Node<T>*& n)
{
	// theoretically, both the front and ends of the tree (LinkedList) should be flanked by NULL ground Node pointers
	if (this->Root == NULL)
	{
		throw BinaryTreeException("Binary Tree remove func: No such element exists in the tree to delete.");
		return;		// empty tree removes nothing as there is noting in the tree
	}

	if (data < n->Data)
	{
		this->remove(data, n->Prev);
	}
	else if (data > n->Data)
	{
		this->remove(data, n->Next);
	}
	else if(n->Prev != NULL && n->Next != NULL)
	{
		n->Data = this->findMin(n->Next)->Data;
		this->remove(n->Data, n->Next);
	}
	else 
	{
		Node<T>* oldNode = n;
		n = (n->Prev != NULL) ? n->Prev : n->Next;	// ternary: if previous Node is not NULL, n = n->Prev. Otherwise n = n->Next;
		delete oldNode;
	}
}
/*
Function: findMin
Author: John Barbonio
Date: 07/04/2020
Desc: returns a node pointing to the min sized value in the tree
I: Node<T>*
O: Node<T>*
*/
template <class T>
Node<T>* BinaryTree<T>::findMin(Node<T>* root)
{
	// sweeps tree back to front to find min value
	if (root->Prev == NULL) { return root; }
	else { return this->findMin(root->Prev); }
}
/*
Function: findMax
Author: John Barbonio
Date: 07/04/2020
Desc: returns a node pointing to the max sized value in the tree
I: Node<T>*
O: Node<T>*
*/
template <class T>
Node<T>* BinaryTree<T>::findMax(Node<T>* root)
{
	// sweeps tree forward to the "back" to find max value
	if (root->Next == NULL) { return root; }
	else { return this->findMax(root->Next); }
}
/*
Function: contains
Author: John Barbonio
Date: 07/04/2020
Desc: returns a bool on whether the passed data parameter already exists within a node in the tree
I: T, Node<T>*
O: bool
*/
template <class T>
bool BinaryTree<T>::contains(T data, Node<T>* n) 
{
	if (n == NULL) { return false; }
	else if (data < n->Data) { return this->contains(data, n->Prev); }
	else if (data > n->Data) { return this->contains(data, n->Next); }
	else { return true; }	// if the data parameter matches a Node->Data in the tree, yes the tree contains it then
}
/*
Function: isEmpty
Author: John Barbonio
Date: 07/04/2020
Desc: returns a bool on whether the tree is devoid of nodes or not
I: n/a
O: bool
*/
template <class T>
bool BinaryTree<T>::isEmpty() const
{
	// returns bool whether this is true or false that Root is NULL
	return this->Root == NULL;
}
/*
Function: printTree
Author: John Barbonio
Date: 07/04/2020
Desc: prints the tree via branch sweeping method starting from the smaller side ending on the larger-than-root other
I: Node<T>*
O: n/a
*/
template <class T>
void BinaryTree<T>::printTree(Node<T>* t) const
{
	if (t != NULL)
	{
		this->printTree(t->Prev);
		std::cout << t->Data << std::endl;
		this->printTree(t->Next);
	}
}
/*
Function: printTree
Author: John Barbonio
Date: 07/04/2020
Desc: accessor for printTree
I: n/a
O: n/a
*/
template <class T>
void BinaryTree<T>::printTree() const
{
	if (this->isEmpty())
	{
		throw BinaryTreeException("Error in printTree: Tree is empty.");
	}
	else
	{
		this->printTree(this->Root);
	}
}
