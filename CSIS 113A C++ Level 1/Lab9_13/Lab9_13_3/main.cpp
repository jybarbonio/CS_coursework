#include <iostream>
#include <ctime>
using namespace std;

int main() 
{
	char letter;
	char guess;
	cout << "Guess the letter!" << endl;
	cin >> guess;
	guess = toupper(guess);

	srand(time(0));
	letter = rand() % 25 + 65;

	do {
		cout << "Incorrect guess!" << endl;
		cout << "The answer is: " << letter << endl;
		cin >> guess;
		guess = toupper(guess);

		if(guess < letter) 
		{
			cout << "Too low! Guess higher!" << endl;
		}
		else if(guess > letter) 
		{
			cout << "Too high! Guess lower!" << endl;
		}

	} while (guess != letter);
		cout << "Correct!" << endl;

	system("pause");
	return 0;
}