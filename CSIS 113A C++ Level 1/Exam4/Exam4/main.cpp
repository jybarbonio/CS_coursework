#include <iostream>
#include <ctime>

using namespace std;

int smallest(int anArray[]);

int main() 
{
	srand(time(0));
	int anArray[50];

	for(int i = 0; i < 50; i++) 
	{
		anArray[i] = rand() % 100 + 1;
		cout << anArray[i] << endl;
	}

	int result = smallest(anArray);
	cout << endl;
	cout << "The smallest number is: " << result << endl;

	system("pause");
	return 0;
}
int smallest(int anArray[]) 
{
	int result = anArray[0];

	for(int i = 0; i < 50; i++) 
	{
		if(anArray[i] < result) 
		{
			result = anArray[i];
		}
	}

	return result;
}
