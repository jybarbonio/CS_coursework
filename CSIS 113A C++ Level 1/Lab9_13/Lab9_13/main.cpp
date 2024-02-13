#include <iostream>
#include <string>

using namespace std;

int main() 
{
	char set;

	char A = 'A';
	char i = 'B';

	for(A = 'A'; A <= 'Z'; A++) 
	{
		for (set = 'A'; set <= A; set++)
		{
			cout << set;
		}
		cout << endl;
	}

	system("pause");
	return 0;
}