/*
John Barbonio
0518876
18 September, 2018
Assignment 15: Arrays as Arguments
*/

#include <iostream>
#include <ctime>

using namespace std;

void fillArray(int arr[]);
void printArray(int arr[]);
void countEvens(int arr[]);

int main()
{
	srand(time(0));		//seeds the random number sequence before the program is run
	int ar[25];		//25 sized array
	fillArray(ar);		//calls func fillArray with paramater ar[] array

	system("pause");
	return 0;
}
void fillArray(int arr[])
{
	int evens = 0;

	for (int i = 0; i < 25; i++)
	{
		arr[i] = rand() % 100 + 1;		//number between 1 and 100 (+ 1 is needed so the range is between 1 and 100)
	}
	printArray(arr);		//passes arr array and the number of even numbers in the array to be printed to console func
}
void printArray(int arr[])
{
	for (int i = 0; i < 25; i++)
	{
		cout << arr[i] << endl;
	}
	countEvens(arr);
}
void countEvens(int arr[])		//was I supposed to do something like void countEvens(int arr[], int evens)? Did you want the evens thing to be passed as a parameter?
{
	int evens = 0;
	for (int i = 0; i < 25; i++)
	{
		if (arr[i] % 2 == 0)
		{
			evens++;
		}
	}
	cout << "There are " << evens << " even numbers in this array" << endl;
}