#include <iostream>
using namespace std;
#include <thread>
#include <chrono>
#include <iomanip>


int main() {
	int num1, num2, num3, num4, num5;

	cout << "Enter two numbers and I will give you the sum " << endl;
	cin >> num1 >> num2;

	int sum = num1 + num2;
	//dif, product, quotient
	int dif = num1 - num2;
	int quo = num1 / num2;
	int prod = num1 * num2;
	
	cout << "The sum is: " << sum << endl << dif << endl << quo << endl << prod << endl;

	cout << "John	" << "Barbonio	" << "19 Aug 2018	";
	double getnum;
	cin >> getnum;
	cout << getnum + 4 << endl;
	getnum = pow(getnum, 2);
	cout << getnum << endl;

	double pennies;
	double dollars;
	cout << "enter num of pennies: " << endl;
	cin >> pennies;

	dollars = pennies * .01;
	cout << fixed << setprecision(2) << "you have: " << dollars << " dollars in pennies" << endl;






	double speed = 0.0;

	while (speed < 88) {

		speed = speed + .20;
		cout << fixed;
		cout << setprecision(1);
		cout << speed << endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
		system("cls");
	}

	int period = 20;
	while (period > 0) {
		std::this_thread::sleep_for(std::chrono::milliseconds(20));
		cout << ".";
		period--;

	}
	cout << "\n88 miles per hour!" << endl;

	system("pause");
	
	return 0;
}