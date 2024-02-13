/*
John Barbonio
0518876
28 August, 2018
Loops
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int num;
	cout << "Enter a number and I will check to see if it is odd or even" << endl;
	cin >> num;

	string result = num % 2 ? "Odd" : "Even";
	cout << "The number you input was " << result << endl;


	system("pause");
	return 0;
}