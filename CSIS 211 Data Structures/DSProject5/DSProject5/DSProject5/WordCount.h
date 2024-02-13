/*
WordCount.h
John Barbonio
07/04/2020
: WordCount.h is an AVLTree derived, string-oriented class that parses a text file and creates a tally of instances of each word
*/

#pragma once

#include <exception>
using std::exception;
#include <regex>
using std::regex;
#include <iterator>
using std::iterator;
#include <fstream>
using std::fstream;
#include <thread>
#include <chrono>

#include "AVLTree.h"

class WordCount : public AVLTree<std::string> 
{
private:
	void printWordCount(Node<std::string>* t);
	Node<std::string>* gotoNode(std::string data, Node<std::string>* n);
public:
	WordCount() {}
	void loadFile();
	void printWordCount();
};
/*
Function: loadFile()
Author: John Barbonio
Date: 07/04/2020
Desc: this function opens the contents for a text file and parses it for unique words, if repeats are parsed, adds to the count within
each Node which also contains the existing word.
I: n/a
O: n/a
*/
void WordCount::loadFile()
{
	std::ifstream infile("WordCountTest.txt");
	std::string input;

	if(!infile) 
	{
		throw std::exception("Unable to open file for reading");
	}

	while(std::getline(infile, input)) 
	{
		std::regex rgLine("([^ '][A-Z]?[a-z]+)");

		auto words = std::sregex_iterator(input.begin(), input.end(), rgLine);
		auto words_end = std::sregex_iterator();

		for (std::sregex_iterator i = words; i != words_end; ++i)
		{
			std::smatch match = *i;
			std::string match_str = match.str();

			if(this->contains(match_str)) 
			{
				Node<std::string>* tmp = this->gotoNode(match_str, this->Root);
				tmp->count++;
			}
			else 
			{
				this->insert(match_str);
				this->gotoNode(match_str, this->Root)->count++;
			}
		}
	}
	infile.close();
}
/*
Function: printWordCount()
Author: John Barbonio
Date: 07/04/2020
Desc: accessor and if-empty tree exception catcher for printWordCount, which prints out the elements of the tree and the count
of each word
I: n/a
O: n/a
*/
void WordCount::printWordCount() 
{
	if (this->isEmpty())
	{
		throw BinaryTreeException("Error in printWordCount: Tree is empty.");
	}
	else
	{
		this->printWordCount(this->Root);
	}
}
/*
Function: printWordCount(Node<std::string>* t)
Author: John Barbonio
Date: 07/04/2020
Desc: parses the tree not unlike the contains function and prints all Nodes, the word contained within them, and the instances
in which they appear in the file.
I: Node<std::string>* t
O: n/a
*/
void WordCount::printWordCount(Node<std::string>* t) 
{
	if (t != NULL)
	{
		this->printWordCount(t->Prev);
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		std::cout << "[ " << t->Data << " : " << t->count << " ]\n";
		this->printWordCount(t->Next);
	}
}
/*
Function: gotoNode(std::string data, Node<std::string>* t)
Author: John Barbonio
Date: 07/04/2020
Desc: returns a pointer pointing to the Node with the already existing word encountered and adds 1 to its count
O: n/a
*/
Node<std::string>* WordCount::gotoNode(std::string data, Node<std::string>* n)
{
	if (n == NULL) { return NULL; }
	else if (data < n->Data) { return this->gotoNode(data, n->Prev); }
	else if (data > n->Data) { return this->gotoNode(data, n->Next); }
	else { return n; }	// if the data parameter matches a Node->Data in the tree, yes return the node at the correct location
}