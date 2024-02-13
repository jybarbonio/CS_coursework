/*
John Barbonio
0518876
22 August, 2018
Assignment 5: The Conditional Operator
*/

#include <iostream>
using namespace std;

int main()						//main method
{
	int wholesome;				//whole number int
	cin >> wholesome;			//gets user input for a number to be checked as odd or even
	cout << endl;				//line feed for neatness

	if (wholesome % 2 == 0)		//checks if number user inputted is odd or even using modulus with a number 2 (ints only)
	{
		cout << "this is an EVEN number\n";		//if true, tells user it's an even number
	}
	else						//if anything other than the condition above, then it's an odd number
	{
		cout << "this is an ODD number\n";		//tells user it's an odd number
	}
	system("pause");			//needed because my VS keeps auto-closing even with run without debugging
}