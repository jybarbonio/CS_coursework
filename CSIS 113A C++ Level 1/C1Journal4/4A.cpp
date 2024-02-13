/*
John Barbonio
0518876
9 September, 2018
Journal 4A simple functions
*/
#include <iostream>

using namespace std;

void printName();
void printDate();

int main()		//main method, returns an integer
{
	printName();

	system("pause");	//VS keeps auto closing cmd prompt
	return 0;	//returns an integer
}
void printName() //printName func returns nothing
{
	cout << "Hello from John!" << endl;
	printDate();
	return;
}
void printDate() //printDate func returns nothing
{
	cout << "Today's date is September 9th, 2018." << endl;
	return;	//nothing is returned, goes back to printName func, then to main method where program ends
}