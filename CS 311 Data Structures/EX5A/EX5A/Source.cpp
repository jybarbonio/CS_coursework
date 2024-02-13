#include <iostream>
using namespace std;

int main()
{
	int r_constant = 0;

	for (int i = 0; i < 100; i++) 
	{
		int r = (i * (i - 1)) / 2;

		cout << r << " constant: " << r_constant << endl;
		r_constant--;

		system("pause");
	}
}