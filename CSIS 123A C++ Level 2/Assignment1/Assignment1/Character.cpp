#include <iostream>
#include <string>
#include "Character.h"

using namespace std;

void Character::equals(char c) 
{
	ch = c;
}
string Character::toString() 
{
	return to_string(ch);
}
int Character::toInt()
{
	return static_cast<int>(ch);
}