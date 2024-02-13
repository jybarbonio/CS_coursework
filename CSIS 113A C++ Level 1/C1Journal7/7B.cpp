#include <iostream>

using namespace std;

int xDigits(char* str, char change);

int main()
{
	char s[] = { "Abc12cdextz99052abzzzzzzzzzzzzz" };
	char z = 'z';
	int cnt = xDigits(s, z);
	cout << "Modified" << cnt << " digits, here is your string" << endl;
	cout << s << endl;

	system("pause");
	return 0;
}
int xDigits(char* str, char change)
{
	char* p = str;
	int count = 0;

	while (*p)
	{
		if (isdigit(*p))
		{
			*p = 'x';
			count++;
		}
		if (*p == change)
		{
			*p = '1';		//changes z's to ones
			count++;
		}
		p++;
	}
	return count;
}