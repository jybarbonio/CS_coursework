/*
John Barbonio
0518876
23 August, 2018
Assignment 6: The switch structure
*/

#include <iostream>		//imports standard I/O
using namespace std;	//standard C++ libraries

int main()		//main method that project starts from
{
	int x;		//first whole number
	int y;		//second whole number
	char op;	//character where user inputs type of operator

	cout << "Enter a basic expression.\n";		//tells user to enter a basic expression i.e. 6 * 3 or 2 + 5
	cin >> x >> op >> y;		//gets user input and stores corresponding input into these variables respectively

	switch (op)		//conditional tests for whatever the user inputted
	{
	case '+':		//addition case
		cout << "Addition Detected\n";
		cout << x + y;		//adds x and y
		break;
	case '-':		//subtraction case
		cout << "Subtraction Detected\n";
		cout << x - y;		//subtracts x from y
		break;
	case '*':		//multiplication case
		cout << "Multiplier Detected\n";
		cout << x * y;		//multiplies x with y
		break;
	case '/':		//division case
		cout << "Divisor Detected\n";
		cout << x / y;		//divied x by y
		break;
	default:		//if none of the above are true, default to invalid input
		cout << "invalid input\n";
	}
	cout << "\n";		//line feed for neatness
	system("pause");	//needed because VS keeps auto-closing even without debugging
	return 0;
}