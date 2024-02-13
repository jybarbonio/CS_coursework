#include <iostream>

using namespace std;

int sumAscii(string s1, string s2);

int main() 
{
	string str = "hello";
	string str2 = "world";

	int total = sumAscii(str, str2);
	cout << "Sum of Ascii is " << total << endl;

	system("pause");
	return 0;
}
int sumAscii(string s1) 
{
	int sum = 0;
	for (int i = 0; i < s1.length(); i++) 
	{
		sum += static_cast<int>(s1.at(i));
	}
	return sum;
}
int sumAscii(string s1, string s2) 
{
	return sumAscii(s1) + sumAscii(s2);
}
