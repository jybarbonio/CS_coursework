#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int main() 
{
	srand(time(0));
	string str = "bold";
	string guess;
	int i;
	int tries = 1;
	//str[rand() % 4] = '*';
	str[0] = '*';
	str[2] = '*';

	/*for(str = rand() % 4; str == '*'; str++)		//I was trying to guarantee there would ALWAYS be two bold asterisks randomly instead of defining them
	{
		str[rand() % 4] = '*';
	}*/

	cout << "Can you guess the word?" << endl;
	cout << str << endl;		//declare it before the loop, right?
	cin >> guess;
	str = "bold";		//reinstates the original word string after it was modified for console output
	do 
	{
		tries++;
		cout << "Incorrect! Please try again." << endl;
		cin >> guess;
	} while (guess != str);		//I could just set this to 'bold' instead of redeclaring the variable str, but I wanted to keep the modifying at the top

	cout << "Correct! It took you " << tries << " guesses to correctly guess the word" << endl;

	system("pause");
	return 0;
}