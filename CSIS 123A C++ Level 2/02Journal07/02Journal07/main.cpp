/*
John Barbonio
0518876
11/18/2018
Journal 7 File IO
*/

#include <iostream>
#include <fstream>
#include "Fraction.h"
#include <time.h>

using namespace std;

void writeFraction(int amt);
void readFraction();

int main()
{
	writeFraction(10);
	readFraction();

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
