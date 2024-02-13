#include <iostream>

using namespace std;

int main() 
{
	int total = 0;
	int num;
	int count;
	int avg;
	cout << "How many numbers?" << endl;
	cin >> count;

	for(num = 0; num <= count; num++) 
	{
		cout << "Enter a number" << endl;
		cin >> num;
		total += num;
		avg = total / count;
	}
	cout << "The average of the total of all numbers inputted is " << avg << endl;

	system("pause");
	return 0;
}