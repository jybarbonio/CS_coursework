/*
The problem with global variables is that they are not destroyed like local variables
in functions and that functions take the value of them if the local scope is undefined,
potentially making it hard to keep track of what assigns what
*/

#include <iostream>

using namespace std;

void printX();
void getX();

int x = 0;		//global scope (heap)

int main() 
{
	getX();
	printX();

	system("pause");
	return 0;
}
void printX() 
{
	cout << "The value of x is " << x << endl;
}
void getX() 
{
	int x;		//local scope supercedes global scope (stack)
	cout << "Enter a value for x " << endl;
	cin >> x;
	
}