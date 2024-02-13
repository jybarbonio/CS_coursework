/*
John Barbonio
0518876
11/18/2018
Journal 7 File IO
*/

#include <iostream>
#include <fstream>
#include <string>
#include "Fraction.h"
#include <time.h>

using namespace std;

void writeFraction(int amt);
void readFraction();
void Towers(int n, char source, char destination, char spare);
int addASCII(string s, int total, int n);

int main()
{
	/*
	Fraction f1(2, 4), f2(2, 8);
	Fraction f3 = f1 * f2;
	f3.reduce();
	f3.printFraction();

	Towers(3, 'A', 'B', 'C');
	*/
	string s = "swaz";

	int n = s.length();
	int total = addASCII(s, 0, n);

	cout << "Total: " << total << endl;

	system("pause");
	return 0;
}
void writeFraction(int amt)
{
	time_t t;
	srand((unsigned)time(&t));

	ofstream outfile("numbers.txt");
	if (!outfile)
	{
		cout << "Unable to open the file for writing" << endl;
		exit(1);
	}
	for (int i = 0; i < amt; i++)
	{
		int a = rand() % 100;
		int b = rand() % 100;

		Fraction f(a, b);
		f.getFractiond();
		f.getFractionn();

		outfile << f << endl;
	}
	outfile.close();
}
void readFraction()
{
	ifstream infile("numbers.txt");
	char in[100];
	while (infile >> in)
		cout << in << endl;

	infile.close();
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
int addASCII(string s, int total, int n) 
{

	if(n < 0) 
	{
		system("pause");
		cout << "Illegal" << endl;
		exit(-1);
	}
	if (n > 0) 
	{
		for (n; n > 0; n--)
		{
			total += static_cast<int>(s[n]);
			cout << total << " : " << s[n] << endl;
		}
		return (addASCII(s, total, n));
	}
	else 
	{
		total += static_cast<int>(s[0]);	//for the string[0] because the program declares itself illegal if I let n drop to >= 0 and let it subtract to -1
		cout << total << " : " << s[0] << endl;
		return total;
	}
}