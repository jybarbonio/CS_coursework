#include <iostream>
#include <string>

using namespace std;

void stringSmaller(string s);

int main() 
{
	string s = "1234x";

	stringSmaller(s);

	system("pause");
	return 0;
}
void Towers(int n, char source, char destination, char spare) 
{
	if(n <= 1) 
	{
		cout << "Move the top disc from " << source << " to " << destination << endl;
	}
	else 
	{
		Towers(n - 1, source, spare, destination);
		Towers(1, source, destination, spare);
		Towers(n - 1, spare, destination, source);

	}
}
void stringSmaller(string s) 
{
	if(s.length() == 1) 
	{
		cout << s << endl;
		return;
	}
	cout << s << endl;
	stringSmaller(s.substr(1, s.length()));
}