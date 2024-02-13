/*
John Barbonio
0518876
2 September, 2018
Journal 3C the While loop
*/

#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	srand(static_cast<unsigned int>(time(0)));

	bool state;
	char yn;
	int count = 1;
	int num = rand() % 10 + 1;
	int guess;

	cout << "Would you like to play?\n";
	cin >> yn;

	switch(tolower(yn))
	{
	case 'y':
		state = true;
		cout << "OK!\n";
		break;
	case 'n':
		cout << "OK. Now closing\n";
		break;
	default:
		state = false;
		cout << "Invalid Input! Now closing...\n";
	}

	cout << "Guess a number between 1 and 10 " << endl;
	cin >> guess;

	while(state) 
	{
		count++;

		cout << "Guess a number between 1 and 10" << endl;
		cin >> guess;

		if(guess == num)
		{
			cout << "It took " << count << " guesses to guess correctly\n" << endl;
		}
		cout << "Play again?\n";
		cin >> yn;

		switch(tolower(yn))
		{
		case 'y':
			state = true;
			cout << "OK!\n";
			break;
		case 'n':
			cout << "OK. Now closing\n";
			break;
		default:
			state = false;
			cout << "Invalid Input! Now closing...\n";
		}
	}

	system("pause");
	return 0;
}