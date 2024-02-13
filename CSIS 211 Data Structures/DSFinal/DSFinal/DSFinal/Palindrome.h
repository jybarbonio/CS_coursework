/*
Palindrome.h
John Barbonio
7/23/2020
: This header file's task is to read a text file for words, and test each word whether it is a palindrome or not,
tests by checking whether they are odd or even length, then compares two string of each half, or in the case
of odd, checks if each half equals each other and excludes the middle char.
*/

#pragma once

#include <iostream>
using std::iostream;
#include <fstream>
using std::fstream;

#include "LinkedListException.h"

struct Palindrome
{
private:
	bool isPalindrome;
public:
	void loadFile();
};
void Palindrome::loadFile()
{
	std::ifstream infile("words.txt");
	std::string in;

	if (!infile)
	{
		throw LinkedListException("Palindrome::loadFile : unable to load file for reading.");
	}
	while (std::getline(infile, in))
	{
		if(in.length() % 2 == 0)
		{
			std::string cmp1;
			std::string cmp2;

			for(unsigned int i = 0; i < in.length() / 2; i++)
			{
				cmp1 += std::tolower(in[i]);
				std::cout << cmp1 << std::endl;
			}
			for(unsigned int i = in.length() - 1; i > (in.length() / 2) - 1; i--)
			{
				cmp2 += std::tolower(in[i]);
				std::cout << cmp2 << std::endl;
			}
			if(cmp1 == cmp2)
			{
				this->isPalindrome = true;
			}
			else 
			{
				this->isPalindrome = false;
			}
		}
		else if(in.length() % 2 == 1)
		{
			std::string cmp1;
			std::string cmp2;

			for (unsigned int i = 0; i < in.length() / 2; i++)
			{
				cmp1 += std::tolower(in[i]);
				std::cout << cmp1 << std::endl;
			}
			for (unsigned int i = in.length() - 1; i > (in.length() / 2) - 1; i--)
			{
				cmp2 += std::tolower(in[i]);
				std::cout << cmp2 << std::endl;
			}
			if (cmp1 == cmp2)
			{
				this->isPalindrome = true;
			}
			else
			{
				this->isPalindrome = false;
			}
		}

		// regex not working correctly
		//this->addHash(this->hash(&name[0], this->TABLE_SIZE), name, number);
	}
	infile.close();
}
