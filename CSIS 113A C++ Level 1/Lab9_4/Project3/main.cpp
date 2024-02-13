/*
John Barbonio
0518876
4 September, 2018
Lab: Functions
*/

#include <iostream>
using namespace std;

void squareVal();		//prototypes/prototyping
int getVal();

int main()
{
	double num1, num2, num3;
	cout << "Enter three doubles " << endl;
	cin >> num1 >> num2 >> num3;

	double sqSum = squareSum(num1, num2, num3);
	cout << "The square of the sum of the numbers is " << endl;

	return 0;
}
double squareSum(double a, double b, double c) 
{
	double sum = a + b + c;
	return sum * sum;
}