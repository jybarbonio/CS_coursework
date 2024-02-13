/*
John Barbonio
0518876
16 September, 2018
Assignment 14; Overloaded Functions
*/
#include <iostream>
#include <string>

using namespace std;

int sumAscii(string string1);		//prototyped func that individually handles each string to be summed
int sumAsciis(string string1, string string2);		//smaller func that serves as a sort of navigation for the strings to be summed

int main() 
{
	int total;
	string str1;
	string str2;
	cout << "Enter two strings" << endl;
	cin >> str1 >> str2;
	total = sumAsciis(str1, str2);

	cout << "The sum of the two set of strings is " << total << endl;

	system("pause");
	return 0;
}
int sumAscii(string string1) 
{
	int length = string1.length();		//gets string length to set the for loop to loop that many times
	int total = 0;		//total is 0 because we haven't done anything yet

	for(int i = 0; i < string1.length(); i++) //for i starts at the beginning of the string, adds every letter until the end of the string, incrementing each time it is not at the end
	{
		total += static_cast<int>(string1.at(i));		//reused from assignment 13
	}
	return total;	//returns the total of the ascii characters
}
int sumAsciis(string string1, string string2) 
{
	int total1 = sumAscii(string1);		//gets the sum of the Ascii chars in str1 and returns it to total1
	int total2 = sumAscii(string2);		//reuses the same function code and gets the sum of both sets of strings by changing what is sent to sumAscii to str2
	return total1 + total2;		//returns the sum of both strings
}