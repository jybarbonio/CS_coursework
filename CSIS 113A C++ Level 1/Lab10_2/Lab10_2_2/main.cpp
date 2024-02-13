#include <iostream>
#include "Rectangle.h"

using namespace std;

void Rectangle::set_values(int l, int w) 
{
	length = l;
	width = w;
}
int Rectangle::area() 
{
	return length * width;
}
int main() 
{
	Rectangle rect;
	cout << "Rectangle 1." << rect.area() << endl;

	Rectangle r(4, 5);
	cout << "Rectangle 2." << r.area() << endl;

	return 0;
}
void fillRects(Rectangle r[], int size) 
{
	int l, w;
	for(int i = 0; i < size; i++) 
	{
		cout << "Enter a length and width" << endl;
		cin >> l >> w;
		r[i].set_values(l, w);
	}
}