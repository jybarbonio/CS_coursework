/*
John Barbonio
0518876
16 September, 2018
Assignment 13: Using References
*/

/*
I used about 70% of the solution and originally tried doing for(i = 0; i < input[3]; i++) then realized that doesn't correctly add the specific char.
I changed the for loop to be three separate ones instead of an embedded if statement for clarity (though maybe it's bad coding practice?). 
I also removed the global const  int LENGTH = 9 and just changed the if statement to check if the string length was 9 characters directly. I will revert
it if this program has more use in the future.
*/
#include <iostream>
#include <string>

using namespace std;

bool decode(int &a, int &b, int &c, string input);
//const int LENGTH = 9;

int main() 
{
	cout << "Please enter nine characters" << endl;
	string str;
	cin >> str;

	int num1, num2, num3;
	bool state = decode(num1, num2, num3, str);

	if(state) 
	{
		cout << "The decoded sequence is" << endl;
		cout << num1 << endl;
		cout << num2 << endl;
		cout << num3 << endl;
	}
	else 
	{
		cout << "Invalid string length." << endl;
	}

	system("pause");
	return 0;
}
bool decode(int &a, int &b, int &c, string input) 
{
	if(input.length() != 9)		//define required string length here instead of as global variable
	{
		return false;	//string is not correct size for use in function
	}

	int i = 0;
	a = 0;
	b = 0;
	c = 0;

	for(i; i != 3; i++) 
	{
		a += static_cast<int>(input.at(i));
	}
	for (i; i >= 3 && i != 6; i++)
	{
		b += static_cast<int>(input.at(i));
	}
	for (i; i >= 6 && i != 9; i++)
	{
		c += static_cast<int>(input.at(i));
	}
	return true;
}