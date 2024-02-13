/*
John Barbonio
0518876
30 September, 2018
Exam 3: Covers Functions
*/
#include <iostream>

using namespace std;

bool lastValues(int &num1, int &num2);

int main() 
{
	int number;
	cout << "Enter a number with at least two integers:" << endl;
	cin >> number;
	

	system("pause");
	return 0;
}
bool lastValues(int &num1, int &num2) 
{
	if (num1 < 10) 
	{
		return false;
	}
	while(&num1) 
	{
		if(num1 > 9) 
		{
			num1 = num1 / 10;
			if(num1 > 10 && num1 < 100) 
			{
				
			}
		}
	}
	
	
	int first, second;

}