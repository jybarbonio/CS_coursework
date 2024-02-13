/*
John Barbonio
SID: 0518876
15 August, 2018
Assignment 1: Console Output
*/

#include <iostream>
using namespace std;

int main()
{
	int SID_a = 0;									//first num of SID
	int SID_b = 518876;								//my SID is 0518876 but the data types don't allow leading zeroes or else it gets an "illegal digit '8' for base '8'" error
	char email[] = "jybarbonio@gmail.com";				//different from "String" and char in Java, at least at face value.
	char dueDate[] = "Sunday, August 19th at 11:59PM";	//due date string
	char embeddedCrlf[] = "test\n\n";						//testing if I could embed line feed into string

	cout << "John\n\n";						//you wanted the names to be separated into first and last
	cout << "Barbonio\n\n";					//last name, does a double spaced line feed using \n twice 
	//cout << SID_a << SID_b << endl << endl;	//Only needed in the comments at the top. double spaced using << endl
	cout << email << endl << endl;			/*prints email from char string str. double spaced using << endl.
										can I embed it in the char string?*/
	cout << dueDate << endl << endl;			//assignment is due Sundae, August 19th at midnight. << endl double spaced.
										//I'm unsure what double spaced means. If you wanted TWO spaces between lines then my bad
	//cout << test;						//embedded line feed works
	return 0;
}

