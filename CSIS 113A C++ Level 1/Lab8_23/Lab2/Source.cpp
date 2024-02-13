#include <iostream>
using namespace std;

int main() 
{
	char ch;

	cout << "Enter a char and I will check if it's a vowel";
	cin >> c;

	switch(toupper(c)) 
	{
	case 'A':
	case 'E':
	case 'I':
	case 'O':
	case 'U':
		cout << "The char is a vowel" << endl;
		break;
	default:
		cout << "Not a vowel" << endl;
	}
}