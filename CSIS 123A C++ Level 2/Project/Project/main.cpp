#include <iostream>
#include <string>
#include <ctime>
#include "Point.h"

using namespace std;

struct Point
{
	int x;
	int y;
};
void setPoint(Point &pt);
void printPoint(Point &pt);

int main()
{
	Point pt;
	setPoint(pt);
	printPoint(pt);
	system("pause");
	return 0;
}
void setPoint(Point &pt) 
{
	cin >> pt.x >> pt.y;
}
void printPoint(Point &pt) 
{
	cout << "Your location is x: " << pt.x << " y: " << pt.y << endl;
}