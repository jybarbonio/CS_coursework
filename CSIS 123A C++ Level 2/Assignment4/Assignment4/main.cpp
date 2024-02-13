/*
John Barbonio
0518876
22 August, 2018
Assignment 4: Making Decisions
*/

#include <iostream>

using namespace std;

int main()		//main method
{
	double total_miles;		//total miles floating point
	double remainder;		//remainder after 100 is found with fmod for doubles
	double mileage = 0;		//mileage is initialised to 0
	cin >> total_miles;		//console input is retrieved for total miles

	if(total_miles <= 100)		//if the total miles is under or at 100, then use only .25 for mileage calculations
	{
		mileage = total_miles * .25;
	}
	else if(total_miles > 100)		//if it is more than 100 miles, calculate .25 for the first 100, then .15 for the rest and add together
	{
		remainder = fmod(total_miles, 100);		//modulus func for doubles
		remainder  *= .15;		//remainder itself * .15
		mileage = 25;		//first 100 miles are calculated (100 * .25)
		mileage += remainder;		//remainder (miles over 100) is added to mileage
		//I'm sure I can simplify these calculations to fewer lines but for now I'm separating them	
	}
	cout << "We owe you: " << mileage << endl;		//prints the total mileage of either if statement to console
	system("pause");		//needed because console keeps auto-closing even with 'run without debugging'
}