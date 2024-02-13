#include "Point.h"
#include "Rectangle.h"

int totalArea(Rectangle r[], int size);
void filLRects(Rectangle r[], int size);

using namespace std;

Rectangle::Rectangle() 
{
	length = 1;
	width = 1;
}
Rectangle::Rectangle(int length, int width) 
{
	length = length;
	width = width;
}
void Rectangle::set_values(int l, int w) 
{
	length = l;
	width = w;
}
int Rectangle::area() 
{
	return length * width;
}