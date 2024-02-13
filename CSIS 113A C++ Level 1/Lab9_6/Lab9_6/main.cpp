#include <iostream>
#include <cmath>
#include <string>

using namespace std;

void Swap(int x, int y);

int main() 
{
	string s;
	getline(cin, s, '?');
	cout << s << endl;

	system("pause");
	return 0;
}
void Swap(int x, int y) 
{
	int tmp = x;
	x = y;
	y = tmp;
	cout << "x: " << x << "y: " << y << endl;
}