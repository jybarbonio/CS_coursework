#include <iostream>		//brackets around the name because it's within the compiler
#include "Player.h"		//quotes around the name because it is only in the project, not with the compiler

Player::Player()
{
	Player("Joe", 0.0);
}
Player::Player(string Name)
{
	Player(Name, 0.0);
}
Player::Player(string Name, double average)
{
	this->Name = Name;
	this->average = average;
}

void Player::setPlayer(double avg, string Name) //tells compiler that setPlayer is prototyped in header file
{
	this->average = avg;
	this->Name = Name;
}
double Player::getAverage()
{
	return this->average;
}
string Player::getName()
{
	return this->Name;
}