/*
main.cpp
John Barbonio
7/16/2020
: This main cpp file is used to test the funcs of the timer in tandem with the various sorting algorithms
*/

#include "Timer.h"
#include "InsertionSort.h"
#include "SelectionSort.h"

#include <iostream>
#include <ctime>
using std::iostream;


int main()
{
// Timer start
	Timer t;
	t.startTimer();
	//srand(time(0));

// STAGE 1: InsertionSort test
	/*
	double list1[12000];
	double* p1 = list1;

	InsertionSort ins1;
	ins1.fillArray(p1, 12000);
	ins1.insertionSort(p1, 11999);

	std::cout << "Iterations: " << ins1.getIterations() << std::endl;
	// TIMES (ms): 111.127, 115.959, 108.881, 119.741
	*/


// STAGE 2: SelectionSort test
	/*
	double list2[12000];
	double* p2 = list2;

	SelectionSort slc1;
	slc1.fillArray(p2, 12000);
	slc1.selectionSort(p2, 11999);

	std::cout << "Iterations: " << slc1.getIterations() << std::endl;
	// TIMES (ms): 157.831, 169.809, 163.317, 163.661
	*/


// STAGE 3: QuickSort.h test
	/*
	double list3[12000];
	double* p3 = list3;

	SelectionSort qc1;
	qc1.fillArray(p3, 12000);
	qc1.selectionSort(p3, 11999);

	std::cout << "Iterations: " << qc1.getIterations() << std::endl;
	qc1.resetIt();
	// TIMES (ms): 160.414, 163.118, 157.43, 168.764
	*/

// STAGE 4:

	double list4[12000];
	double* p4 = list4;

	SelectionSort sh1;
	sh1.fillArray(p4, 12000);
	sh1.selectionSort(p4, 11999);

	std::cout << "Iterations: " << sh1.getIterations() << std::endl;
	// TIMES (ms): 156.454, 167.959, 184.686, 168.521

// Timer end
	t.stopTimer();
	std::cout << "In Milliseconds " << t.getMilli() << std::endl;
	std::cout << "In Seconds " << t.getSeconds() << std::endl;
	std::cout << std::fixed << "In Microseconds " << t.getMicro() << std::endl;

	return 0;
}