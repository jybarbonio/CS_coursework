#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

void fillVect(vector<int>&v, int size);
void printVect(const vector<int>&v, int size);

int main() 
{
	srand(static_cast<unsigned int>(time(0)));

	vector<int>myVect;
	fillVect(myVect, 20);

	system("pause");
	return 0;
}
void fillVect(vector<int>&v, int size) 
{
	for(int i = 0; i < size; i++) 
		v.push_back(rand() % 100);

	printVect(v, size);
}
void printVect(const vector<int>&v, int size)		/*const is used so 
it is read-only, since passing by reference has direct access data there
is the potential for unwanted data manipulation*/
{
	for (int i = 0; i < size; i++)
		cout << v[i] << endl;
}