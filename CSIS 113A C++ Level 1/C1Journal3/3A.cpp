/*
John Barbonio
0518876
2 September, 2018
Journal 3A For loops
*/

#include <iostream>

using namespace std;

int main()
{
	for (int row = 1; row < 10; row++)
	{
		for (int col = 1; col < 10; col++)
		{
			cout << row * col << "\t";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}
