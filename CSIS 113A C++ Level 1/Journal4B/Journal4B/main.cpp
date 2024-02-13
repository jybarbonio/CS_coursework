/*
John Barbonio
0518876
9 September, 2018
Journal 4B Value Producing Functions
*/
#include <iostream>

using namespace std;

int getValue();		//prototypes/return types for compiler
void sqrValue();

int main()		//main method, returns an integer
{
	sqrValue();		//you wanted sqrValue to be called first instead of getValue in the example?

	system("pause");	//stops VS auto closing
	return 0;	//returns a value
}
int getValue() 
{
	int val;
	cout << "Enter a number" << endl;
	cin >> val;
	cout << "The value entered is " << val << endl;
	return val;		//returns user input to sqrValue where this func was called
}
void sqrValue()		//void, doesn't return anything and all is printed inside the func
{
	int sqr;
	sqr = getValue();
	sqr = pow(sqr, 2);		//squares the value entered in getValue() func
	cout << "The number squared is " << sqr << endl;	//prints it to console
	return;		//returns nothing
}