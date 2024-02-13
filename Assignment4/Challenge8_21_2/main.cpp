#include <iostream>
using namespace std;



int main() 
{
	char grade;
	cin >> grade;

	if (grade == 'A' || 'a')	//you cannot do 
	{
		cout << "Excellent work!\n";
	}
	else if (grade == 'B' || 'b')
	{
		cout << "Very good!\n";
	}
	else if (grade == 'C' || 'c')
	{
		cout << "Average\n";
	}
	else if (grade == 'D' || 'd')
	{
		cout << "Not good\n";
	}
	else if (grade == 'F' || 'f')
	{
		cout << "failing!\n";
	}

	switch (grade)
	{
	case 'A':
		cout << "excellent";
		break;
	case 'B':
		cout << "very good";
		break;
	case 'C':
		cout << "average!";
		break;
	case 'D':
		cout << "failing";
		break;
	case 'F':
		cout << "failed";
		break;
	default:
		cout << "this is not a valid grade";
	}

	system("pause");
}