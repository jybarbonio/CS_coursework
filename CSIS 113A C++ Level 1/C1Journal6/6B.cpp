#include <iostream>
#include <ctime>

using namespace std;

void fillArray(int a[], int size);
void printArray(int a[], int size);
int countEvens(int a[], int size);
int countInstance(int a[], int size, int n);

int main()
{
	srand(time(0));
	int ar[10];

	fillArray(ar, 10);

	int count = countEvens(ar, 10);
	cout << "There are " << count << " even numbers in the array " << endl;
	cout << endl;

	int instance = countInstance(ar, 10, 4);	//the number specified will be 4
	cout << "There are " << instance << " of the number 4 in the array" << endl;

	system("pause");
	return 0;
}
void fillArray(int a[], int size)
{
	for (int i = 0; i < 10; i++)
		a[i] = rand() % 10 + 1;

	printArray(a, size);
}
void printArray(int a[], int size)
{
	for (int i = 0; i < 10; i++)
		cout << a[i] << endl;
	cout << endl;
}
int countEvens(int a[], int size)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (a[i] % 2 == 0)
			count++;
	}
	return count;
}
int countInstance(int a[], int size, int n)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (a[i] == n)		//the n is the instances of number 4, this was set in main
			count++;
	}
	return count;
}