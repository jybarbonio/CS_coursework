#include <iostream>
#include <string>
#include <ctime>
#include "Rectangle.h"

using namespace std;

int totalArea(Rectangle r[], int size);
void fillRects(Rectangle r[], int size);

int main() 
{
	Rectangle rects[5];
	fillRects(rects, 5);
	int area = totalArea(rects, 5);
	cout << "The total area of the rectangles is: " << totalArea(rects, 5) << endl;
	system("pause");
	return 0;
}
void fillRects(Rectangle r[], int size) 
{
	for(int i = 0; i < size; i++) 
	{
		cout << "Enter a length and width" << endl;
		cin >> r[i].length >> r[i].width;
	}
}
int totalArea(Rectangle r[], int size) 
{
	int total = 0;
	for (int i = 0; i < size; i++)
	{
		total += r[i].area();
	}
	return total;
}