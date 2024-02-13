/*
main.cpp
John Barbonio
07/04/2020
: This is main where BinaryTree.h and its derivative classes are tested for their compatibility to do assigned operations,
and this main.cpp tests the functionality of the Trees.
*/
#include "PairList.h"
#include "LinkedList.h"
#include "WordCount.h"
#include "AVLTree.h"
#include "BinaryTree.h"

#include "Stack.h"
#include "Queue.h"

#include "RPN.h"
#include "InfixNotation.h"

int main() 
{
// [ STAGE 1: BinaryTree.h test ]

/*
	try
	{
		BinaryTree<int> TREE;
		TREE.insert(2);
		TREE.printTree();

		//TREE.remove(1);		// !exception test by attempt to del a non-existent param, testing Tree LL sweep towards front/Root (Prev "left")
		//TREE.remove(7);		// !exception test by attempt to del a non-existent param, testing Tree LL sweep towards rear/leaf (Next "right")

		TREE.remove(2);
		// TREE.printTree(); // causes an exception throw, Note to self add a throw error if there is nothing to print

		TREE.insert(5);
		bool test1 = TREE.contains(4);
		bool test2 = TREE.contains(5);
		std::cout << "Contains 4?: " << test1 << std::endl;
		std::cout << "Contains 5?: " << test2 << std::endl;

		TREE.insert(4);
		Node<int>* mtest1 = TREE.findMin();
		std::cout << "Min: " << mtest1->Data << std::endl;

		Node<int>* mtest2 = TREE.findMax();
		std::cout << "Max: " << mtest2->Data << std::endl;


		TREE.insert(7);
		TREE.insert(1);
		Node<int>* mtest3 = TREE.findMin();
		std::cout << "Min: " << mtest3->Data << std::endl;

		Node<int>* mtest4 = TREE.findMax();
		std::cout << "Max: " << mtest4->Data << std::endl;

		bool etest1 = TREE.isEmpty();
		std::cout << "Is empty?: " << etest1 << std::endl;

		TREE.printTree();
		TREE.remove(5);
		TREE.remove(4);
		TREE.remove(1);
		TREE.remove(7);

		bool etest2 = TREE.isEmpty();
		std::cout << "Is empty?: " << etest2 << std::endl;
	}
	catch(BinaryTreeException bte) 
	{
		std::cout << bte.query() << std::endl;
	}
*/

// [ STAGE 2: AVLTree.h test ]
/*
	try
	{
		AVLTree<int> avl(-1);
		avl.insert(23);
		avl.insert(18);
		avl.insert(44);
		avl.insert(6);
		avl.insert(12);
		avl.insert(52);
		avl.insert(14);
		avl.insert(8);

		avl.printTree();
		std::cout << "Post-Removal" << std::endl;

		avl.remove(6);
		avl.printTree();

		avl.makeEmpty();	// clears tree
		//avl.printTree();	// <-- exception test: thrown because tree is empty

		AVLTree<std::string> s_avl("a");
		s_avl.insert("d");
		s_avl.insert("f");
		s_avl.insert("q");
		s_avl.insert("a");
		s_avl.insert("k");
		s_avl.insert("b");

		s_avl.printTree();
		std::cout << "After Remove" << std::endl;

		s_avl.remove("f");
		s_avl.printTree();

	}
	catch(BinaryTreeException bte) 
	{
		std::cout << bte.query() << std::endl;
	}
*/

// [ STAGE 3: WordCount.h test ]
/*
	try 
	{
		WordCount w;
		w.loadFile();
		w.printTree();
		w.printWordCount();

		std::cout << w.contains("to") << std::endl;
	}
	catch(BinaryTreeException bte) 
	{
		std::cout << bte.query() << std::endl;
	}
*/
}