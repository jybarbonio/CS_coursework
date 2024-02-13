#include <iostream>
using namespace std;

int main() 
{

	int num;
	cin >> num;

	int check = num % 2;
	cout << check << endl;
	if(check != 0) 
	{
		num += 1;
		cout << "num was odd and was made even by adding 1\n" << num << "\nSquare: \n" << pow(num,2) << endl << endl;
		check = 0;
	}
	else if(check == 0)
	{
		cout << pow(num, 2) << endl << "num  is even" << endl;	
	}
	system("pause");

}