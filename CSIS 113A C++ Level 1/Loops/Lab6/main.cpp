/*
John Barbonio
0518876
28 August, 2018
Loops
*/

#include <iostream>

using namespace std;

int main()
{
	int num1, num2;
	char oper;

	cout << "Enter an expression " << endl;
	cin >> num1 >> oper >> num2;

	switch(oper) 
	{
	case '+':
		cout << "The sum is " << num1 + num2 << endl;
		break;
	case '-':
		cout << "The sum is " << num1 - num2 << endl;
		break;
	case '*':
		cout << "The sum is " << num1 * num2 << endl;
		break;
	case '/':
		if (num2 == 0)
			cout << "Cannot divide by 0" << endl;
		else
			cout << "The quotient is " << num1 / num2 << endl;
		break;
	default:
		cout << "Invalid input" << endl;
	}

	system("pause");
	return 0;
}