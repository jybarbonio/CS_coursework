/*
John Barbonio
0518876
9 September, 2018
Journal 4C Parameter Functions
*/
#include <iostream>

using namespace std;

int getValue();
int cubeIt(int x);
int sumIt(int x, int y, int z);

int main()	
{
	int num;
	num = getValue();
	int cube = cubeIt(num);		//actual parameter
	cout << "The cube of your value is " << cube << endl;

	int num1, num2, num3;
	cout << "Enter three numbers" << endl;
	cin >> num1 >> num2 >> num3;
	int theSum = sumIt(num1, num2, num3);
	cout << "The sum of the three numbers is " << theSum << endl;

	system("pause");
	return 0;
}
int getValue() 
{
	int val;
	cout << "Enter a number " << endl;
	cin >> val;
	return val;
}
int cubeIt(int x) 
{
	return x * x * x;

}
int sumIt(int x, int y, int z) 
{
	int sum;
	sum = x + y + z;

	return sum;
}