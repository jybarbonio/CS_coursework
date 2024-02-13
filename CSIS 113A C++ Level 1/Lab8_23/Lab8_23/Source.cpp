#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int age;
	int numPersons;
	double cost;
	cout << "How many people?" << endl;
	cin >> numPersons;
	cout << "\nWhat is the age of the group?\n";
	cin >> age;

	cost = age >= 55 ? numPersons * 7.5 : numPersons * 10;

	cout << fixed << setprecision(2) << "Your total cost is $" << cost << endl;
	system("pause");
}