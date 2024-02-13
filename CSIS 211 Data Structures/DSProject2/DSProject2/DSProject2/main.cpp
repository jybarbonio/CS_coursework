/*
main.cpp
John Barbonio
6/11/2020
: This is the main.cpp file where the program run time begins. 
*/
#include "PairList.h"

int main() 
{
// stage 1 Pair.h test
	/*
	Pair<int> score;
	Pair<char> seats;

	score.setFirst(3);
	score.setSecond(0);

	seats.setFirst('A');
	seats.setSecond('B');

	std::cout << seats.getFirst() << " | " << seats.getSecond() << std::endl;
	std::cout << score.getFirst() << " | " << score.getSecond() << std::endl;
	*/

// stage 2 PairList.h test
// int test
	PairList<int> i_list;
	Pair<int> i_p(1, 2);

	// i_list.addPair(i_p);
	i_list.addPair(1, 2);
	i_list.printList();

	auto i1 = i_list.getFirst(2);
	auto i2 = i_list.getSecond(1);
	std::cout << i1 << " | " << i2 << std::endl;

	// auto i3 = i_list.getFirst(33);	// does not exist
	// auto i4 = i_list.getSecond(241);	// does not exist

	i_list.deletePair(1, 2);
	i_list.printList();

// double test
	PairList<double> d_list;
	Pair<double> d_p(1.1, 2.2);

	// d_list.addPair(d_p);
	d_list.addPair(1.1, 2.2);
	d_list.printList();

	auto d1 = d_list.getFirst(2.2);
	auto d2 = d_list.getSecond(1.1);
	std::cout << d1 << " | " << d2 << std::endl;

	d_list.deletePair(1.1, 2.2);
	d_list.printList();

// char test
	PairList<char> c_list;
	Pair<char> c_p('a', 'b');

	// c_list.addPair(c_p);
	c_list.addPair('a', 'b');
	c_list.printList();

	auto c1 = c_list.getFirst('b');
	auto c2 = c_list.getSecond('a');
	std::cout << c1 << " | " << c2 << std::endl;

	c_list.deletePair('a', 'b');
	c_list.printList();

// std::string test
	PairList<std::string> s_list;
	Pair<std::string> s_p("a", "b");

	// s_list.addPair(s_p);
	s_list.addPair("a", "b");
	s_list.addPair("y", "z");
	s_list.addPair("a", "b");
	s_list.addPair("a", "b");

	s_list.printList();
	s_list.deletePair("a", "b");
	s_list.printList();
}