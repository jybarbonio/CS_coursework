#include <iostream>
#include <string>
#include "Rectangle.h"

using namespace std;

void Rectangle::set_values(int l, int w) 
{
	length = l;
	width = w;
}
int Rectangle::area() const
{
	return length * width;
}
void Rectangle::set_name(string nm) 
{
	name = nm;
}