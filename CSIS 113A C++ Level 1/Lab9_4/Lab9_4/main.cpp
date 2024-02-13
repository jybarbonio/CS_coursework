/*
John Barbonio
0518876
4 September, 2018
Lab
*/
#include <iostream>

using namespace std;

int main() 
{
	int n;
	int num;
	cout << "How many numbers would you like to enter" << endl;
	cin >> n;

	int small, large;
	cout << "Enter a number " << endl;
	cin >> num;
	small = large = num;
	for(int i = 1; i < n; i++)
	{
		cout << "Enter a number" << endl;
		cin >> num;
		if (num > large) large = num;
		if (num < small) small = num;

	}
	cout << "The largest number was " << large << endl;
	cout << "The smallest number was " << small << endl;

	system("pause");
	return 0;
}