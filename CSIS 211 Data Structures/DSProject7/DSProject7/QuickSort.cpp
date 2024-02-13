/*
ShellSort.cpp
John Barbonio
7/16/2020
: QuickSort
*/

#include <random>
#include "QuickSort.h"

/*
Function: fillArray
Author: John Barbonio
Date: 7/18/2020
Desc: fills array with random data (can be seeded in main with srand)
I: double*, int
O: n/a
*/
void QuickSort::fillArray(double* p, int size)
{
	for (int i = 0; i < size; i++)
	{
		p[i] = (((double)rand() / (double)RAND_MAX) * (100 - 0)) + 0;
		//std::cout << "Added: " << list[i] << std::endl;
		//system("pause");
	}
}
/*
Function: quickSort
Author: John Barbonio
Date: 7/18/2020
Desc: quickSort
I: list[], int, int
O: n/a
*/
void QuickSort::quickSort(double list[], int m, int n)
{
	double key;
	int i, j, k;

	if(m < n)
	{
		k = this->choosePivot(m, n);

		double t = list[m];
		list[m] = list[k];
		list[k] = t;

		key = list[m];
		i = m + 1;
		j = n;

		while(i <= j)
		{
			while((i <= n) && (list[i] <= key))
			{
				i++;
			}
			while((j >= m) && (list[j] <= key))
			{
				j--;
			}
			if(i < j)
			{
				double t = list[i];
				list[i] = list[j];
				list[j] = t;
			}
		}
		double t2 = list[m];
		list[m] = list[j];
		list[j] = t2;

		this->quickSort(list, m, j - 1);
		this->quickSort(list, j + 1, n);
		this->it++;
	}
	return;
}
int QuickSort::choosePivot(double i, double j)
{
	return static_cast<int>((i + j) / 2);
}
/*
Function: getIterations
Author: John Barbonio
Date: 7/18/2020
Desc: gets the iterations from the insertion sort loop
I: n/a
O: long
*/
long QuickSort::getIterations()
{
	return this->it;
}
/*
Function: resetIt
Author: John Barbonio
Date: 7/18/2020
Desc: resets iteration counter
I: n/a
O: n/a
*/
void QuickSort::resetIt()
{
	this->it = 0;
}