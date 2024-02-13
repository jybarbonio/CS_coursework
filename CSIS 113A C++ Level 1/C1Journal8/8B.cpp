#include <string>

using std::string;		//never use std namespace in a header file, std:: narrows to specific func

#ifndef PLAYER
#define PLAYER
class Player
{
private:
	string Name;
	double average;

public:
	void setPlayer(double avg, string Name);
	double getAverage();
	string getName();

};

#endif