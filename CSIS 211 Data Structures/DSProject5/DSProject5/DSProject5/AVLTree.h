/*
AVLTree.h
John Barbonio
07/04/2020
: AVLTree.h is derived from BinaryTree and utilizes some of its functionality (I couldn't figure out how to utilize the base remove and insert
classes for it). It utilizes a concept of tree balancing as a specific efficient form of data structure to be parsed more effectively. It is
template based and organizes based off of data size.
*/

#pragma once

#include "BinaryTree.h"

template <class T>
class AVLTree : public BinaryTree<T>
{
private:
	const T ITEM_NOT_FOUND;
	const T& dataAt(Node<T>* rt) const;

	void insert(const T& x, Node<T>*& root) const;
	void remove(T x, Node<T>*& root);
	void makeEmpty(Node<T>*& t) const;

	Node<T>* find(const T& x, Node<T>* t) const;
	Node<T>* clone(Node<T>* t) const;

	// tree organization manipulations
	int height(Node<T>* root) const;
	int max(int lhs, int rhs) const;
	void rotateWithLeftChild(Node<T>*& root) const;
	void rotateWithRightChild(Node<T>*& root) const;
	void doubleWithLeftChild(Node<T>*& root) const;
	void doubleWithRightChild(Node<T>*& root) const;
public:
	explicit AVLTree(const T& notFound);
	AVLTree() {}
	AVLTree(const AVLTree& rhs);
	~AVLTree();	// destructor frees memory

	void insert(const T& x);	// there's a way to remove these and only use the base class accessors that I can't figure out how to get working
	void remove(const T& x);	// there's a way to remove these and only use the base class accessors that I can't figure out how to get working
	void makeEmpty();	// clears tree

	const T& find(const T& x) const;

