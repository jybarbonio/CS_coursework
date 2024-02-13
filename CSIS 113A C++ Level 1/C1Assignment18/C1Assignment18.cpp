/*
John Barbonio
0518876
30 September, 2018
Assignment 18: Using Pointers
*/

#include <iostream>

using namespace std;

int removeChar(char* str, char change);

int main()
{
	char remove;		//remove var
	char s[100];
	cout << "Please enter a string!" << endl;
	cin.getline(s, 99);		//99 for null char and to prevent overflow (100 max but 0-99 range)
	cout << "Enter a character to be removed" << endl;
	cin >> remove;
	int count = removeChar(s, remove);
	cout << "This program modified " << count << " characters, here is your new string:" << endl;
	cout << s << endl;

	system("pause");
	return 0;
}
int removeChar(char* str, char change)
{
	char* p = str;
	int count = 0;

	while (*p)
	{
		if (*p == change) //change was set to "remove" var thus equals 'a'
		{
			*p = 0x20;	//hex for a space
			count++;
		}
		else if (*p == 0x0)
		{
			*p = 0x20;	//replaces nulls with spaces? Is this what you were asking for? How does one actually remove that char from the string like in the example? 0x8 backspace?
		}
		p++;
	}
	return count;
}