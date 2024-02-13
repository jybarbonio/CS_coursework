#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>

using namespace std;

int main() 
{
	srand(static_cast<unsigned int>(time(0)));

	int num = 0;
	
	num = rand() % 51;

	int guess;

	bool state = true;
	int guesscount = 0;

	while(state)
	{
		num = rand() % 2;
		cout << "Guess the number\n";
		cin >> guess;

		if(guess == num) 
		{
			cout << "Correct!\n";
			cout << guesscount << endl;
			guesscount = 0;

		}
		else 
		{
			cout << "Wrong!\n";
			guesscount++;
		}

		cout << "do you want to continue?\n";
		char i;
		cin >> i;
		switch(i)
		{
		case 'y':
			state = true;
			break;
		case 'n':
			state = false;
			break;
		default:
			cout << "invalid, quitting";
			state = false;
		}
	}

	system("pause");
	return 0;
}