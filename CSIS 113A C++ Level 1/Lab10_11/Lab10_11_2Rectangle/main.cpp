#include <iostream>
#include "Rectangle.h"

using namespace std;

void fillRect(Rectangle &r);
void printArea(Rectangle &r);

int main()
{
	Rectangle rect;
	fillRect(rect);
	printArea(rect);

	system("pause");
	return 0;
}
void fillRect(Rectangle &r) 
{
	cout << "Enter length and width" << endl;
	int length, width;
	cin >> length >> width;
	r.set_values(length, width);
}
void printArea(Rectangle &r) 
{
	int length, width;
	cout << "The area is: " << r.area() << endl;
}