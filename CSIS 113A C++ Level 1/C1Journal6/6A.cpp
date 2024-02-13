#include <iostream>

using namespace std;

void fillArray(int a[], int size);
void printArray(int a[], int size);

int main()
{
	int ar[10];

	fillArray(ar, 10);

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
}