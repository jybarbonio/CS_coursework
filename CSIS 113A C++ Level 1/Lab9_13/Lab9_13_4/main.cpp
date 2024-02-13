#include <iostream>
#include <ctime>

using namespace std;

int main() 
{
	int num;
	int sum;
	int avg;
	int attempts = 0;
	cout << "Please enter a number between 1 and 1000" << endl;
	cin >> num;
	int rando;
	srand(time(0));		//seeds the random number to improve pseudo-random outcomes
	rando = rand() % 1001 + 1;		//1 to 1000, not 0 to 1000
	sum = rando;

	while(rando != num) 
	{
		rando = rand() % 1001 + 1;
		cout << rando << endl;
		sum += rando;
		attempts++;
	}
	avg = sum / attempts;
	cout << "It took " << attempts << " random number attempts before " << num << " was matched.";
	cout << " The sum of all the attempts are " << sum << " and the average of those numbers are " << avg << endl;

	system("pause");
	return 0;
}