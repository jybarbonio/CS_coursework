/*
InsertionSort.cpp
John Barbonio
7/16/2020
: Insertion Sort
*/

#include <random>
#include "InsertionSort.h"

/*
Function: fillArray
Author: John Barbonio
Date: 7/18/2020
Desc: fills array with random data (can be seeded in main but is commented out)
I: double*, int
O: n/a
*/
void InsertionSort::fillArray(double* p, int size)
{
	for (int i = 0; i < size; i++)
	{
		p[i] = (((double)rand() / (double)RAND_MAX) * (100 - 0)) + 0;
		//std::cout << "Added: " << list[i] << std::endl;
		//system("pause");
	}
}
/*
Function: insertionSort
Author: John Barbonio
Date: 7/18/2020
Desc: insertion sort algorithm
I: double[], double
O: n/a
*/
void InsertionSort::insertionSort(double list[], double last)
{
	this->it = 0;

	double hold = 0;
	int search = 0;

	for(int current = 1; current <= last; current++)
	{
		hold = list[current];

		for(search = current - 1; search >= 0 && hold < list[search]; search--)
		{
			list[search + 1] = list[search];
		}
		list[search + 1] = hold;
		this->it++;
	}
	return;
}
/*
Function: getIterations
Author: John Barbonio
Date: 7/18/2020
Desc: gets the iterations from the insertion sort loop
I: n/a
O: n/a
*/
long InsertionSort::getIterations()
{
	return this->it;
}