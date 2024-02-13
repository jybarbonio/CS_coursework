#include <iostream>
#include <ctime>
#include <cstring>
#include <stdio.h>
#include <ctype.h>

using namespace std;

void capFirst(char *ptr, char spaceCheck);

int main()
{
	char CString[] = "Allons enfants de la patrie, le jour de gloire est arrive!";
	char spaceCheck = 0x20;
	capFirst(CString, spaceCheck);

	cout << CString << endl;

	system("pause");
	return 0;
}
void capFirst(char *ptr, char spaceCheck) 
{
	char *p = ptr;

	while(*p)
	{
		if(*p == spaceCheck) 
		{
			p++;
			char result = toupper(*p);		//I thought I could just use toupper(*p) alone, but that doesn't work so I had to store the toupper in memory then reassign what the pointer was at to the stored capital letter
			*p = result;
		}
		p++;
	}
}
