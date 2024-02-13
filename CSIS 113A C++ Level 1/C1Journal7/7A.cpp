#include <iostream>

using namespace std;

int main()
{
	int* p;

	int ar[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	p = &ar[0];		//also p = &ar[0]

	for (int i = 10, *p = &ar[9]; i > 0; i--, p--)	//can increment in the for loop or at the print
	{
		cout << *p << endl;
	}

	system("pause");
	return 0;
}