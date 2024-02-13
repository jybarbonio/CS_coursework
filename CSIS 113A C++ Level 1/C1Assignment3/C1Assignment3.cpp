/*
John Barbonio
SID: 0518876
16 August, 2018
Assignment 3: Simple Math Operators
*/

#include <iostream>
using namespace std;

int main()
{
	cout << "Please enter the temp in Fahrenheit: \n";	//prints to console requesting Fahrenheit, then does line feed

	double C;		//C = (F - 32) * (0.55)
	double F;		//Fahrenheit variable
	double K;		//K = (F - 32) * (5/9) + 273.15

	cin >> F;		//requests input for Fahrenheit
	C = (F - 32) * (0.55555);						//formula for Celsius from Fahrenheit
	cout << "The Celsius is: " << C << endl;	//prints the console the Celsius

	K = (F - 32) * (0.55) + 273.15;				//formula for Kelvin from Fahrenheit
	cout << "The Kelvin is: " << K << endl;		//prints to console the Kelvin

	return 0;
}
