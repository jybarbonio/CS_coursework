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