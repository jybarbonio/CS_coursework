#include <iostream>

using namespace std;

void fillArray(int a[][5], int size);
void printArray(int a[][5], int size);
int countNums(int ar[][5], int size, int search);

int main()
{
	int ar[5][5];

	fillArray(ar, 5);
	printArray(ar, 5);

	cout << "What number do  you want to search for?" << endl;
	int num;
	cin >> num;
	int count = countNums(ar, 5, num);
	cout << "Your number appears " << count << " times in the 2D Array" << endl;

	system("pause");
	return 0;
}
void fillArray(int a[][5], int size) 
{	//to traverse an array you need a nested for loop
	for(int r = 0; r < 5; r++) 
	{
		for(int c = 0;c < 5; c++) 
		{
			a[r][c] = rand() % 10 + 1;
		}
	}
}
void printArray(int a[][5], int size)
{	//to traverse an array you need a nested for loop
	for (int r = 0; r < 5; r++)
	{
		for (int c = 0; c < 5; c++)
		{
			cout << a[r][c] << "\t";
		}
		cout << endl;
	}
}
int countNums(int ar[][5], int size, int search) 
{
	int count = 0;

	for (int r = 0; r < 5; r++)
	{
		for (int c = 0; c < 5; c++)
		{
			if (ar[r][c] == search) 
			{
				count++;
				cout << "Found at " << "Row " << r << " Column " << c << endl;
			}
		}
	}
	return count;
}
