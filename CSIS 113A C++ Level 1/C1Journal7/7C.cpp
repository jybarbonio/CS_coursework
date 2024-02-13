#include <iostream>

using namespace std;

void one();
void two();
void three();
void four();

int main()
{
	void(*func[4]) ();

	func[0] = one;
	func[1] = two;
	func[2] = three;
	func[3] = four;

	for (int i = 0; i < 4; i++)
	{
		func[i]();
	}

	system("pause");
	return 0;
}
void one()
{
	cout << "Hello from Func One" << endl;
}
void two()
{
	cout << "Hello from Func Two" << endl;
}
void three()
{
	cout << "Hello from Func Three" << endl;
}
void four()
{
	cout << "Hello from Func Three plus One" << endl;
}