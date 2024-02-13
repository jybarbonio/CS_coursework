#pragma once

struct QuickSort
{
private:
	long it;

public:
	QuickSort() { this->it = 0; }
	QuickSort(double list[], int m, int n) { this->it = 0; this->quickSort(list, m, n); }

	void fillArray(double* p, int size);
	void quickSort(double list[], int m, int n);
	int choosePivot(double i, double j);
	long getIterations();
	void resetIt();
};
