/*
John Barbonio
0518876
23 September, 2018
Assignment 16: 2D Arrays
*/
#include <iostream>

using namespace std;

void fill2DArray(int a[][10], int size);
void print2DArray(int a[][10], int size);
int getDivisible(int ar[][10], int size, int divisor);
void printArray();

int main()
{
	int ar[10][10];

	fill2DArray(ar, 10);
	print2DArray(ar, 10);

	cout << "What number do  you want to search for?" << endl;
	int divisor;
	cout << "Please provide the divisor" << endl;
	cin >> divisor;
	/*cout << "Please provide the quotient" << endl;
	cin >> quotient;*/

	int count = getDivisible(ar, 10, divisor);
	cout << "There are " << count << " evenly divisible numbers in the 2D Array" << endl;
	//printArray();

	system("pause");
	return 0;
}
void fill2DArray(int a[][10], int size)
{	//to traverse an array you need a nested for loop
	for (int r = 0; r < 10; r++)
	{
		for (int c = 0; c < 10; c++)
		{
			a[r][c] = rand() % 1000 + 1;
		}
	}
}
void print2DArray(int a[][10], int size)
{	//to traverse an array you need a nested for loop
	for (int r = 0; r < 10; r++)
	{
		for (int c = 0; c < 10; c++)
		{
			cout << a[r][c] << "\t";
		}
		cout << endl;
	}
}
int getDivisible(int ar[][10], int size, int divisor)
{
	int ar1D[1000];
	int count = 0;
	int i = 0;

	for (int r = 0; r < 10; r++)
	{
		for (int c = 0; c < 10; c++)
		{
			if (ar[r][c] % divisor == 0)
			{
				count++;
				cout << "Found at " << "Row " << r + 1 << " Column " << c + 1 << endl;
			}
		}
	}
	return count;
}
