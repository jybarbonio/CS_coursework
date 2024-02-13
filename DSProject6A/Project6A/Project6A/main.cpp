
#include "HashTable.h"

int main() 
{
	try 
	{
		HashTable ht;
		ht.loadFile();
		ht.printTable();

		ht.search();
	}
	catch(LinkedListException lle) 
	{
		std::cout << lle.query() << std::endl;
	}
}