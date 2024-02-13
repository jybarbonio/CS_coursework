#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void writeNumbers(string fName, int size);

int main() 
{
	writeNumbers("numbers.txt", 8);

	char val[100];
	ifstream infile("numbers.txt");
	while(!infile.eof()) //this func cannot take strings 	infile.getline(val, 100);
	{
		infile.getline(val, 100);
		cout << val << endl;
	}
	infile.close();

	system("pause");
	return 0;
}
void writeNumbers(string fName, int size) 
{
	ofstream outFile;

	if(outFile.fail()) 
	{
		cout << "Unable to open file for writing" << endl;
		return;
	}
	outFile.open(fName, ios::app);
	
	for(int i = 0; i < size; i++) 
	{
		outFile << rand() % 100 + 1 << endl;	
	}
	outFile.close();
}