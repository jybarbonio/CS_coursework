/*
John Barbonio
0518876
2 September, 2018
Assignment 89: More Primed Loops
*/

#include <iostream>		//standard I/O

using namespace std;		//standard libraries?

int main()
{
	double temp;		//double floating point temp to taking temperature
	char type;			//gets a single char (i.e. a letter) for the type of temperature to be converted

	cout << "This temperature conversion program converts Celsius, Kelvin, and Newton into Fahrenheit.\n";
	cout << "C - Celsius\nK - Kelvin\nN - Newton\nX - EXITS PROGRAM\n";

	bool state = true;		//game state true is running. false is 

	while (state)
	{
		cout << "Please enter a the degrees followed by its abbreviation. (ex: 30 C)\n";		//asks user for a number and a type of temperatures

		cin >> temp >> type;		//gets input for number first, type char second. The space denominates the difference between the two variables

		switch (tolower(type))	//calculates fahrenheit into whatever specified below and takes the char regardless of capitalization
		{
		case 'c':
			temp = temp * 9 / 5 + 32;		//calculating fahrenheit to celsius
			cout << temp << " F in Fahrenheit" << endl;
			break;
		case 'k':
			temp = (temp - 273.15) * 1.8 + 32;		//calculates fahrenheit to kelvin
			cout << temp << " F in Fahrenheit" << endl;
			break;
		case 'n':		//case newton
			temp = (temp * 60) / 11 + 32;		//newton calculation fahrenheit to newton
			cout << temp << " F in Fahrenheit" << endl;
			break;
		case 'x':		//case x terminates program
			cout << "terminating...\n";
			state = false;		//ends loop and closes program
			break;
		default:
			cout << "Invalid input. Try again\n";		//invalid input. program resets because boolean state remains the same
		}
	}

	system("pause");		//needed because VS keeps auto closing. Why is system considered ambiguous?
	return 0;
}