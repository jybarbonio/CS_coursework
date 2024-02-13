#include <iostream>
#include "Double.h"
#include "Integer.h"

using namespace std;

int main() 
{
	Double d;
	d.equals(12.34);
	d.print();

	Integer i;
	i.equals(5);
	i.print();

	system("pause");
	return 0;
}