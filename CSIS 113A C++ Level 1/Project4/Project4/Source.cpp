#include <iostream>

using namespace std;

int main() 
{
	bool state = true;

	int a;
	int b;
	cin >> a >> b;

	for(int i = 0;i <= 12;i++) 
	{
		a *= 2;
		b *= 2;

		cout << a << " " << b << endl;
		
	}

	system("pause");
	return 0;
}