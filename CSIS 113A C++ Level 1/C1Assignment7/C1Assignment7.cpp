/*
John Barbonio
0518876
1 September, 2018
Assignment 7: The For Loop
*/
#include <iostream>

using namespace std;

int main()		//main method
{
	int count;		//used for amount of loops counted (-2 in the for loop because two variables will be primed before it starts)
	int inp;		//takes in input
	int low;		//stores the low num
	int high;		//stores the high num

	cout << "How many numbers would you like to enter?\n";		//prompts user for amt of number inputs
	cin >> count;		//input for amt of nums  to be inputted
	cout << "Enter a number:\n";		//asks for number for low
	cin >> low;			//stores low
	cout << "Enter a number:\n";		//asks for a number for high
	cin >> high;		//stores high

	for (count; count > 2; count--)		//for count = (whatever user inputted); count > 2 (used to account for low and high above); count--
	{
		cout << "Enter a number:\n" << endl;
		cin >> inp;		//asks user to input a num

		if (low > high)		//if the first low is higher than the first high, replace the high
		{
			high = low;		//set high as equal to low if low is higher than high
		}
		else if (inp > high)	//if the inp is greater than the high input, replace high, if equal do nothing
		{
			high = inp;		//set high equal to inp if inp is higher than high
		}
		else if (inp < low)	//otherwise, if it is lower than low, replace the low
		{
			low = inp;		//set low equal to inp if inp is lower than low
		}
	}
	cout << "The lowest number was " << low;		//says what lowest num was
	cout << "\nThe largest number was " << high << endl;		//says what highest num was

	system("pause");		//needed because VS keeps auto closing
	return 0;		//returns a 0 from the program
}