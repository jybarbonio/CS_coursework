/*
John Barbonio
0518876
25 November, 2018
Journal 9: Polymorphism and Inheritance
*/

#include <iostream>

using namespace std;

class Animaux 
{
private:
	int legs;
public:
	void setLegs(int legs);
	int getlegs();
	Animaux() :legs(4) {}
	void talk();
	virtual void speak() = 0;
};
void Animaux::talk() 
{
	speak();
}
void Animaux::setLegs(int legs) 
{
	this->legs = legs;
}
int Animaux::getlegs() 
{
	return this->legs;
}

class Cat : public Animaux 
{
public:
	void speak();
};
void Cat::speak() 
{
	cout << "meow" << endl;
}

class Dog : public Animaux 
{
public:
	void speak();
};
void Dog::speak() 
{
	cout << "woof" << endl;
}

class Bird : public Animaux 
{
public:
	void speak();
};
void Bird::speak() 
{
	cout << "chirp" << endl;
}

int main() 
{
	Cat cat;
	Dog dog;
	Bird bird;

	Animaux *an[3];
	an[0] = &cat;
	an[1] = &dog;
	an[2] = &bird;

	for(int i = 0; i < 3; i++) 
	{
		an[i]->talk();
	}

	system("pause");
	return 0;
	
}