#include <iostream>
#include "Double.h"
#include "Integer.h"

using namespace std;

int main()
{
	Double d(12.6), d3;
	d3 = d.add(1.5);
	d3.print();

	Integer i(5), i3;
	i3 = i.add(5);
	i3.print();

	system("pause");
	return 0;
}