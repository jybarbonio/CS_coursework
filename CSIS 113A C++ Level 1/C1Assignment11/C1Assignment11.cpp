/*
I mainly used the cheat sheet solution to figure out the conditional operators for the smaller and larger value. I omitted the bool isVowel function because I wouldn't have known how to write that, and would've rather included
the if statement test in the sumConsonants function. That function does seem more robust for reading code. For the if statement in main that checks if sum == -1, I included curly brackets because why not? If it's
bad coding practice then why do it all? I learned that writing less code for time convenience creates problems and missed bugs. Originally I had made it so that if a char was lower case, it would be converted to
uppercase before being used in the loop i.e. if(islower(x) || islower(y)) -> x = toupper(x); y = toupper(y); else if(islower(x) && islower(y)) -> sum = -1;, then I saw the either in the instructions. For the isvowel if statement,
I included the empty else clause. In the example, you defined two int sum variables, one in the main method and one in the sumConsonants function. I changed the sum in main to getSum, to make it less confusing for me*/

/*
John Barbonio
0518876
9 September, 2018
Assignment 11: Functions, Loops, and Decisions
*/
#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

int sumConsonants(char x, char y);

int main()
{
	cout << "Please enter two uppercase consonants" << endl;
	char char1, char2;
	cin >> char1 >> char2;
	int getSum = sumConsonants(char1, char2);

	if (getSum == -1)
	{
		cout << "Invalid Input! Cannot use lowercase letters!" << endl;
	}
	else
	{
		cout << "The sum of the consonants in between the two characters is " << getSum << endl;
	}

	system("pause");		//needed because VS keeps auto shutting the console
	return 0;				//returns a 0, program closes cleanly
}
int sumConsonants(char x, char y)
{
	char i;
	int sum = 0;		//needed to be initialised before use

	char small = x < y ? x : y;
	char large = x > y ? x : y;

	if (islower(x) || islower(y))		//tests if either x or y is a lowercase letter, then sends it as invalid input
	{
		sum = -1;		//set to -1 to indicate and invalid input to the user
	}

	for (i = small; i <= large; i++)			//loop goes up or down the ASCII chart and adds the char value (actually integers) into the sum, omits adding vowels
	{
		if (i != 'A' || i != 'E' || i != 'I' || i != 'O' || i != 'U')		//tests if it's a vowel
		{
			sum += static_cast<int>(i);
		}
		else
		{
		}
	}
	return sum;		//sum is returned and assigned to getSum
}