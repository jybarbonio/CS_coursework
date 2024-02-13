#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct guest 
{
	char first[50];
	char last[50];
	char email[50];
};

void writeGuest(guest g, int position);
void readGuest(guest &g, int position);

int main()
{
	guest g[] = {
		{ "John", "Barbonio", "jybarbonio@gmail.com" },
		{ "Kristofer", "Mendoza", "krismendoza447@gmail.com" },
		{ "Jane", "Doe", "soi@gmail.com" }
	};

	for (int i = 0; i < 3; i++) 
	{
		writeGuest(g[i], i);
	}


	/*guest gst;
	readGuest(gst, 2);
	cout << gst.first << "\t" << gst.last << "\t" << gst.email << endl;*/

	system("pause");
	return 0;
}
void writeGuest(guest g, int position) 
{
	ofstream outData("guests.txt", ios::binary | ios::app);
	if(!outData) 
	{
		cout << "Unable to open file for writing" << endl;
		return;
	}
	outData.seekp(position * sizeof(guest));
	outData.write(reinterpret_cast<const char *>(&g), sizeof(guest));
	outData.close();
}
void readGuest(guest &g, int position) 
{
	ifstream inData("guests.txt", ios::in);
	if(inData.fail()) 
	{
		cout << "Unable to open file for readng" << endl;
		return;
	}
	inData.seekg(position * sizeof(guest));
	inData.read(reinterpret_cast<char *>(&g), sizeof(guest));
}