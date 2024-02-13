/*
ShellSort.cpp
John Barbonio
7/16/2020
: ShellSort
*/

#pragma once

struct ShellSort
{
private:
	long it;

public:
	ShellSort() { this->it = 0; }
	ShellSort(double list[], int last) { this->it = 0; this->shellSort(list, last); }

	void fillArray(double* p, int size);
	void shellSort(double list[], int last);
	long getIterations();
};
