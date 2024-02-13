/*
SelectionSort.cpp
John Barbonio
7/16/2020
: SelectionSort
*/

#include <random>

#include "SelectionSort.h"

/*
Function: fillArray
Author: John Barbonio
Date: 7/18/2020
Desc: fills array with random data (can be seeded in main with srand)
I: double*, int
O: n/a
*/
void SelectionSort::fillArray(double* p, int size)
{
	for (int i = 0; i < size; i++)
	{
		p[i] = (((double)rand() / (double)RAND_MAX) * (100 - 0)) + 0;
		//std::cout << "Added: " << list[i] << std::endl;
		//system("pause");
	}
}
/*
Function: selectionSort
Author: John Barbonio
Date: 7/18/2020
Desc: selection sort algorithm
I: double[], int
O: n/a
*/
void SelectionSort::selectionSort(double list[], int last)
{
	this->it = 0;

	int low = 0;
	double hold = 0;

	for(int current = 0; current < last; current++)
	{
		low = current;
		for(int index = current + 1; index <= last; index++)
		{
			if(list[index] < list[low])
			{
				low = index;
			}
		}
		hold = list[current];
		list[current] = list[low];
		list[low] = hold;
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
long SelectionSort::getIterations()
{
	return this->it;
}