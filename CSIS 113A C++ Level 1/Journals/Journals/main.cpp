#include <iostream>		//imports standard I/O

using namespace std;	//allocates a namespace

int main()		//main method
{
	int x, y;		//integers x and y to be compared

	cout << "Enter two values: " << endl;		//asks user to enter two values
	cin >> x >> y;		//seeks user input of two numbers then stores them in x and y

	bool val = x < y;		//boolean test for if x < y, val is true. otherwise false.
	if(val)		//if statement testing the above
	{
		cout << x << " is less than " << y << endl;		//prints if x IS LESS THAN y
		cout << "x is less than y" << endl;		//tells user x is less than y
	}
	else 
	{
		cout << x << " is greater than " << y << endl;	//prints if x IS GREATER THAN y
		cout << "x is greater than y." << endl;			//tells user x is greater than y (false condition)
	}
	system("pause");
	return 0;
}