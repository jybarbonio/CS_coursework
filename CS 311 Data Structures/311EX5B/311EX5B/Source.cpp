#include <iostream>
using namespace std;

class Dog 
{
public:
	void bark() 
	{
		cout << "woof" << endl;
	}
};
int main() 
{
	// declare pointers P and Q to point to char cells
	char* P;
	char* Q;
	// make P point to a new cell, make Q point to a new cell
	P = new char;
	Q = new char;
	// assign values to new cells
	*P = 'x';
	*Q = 'y';
	// move P point to where Q is
	cout << *P << endl;
	P = Q;
	cout << *P << endl;
	// delete the Q cell
	delete Q;
	cout << *P << endl;
	// Make P point to nothing
	P = NULL;
	*Q = 'z';
	// cout << *P << endl;	// causes crash, dangling pointer points
							// to nothing or invalid data
// ----------------------------------------------------------------------------------------- //	
	Dog* D[5];			// create array of five pointers for Dog objects
	D[3] = new Dog();	// point the 4th element to a new Dog object
	D[3]->bark();		// call bark function from dog via dereference
}