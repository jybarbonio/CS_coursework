#include <iostream>
#include <string>

using namespace std;

int main() 
{
	string str;

	cout << "Enter some text " << endl;
	getline(cin, str, ',');
	cout << str << endl;
	
	system("pause");
	return 0;
}