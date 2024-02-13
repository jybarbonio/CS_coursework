/*
John Barbonio
0518876
19 August, 2018
Journal 1B Console Input
*/

#include <iostream>

using namespace std;

int main()
{

	int age;

	cout << "Please enter your age: " << endl;
	cin >> age; //cannot use endl wrong data flow direction

	int sqAge = pow(age, 2);	//age * age

	cout << sqAge << " is the square of your age" << endl;

	system("pause");		//console window kept closing even with run without debugging
	return 0;
}