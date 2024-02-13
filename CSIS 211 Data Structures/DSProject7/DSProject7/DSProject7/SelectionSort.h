/*
SelectionSort.h
John Barbonio
7/16/2020
: this algorithm pans through a list to find the smallest number and swaps with the pointer that is against
the wall of those already sorted 
*/

#pragma once

struct SelectionSort
{
private:
	long it;
public:
	SelectionSort() { this->it = 0; }
	SelectionSort(double list[], int last) { this->it = 0; this->selectionSort(list, last); }

	void fillArray(double* p, int size);
	void selectionSort(double list[], int last);
	long getIterations();
};
