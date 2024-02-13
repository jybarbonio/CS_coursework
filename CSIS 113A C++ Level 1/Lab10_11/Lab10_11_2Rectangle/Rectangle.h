#ifndef RECTANGLE
#define RECTANGLE
#include <string>

using std::string;		//in header files, you don't want to use an entire namespace, rather scope to the specific function

class Rectangle 
{
private:
	int width;
	int length;
	string name;
public:
	void set_values(int l, int w);	//these are nothing more than func prototypes until they are defined
	void set_name(string nm);
	int area() const;
};

#endif
