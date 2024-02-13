#include <iostream>

using namespace std;

void fillArray(int myArray[], int size);
void printArray(int myArray[], int size);

int main() 
{
	int myArray[20];

	int al;
	cin >> al;

	fillArray(myArray, al);
	printArray(myArray, al);

	system("pause");
	return 0;
}
void fillArray(int myArray[], int size) 
{
	for(int i = 0; i < size; i++) 
	{
		myArray[i] = rand() % 20 + 1;
	}
}
void printArray(const int myArray[], int size) 
{
	for(int i = 0; i < size; i++) 
	{
		cout << i + 1 << " " << myArray[i] << endl;
	}
}