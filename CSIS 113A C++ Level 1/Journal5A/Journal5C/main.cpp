#include <iostream>

using namespace std;

int sumInt(int a, int b);
int sumInt(int a, int b, int c);
int sumfourInts(int a, int b, int c);
int sumfourInts(int a, int b, int c, int d);

int main() 
{
	cout << "Enter three numbers and I will sum them" << endl;
	int w, x, y, z;
	cin >> x >> y >> z;

	int mySum = sumInt(x, y, z);
	cout << "The sum of your numbers is " << mySum << endl;

	cout << "Enter four numbers and I will sum them" << endl;
	cin >> w >> x >> y >> z;
	int sumFour = sumfourInts(w, x, y, z);
	cout << "The sum of your numbers is " << sumFour << endl;

	system("pause");
	return 0;
}
int sumInt(int a, int b) 
{
	return a + b;
}
int sumInt(int a, int b, int c) 
{
	return sumInt(sumInt(a,b), c);
}
int sumfourInts(int a, int b, int c) 
{
	return a + b + c;
}
int sumfourInts(int a, int b, int c, int d) 
{
	int theSum = sumfourInts(a, b, c);
	return sumfourInts(sumfourInts(a, b, c), d, 0);		//I know I shouldn't put a zero there but I couldn't figure it out
}