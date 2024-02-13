#include <iostream>

using namespace std;

int main() 
{
	int num1, num2;
	cin >> num1 >> num2;
	int diff = abs(num1 - num2);

	while(diff <= 10) 
	{
		cout << "Difference: " << diff;
		cout << endl;
		cout << "Please enter a number " << endl;
		cin >> num1 >> num2;
		diff = abs(num1 - num2);
	}
	cout << "The difference between " << num1 << " and " << num2 << " is " << diff << endl;

	system("pause");
	return 0;
}