#include <iostream>
using namespace std;

int main() 
{

	int age, tickets;
	cin >> tickets >> age;

	if(age >= 12 && age <= 15) 
	{
		cout << "tickets are $5" << tickets * 5.0;
	}
	else 
	{
		cout << "tickets are $6.50" << tickets * 6.50;
	}
	cout << endl;
	system("pause");

}