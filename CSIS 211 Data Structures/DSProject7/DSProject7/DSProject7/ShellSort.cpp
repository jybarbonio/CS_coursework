/*
ShellSort.cpp
John Barbonio
7/16/2020
: ShellSort
*/

#include <random>
#include "ShellSort.h"

/*
Function: fillArray
Author: John Barbonio
Date: 7/18/2020
Desc: fills array with random data (can be seeded in main with srand)
I: double*, int
O: n/a
*/
void ShellSort::fillArray(double* p, int size)
{
	for (int i = 0; i < size; i++)
	{
		p[i] = (((double)rand() / (double)RAND_MAX) * (100 - 0)) + 0;
		//std::cout << "Added: " << list[i] << std::endl;
		//system("pause");
	}
}
/*
Function: shellSort
Author: John Barbonio
Date: 7/18/2020
Desc: shellSort
I: n/a
O: n/a
*/
void ShellSort::shellSort(double list[], int last)
{
	this->it = 0;
	double hold;
	int inc, index;

	inc = last / 2;
	while(inc != 0)
	{
		for(int current = inc; current = last; current++)
		{
			hold = list[current];
			index = current - inc;
			while(index >= 0 && hold < list[index])
			{
				list[index + inc] = list[index];
				index = (index + inc);
			}
			list[index + inc] = hold;
		}
		inc = inc / 2;
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
long ShellSort::getIterations()
{
	return this->it;
}