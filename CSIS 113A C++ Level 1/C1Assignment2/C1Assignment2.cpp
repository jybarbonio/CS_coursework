/*
John Barbonio
SID: 0518876
16 August, 2018
Assignment 2: Creating Variables
*/

#include <iostream>			//include input/output library header thing
using namespace std;		//using standard definitions i.e. cout, cin etc.


int main()				//starting point of project
{
	char theChar;			//char string with 1 char sized array
	double theDouble;		//floating point value
	int theInt;			//integer i.e. whole number

	cout << "Enter a character, a double, and an int:" << endl;		//prints a text string to console telling user what to input
	cin >> theChar >> theDouble >> theInt;						//console INPUT goes into char, double, and int respectively according to reversed data flow arrow indicators
	theDouble = theDouble - 2;								//whatever the user inputted - 2
	theChar++;											//I tried using just theChar++, I guess even with 1 var, I have to specify the array section?

	cout << "The Char: " << theChar << "\nThe Double: " << theDouble << "\nThe Int: " << pow(theInt, 2) << endl;
	/* I could embed the above operations on the variables (18 - 21) into the cout print (23) but isn't that bad/unclear coding practice?
	I embedded the power operation for theInt and the line feed in the text strings
	*/

	return 0;		//this is used as opposed to void main as seen like in Java
}

