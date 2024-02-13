#ifndef TRIANGLE
#define TRIANGLE

class triangle 
{
private:
	double base;
	double height;

public:
	void setBase(double base);
	void setHeight(double height);
	double getArea();
	double getHypotenuse();
	double getPerimeter();
	triangle();
};






#endif