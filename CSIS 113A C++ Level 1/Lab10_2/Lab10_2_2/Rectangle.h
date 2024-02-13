#pragma once
class Rectangle 
{
private:
	int length;
	int width;

public:
	void set_values(int l, int w);
	int area();
	Rectangle();
	Rectangle(int length, int width);
};