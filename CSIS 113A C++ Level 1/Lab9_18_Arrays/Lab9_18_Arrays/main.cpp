#include <iostream>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

int main() 
{
	double myArray[1000];
	string wordsArray[26] = { "Alfa", "Bravo", "Charlie", "Delta", "Echo", "Foxtrot", "Golf", 
	"Hotel", "India", "Juliett", "Kilo", "Lima", "Mike", "November", "Oscar", "Papa", "Quebec", "Romeo", "Sierra", "Tango", "Uniform", "Victor", "Whiskey", "X - ray", "Yankee", "Zulu"};

	int op = 0;
	int times = 0;

	for(int i = 0; i < 100; i++) 
	{
		if(i < 20) 
		{
			cout << "This random number is ";
			this_thread::sleep_for(chrono::milliseconds(20));
			myArray[i] = rand() % 1000;
			cout << myArray[i] << endl;
		}
		if (i == 20)
		{
			this_thread::sleep_for(chrono::milliseconds(5000));;
		}
		if(i > 20) 
		{
			this_thread::sleep_for(chrono::milliseconds(i + 4));
			cout << "Loading sector in " << wordsArray[rand() % 26] << endl;	//I can include various arguments in those brackets
		}
	}

	system("pause");
	return 0;
}