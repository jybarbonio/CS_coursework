/*
John Barbonio
0518876
2 September, 2018
Journal 3B Random Numbers
*/

#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	int min, max;
	srand((unsigned int) time(0));

	cout << "Enter your min value" << endl;
	cin >> min;
	cout << "Enter your max value" << endl;
	cin >> max;

	for(int j = 0; j < 10 ; j++) 
	{
		for(int i = 0; i < 10 ; i++) 
		{
			cout << (rand() % (min, max)) << "\t";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}