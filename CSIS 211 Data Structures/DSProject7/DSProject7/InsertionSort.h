/*
InsertionSort.h
John Barbonio
7/16/2020
: this algorithm provides the worst case efficiency and sorts by comparing and swapping two values, going up the list
*/

#pragma once

struct InsertionSort 
{
private:
	long it;
public:
	InsertionSort() { this->it = 0; }
	InsertionSort(double list[], double last) { this->it = 0; this->insertionSort(list, last); }
	
	void fillArray(double* p, int size);
	void insertionSort(double list[], double last);
	long getIterations();
	
};
