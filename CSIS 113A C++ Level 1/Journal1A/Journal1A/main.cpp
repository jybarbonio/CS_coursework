/*
John Barbonio
0518876
19 August, 2018
Journal 1C Math Operators
*/

#include <iostream>

using namespace std;

int main() 
{

	int x, y;
	cout << "Please enter two numbers " << endl;
	cin >> x >> y;

	int addxy = x + y;
	int subxy = x - y;
	int mulxy = x * y;
	int divxy = x / y;
	int modxy = x % y;

	cout << "The sum of your values is " << addxy << endl;
	cout << "The difference of your values is " << subxy << endl;
	cout << "The product of your values is " << mulxy << endl;
	cout << "The quotient of your values is " << divxy << endl;

	cout << "The remainder of your division is " << modxy << endl;
	//+ add, - subtract, * multiply, / divide, % remainder

	system("pause");	//console window kept closing even with run without debugging
	return 0;
}