	const AVLTree<T>& operator = (const AVLTree<T>& rhs);
};
/*
Function: AVLTree(T&)
Author: John Barbonio
Date: 07/04/2020
Desc: constructor that sets an item not found variable and initializes an empty avltree
I: const T&
O: n/a
*/
template <class T>
AVLTree<T>::AVLTree(const T& notFound)
	: ITEM_NOT_FOUND(notFound)
{
	this->Root = NULL;
}
/*
Function: AVLTree(AVLTree&)
Author: John Barbonio
Date: 07/04/2020
Desc: constructor that copies over another avltree and its item not found variable
I: AVLTree&
O: n/a
*/
template <class T>
AVLTree<T>::AVLTree(const AVLTree &rhs)
{
	this->ITEM_NOT_FOUND = rhs.ITEM_NOT_FOUND;
	this->Root = NULL;
	*this = rhs;
}
/*
Function: ~AVLTree()
Author: John Barbonio
Date: 07/04/2020
Desc: destructor frees memory used by instances after use
I: n/a
O: n/a
*/
template <class T>
AVLTree<T>::~AVLTree() 
{
	this->makeEmpty();
}
/*
Function: insert
Author: John Barbonio
Date: 07/04/2020
Desc: accessor to the insert function w/ node parameter that adds to the tree
I: const T&
O: n/a
*/
template <class T>
void AVLTree<T>::insert(const T& x) 
{
	this->insert(x, this->Root);
}
/*
Function: remove
Author: John Barbonio
Date: 07/04/2020
Desc: accessor to the remove function w/ Node parameter that removes Nodes from the tree
I: const &T
O: n/a
*/
template <class T>
void AVLTree<T>::remove(const T& x) 
{
	this->remove(x, this->Root);
}
/*
Function: makeEmpty
Author: John Barbonio
Date: 07/04/2020
Desc: accessor to the makeEmpty function that takes a Node parameter, and clears the tree of all members
I: n/a
O: n/a
*/
template <class T>
void AVLTree<T>::makeEmpty()
{
	this->makeEmpty(this->Root);
}
/*
Function: find
Author: John Barbonio
Date: 07/04/2020
Desc: accessor to the find function that takes a data parameter and a Node, returning the Data of specified Node
I: const T&
O: T& data
*/
template <class T>
const T& AVLTree<T>::find(const T& x) const 
{
	return this->dataAt(this->find(x, this->Root));
}
/*
Function: = operator overlead
Author: John Barbonio
Date: 07/04/2020
Desc: overloads equals operator to allow trees to be copied to instances of each other. in turn clearing the receiving node
and calling the clone function
I: AVLTree<T>&
O: AVLTree<T>*
*/
template <class T>
const AVLTree<T>& AVLTree<T>::operator = (const AVLTree<T>& rhs)
{
	if(this != &rhs) 
	{
		this->makeEmpty();
		this->Root = this->clone(rhs.root);
	}
	return *this;
}
/*
Function: dataAt
Author: John Barbonio
Date: 07/04/2020
Desc: returns the data section of specified node (internal use, not called by user), if data isn't found it returns item not found
I: AVLTree<T>&
O: const T
*/
template <class T>
const T& AVLTree<T>::dataAt(Node<T>* rt) const 
{
	if(rt == NULL) 
	{
		return ITEM_NOT_FOUND;
	}
	else 
	{
		return rt->Data;
	}
}
/*
Function: insert
Author: John Barbonio
Date: 07/04/2020
Desc: adds to the avltree specified data
I: const T&, Node<T>*&
O: n/a
*/
template <class T>
void AVLTree<T>::insert(const T& x, Node<T>* &root) const
{
	if(root == NULL) 
	{
		root = new Node<T>(x, NULL, NULL);
	}
	else if(x < root->Data) 
	{
		this->insert(x, root->Prev);
		if(height(root->Prev) - height(root->Next) == 2) 
		{
			if(x < root->Prev->Data) 
			{
				this->rotateWithLeftChild(root);
			}
			else 
			{
				this->doubleWithLeftChild(root);
			}
		}
	}
	else if(root->Data < x) 
	{
		this->insert(x, root->Next);
		if(height(root->Next) - height(root->Prev) == 2) 
		{
			if(root->Next->Data < x) 
			{
				rotateWithRightChild(root);
			}
		}
	}
	root->height = max(height(root->Prev), height(root->Next)) + 1;
}
/*
Function: remove
Author: John Barbonio
Date: 07/04/2020
Desc: removes from the avltree a specified data paramter
I: const T&, Node<T>*&
O: n/a
*/
template <class T>
void AVLTree<T>::remove(T x, Node<T>*& root) 
{
	if(root == NULL) 
	{
		return;
	}
	else if(x < root->Data) 
	{
		this->remove(x, root->Prev);
		if(height(root->Next) - height(root->Prev) > 1) 
		{
			if(height(root->Next->Next) >= height(root->Next->Prev)) 
			{
				this->rotateWithRightChild(root);
			}
			else
			{
				this->doubleWithRightChild(root);
			}
		}
	}
	else if(x > root->Data) 
	{
		this->remove(x, root->Next);
		if(height(root->Prev) - height(root->Next) > 1) 
		{
			if(height(root->Prev->Prev) + height(root->Prev->Next)) 
			{
				this->rotateWithLeftChild(root);
			}
			else 
			{
				this->doubleWithLeftChild(root);
			}
		}
	}
	else	// key is same as root key, thus is removed
	{
		// empty or only populated by 1 Node
		if(root->Prev == NULL || root->Next == NULL) 
		{
			Node<T>* temp = root->Prev ? root->Prev : root->Next;
			
			if(temp == NULL) 
			{
				temp = root;
				root = NULL;
			}
			else 
			{
				*root = *temp;
			}
			delete temp;
		}
		else 
		{
			Node<T>* temp;
			temp = this->findMin(root->Next);
			root->Data = temp->Data;
			this->remove(temp->Data, root->Next);
		}
		if(root != NULL) 
		{
			root->height = max(height(root->Prev), height(root->Next)) + 1;
		}
	}
}
/*
Function: makeEmpty
Author: John Barbonio
Date: 07/04/2020
Desc: empties the AVLTree
I: Node<T>*&
O: n/a
*/
template <class T>
void AVLTree<T>::makeEmpty(Node<T>*& t) const
{
	if (t != NULL)
	{
		this->makeEmpty(t->Prev);
		this->makeEmpty(t->Next);
		delete t;
	}
	t = NULL;
}
/*
Function: find
Author: John Barbonio
Date: 07/04/2020
Desc: returns a pointer to the node that carries the specified parameter being looked for
I: t&, Node<T>*&
O: n/a
*/
template <class T>
Node<T>* AVLTree<T>::find(const T &x, Node<T>* t) const 
{
	while(t != NULL) 
	{
		if(x < t->Data) 
		{
			t = t->Prev;
		}
		else if(t->Data < x) 
		{
			t = t->Next;
		}
		else 
		{
			return t;
		}
	}
	return NULL;
}
/*
Function: clone
Author: John Barbonio
Date: 07/04/2020
Desc: copies a node and returns a new Node (the copy) of the Node passed to it
I: Node<T>*
O: Node<T>*
*/
template <class T>
Node<T>* AVLTree<T>::clone(Node<T>* t) const
{
	if(t == NULL) 
	{
		return NULL;
	}
	else 
	{
		return new Node<T>(t->Data, this->clone(t->Prev), this->clone(t->Next), t->height);
	}
}
/*
Function: height
Author: John Barbonio
Date: 07/04/2020
Desc: verifies the height of one side is within 1 height as the opposite tree, maintaining tree balance and efficiency of the
data structure
I: Node<T>*
O: int
*/
template <class T>
int AVLTree<T>::height(Node<T>* root) const
{
	return root == NULL ? -1 : root->height;
}
/*
Function: max
Author: John Barbonio
Date: 07/04/2020
Desc: reports the height of each side and returns a value determining which side is to be rebalanced
I: int, int
O: int
*/
template <class T>
int AVLTree<T>::max(int lhs, int rhs) const 
{
	return lhs > rhs ? lhs : rhs;
}
/*
Function: rotateWithLeftChild
Author: John Barbonio
Date: 07/04/2020
Desc: rotates to the right a root and its left child from the left, and readjusts the height report
I: Node<T>*&
O: n/a
*/
template <class T>
void AVLTree<T>::rotateWithLeftChild(Node<T>*& root) const
{
	Node<T>* p;

	p = root->Prev;
	root->Prev = p->Next;
	p->Next = root;
	root->height = max(height(root->Prev), height(root->Next)) + 1;
	p->height = max(height(p->Prev), height(root->Next)) + 1;

	root = p;
}
/*
Function: rotateWithRightChild
Author: John Barbonio
Date: 07/04/2020
Desc: rotates to the left a root and its right child from the right, and readjusts the height report
I: Node<T>*&
O: n/a
*/
template <class T>
void AVLTree<T>::rotateWithRightChild(Node<T>*& root) const
{
	Node<T>* p;

	p = root->Next;
	root->Next = p->Prev;
	p->Prev = root;
	root->height = max(height(root->Prev), height(root->Next)) + 1;
	p->height = max(height(p->Next), root->height) + 1;

	root = p;
}
/*
Function: rotateWithLeftChild
Author: John Barbonio
Date: 07/04/2020
Desc: double rotates to the right a root and its left child from the left, and readjusts the height report
I: Node<T>*&
O: n/a
*/
template <class T>
void AVLTree<T>::doubleWithLeftChild(Node<T>* &root) const
{
	rotateWithRightChild(root->Prev);
	rotateWithLeftChild(root);
}
/*
Function: rotateWithRightChild
Author: John Barbonio
Date: 07/04/2020
Desc: double rotates to the left a root and its right child from the right, and readjusts the height report
I: Node<T>*&
O: n/a
*/
template <class T>
void AVLTree<T>::doubleWithRightChild(Node<T>*& root) const
{
	rotateWithLeftChild(root->Next);
	rotateWithRightChild(root);
}