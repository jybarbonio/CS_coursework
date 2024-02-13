#include <iostream>
#include <string>

using namespace std;

int main()
{
	for(char ch = 'A'; ch <= 'E'; ch++) 
	{
		for(char c = ch; c <= 'X'; c++) 
		{
			cout << c << '\t';
		}
		cout << endl;
	}

	system("pause");
	return 0;
}