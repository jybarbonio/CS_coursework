/*
John Barbonio
0518876
9 September, 2018
Assignment 10: Functions
*/
#include <iostream>
#include <ctype.h>

using namespace std;

double C2F(double C);
double K2F(double K);
double N2F(double N);

int main() 
{
	cout << "This is a temperature conversion program that converts other temperature types to Fahrenheit" << endl;
	cout << "The temperature types are:\nC - Celsius\nK - Kelvin\nN - Newton\nX - EXIT" << endl << endl;
	cout << "To use the converter you must input a value and the letter of the temp type\ni.e. 32 C converts 32 Celsius to Fahrenheit" << endl;
	cout << "Please DO NOT enter a letter first, or else the program will go nuclear" << endl;

	char op;		//option user enters
	double temp;
	cin >> temp >> op;		//getting the temp (int) and option (char)
	op = toupper(op);		//consistent uppercase input and makes sure the while loop catches x or X

	while(op != 'X')		//while op is not equal to x or X, using boolean state == true is bad coding practice
	{
		switch(op)			//switch choices based on what char the user inputted
		{
		case 'C':
			double getC;
			getC = C2F(temp);	//sends temp to be modified and returns result from func to getC
			cout << temp << " C in Fahrenheit is " << getC << " F" << endl;
			break;
		case 'K':
			double getK;		//sends temp to be modified and returns result from func to getK
			getK = K2F(temp);
			cout << temp << " K in Fahrenheit is " << getK << " F" << endl;
			break;
		case 'N':
			double getN;		//sends temp to be modified and returns result from func to getN
			getN = N2F(temp);
			cout << temp << " N in Fahrenheit is " << getN << " F" << endl;
			break;
		case 'X':
			cout << "Terminating" << endl;		//this case actually isn't needed now that cin is at the bottom and the while loop would stop before it can run this..
			break;
		default:
			cout << "Invalid Input! Please try again." << endl;
		}
		cout << "Please enter a value and the type to be converted" << endl;		//I don't know why, but I really hate putting cin at the end of the while loop like this!!
		cin >> temp >> op;		//gets temp (int) then option (char) to be checked in the repeating switch statement
		op = toupper(op);		//consistent uppercase input and makes sure the while loop catches x or X
	}

	system("pause");		//needed because VS keeps auto shutting the console
	return 0;				//returns a 0, program closes clean
}
double C2F(double C) 
{
	C = C * 9 / 5 + 32;		//C to F func
	return C;		//sends to getC
}
double K2F(double K) 
{
	K = (K - 273.15) * 1.8 + 32;		//K to F func
	return K;		//sends to getK
}
double N2F(double N)
{
	N = (N * 60) / 11 + 32;		//N to F func
	return N;		//sends to getN
}