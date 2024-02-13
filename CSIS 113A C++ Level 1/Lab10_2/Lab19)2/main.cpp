#include <iostream>
#include <string>

using namespace std;

int movement(int x, int y, int hp);

int main() 
{
	int health = 100;

	int x = 0;
	int y = 0;

	while(health > 0) 
	{
		cout << x << " " << y << endl;
		char in;
		cin >> in;

		 switch(in) 
		 {
		 case 'n':
			 y++;
			 break;
		 case 's':
			 y--;
			 break;
		 case 'e':
			 x++;
			 break;
		 case 'w':
			 x--;
			 break;
		 default:
			 cout << "invalid input" << endl;
		 }
	}

	system("pause");
	return 0;
}
int movement(int x, int y, int hp) 
{
	return 0;
}
