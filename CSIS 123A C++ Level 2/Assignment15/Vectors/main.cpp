#include <iostream>
#include <vector>
using namespace std;

void printArray(const int ar[], int size);
void fillVect(vector<int> &v, int size);
void printVect()

int main() 
{
	vector<int> myVect;
	fillVect(myVect, 25);
	printVect(myVect);

	system("pause");
	return 0;
}