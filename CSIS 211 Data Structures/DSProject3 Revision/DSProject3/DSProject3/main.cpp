/*
Function: insert(T, T)
Author: John Barbonio (edited based on code from Unit 8 Discussion)
Date: 6/20/2020
Desc: This function inserts a node at a specified position in the linked List
I: template, template
O: n/a
*/

#include "PairList.h"

int main() 
{
// Stage 1, LinkedList test
	LinkedList<std::string> list;

	list.addToEnd("Hello");
	list.addToEnd("Now");
	list.addToEnd("Goodbye");

	list.insert("Now", "*HEY* (LL insertion)");
	list.insert("Soz", "*HEY* (LL insertion)");

	list.printList();

	std::cout << "Does this LinkedList contain " << list.contains("Hello") << std::endl;
	std::cout << "Does this LinkedList contain " << list.contains("Sup") << std::endl;

	list.deleteNode("*HEY* (LL insertion)");
	list.printList();

// stage 2 PairList.h new test with LinkedList
	// int test
	PairList<int> i_list;
	Pair<int> i_p(1, 2);

	// i_list.addPair(i_p);
	i_list.addPair(1, 2);
	i_list.addPair(2, 4);
	i_list.addPair(3, 6);
	i_list.addPair(222, 123);
	i_list.printList();

	auto i1 = i_list.getFirst(2);
	auto i2 = i_list.getSecond(1);
	std::cout << "get " << i1 << " and " << i2 << std::endl;

	// auto i3 = i_list.getFirst(33);	// does not exist
	// auto i4 = i_list.getSecond(241);	// does not exist


	i_list.printList();
	i_list.deletePair(2, 4);
	i_list.deletePair(1, 2);
	i_list.deletePair(222, 123);
	i_list.deletePair(77, 889);	// results in nothing
	i_list.printList();
}