#include <string>
#include "Number.h"

namespace john 
{
	Number::Number() 
	{
		this->equals("0");
	}
	Number::Number(string s) 
	{
		this->equals(s);
	}
	
}