/*
Pair.h
John Barbonio
6/23/2020
: This header file provides the function definitions and code for a Pair object, which contains two values within it that are initially templates
whose types can then be set. The Pair can be added and removed to a PairList vector as defined in PairList.h
*/
#pragma once

template <class T>	// one generic template type
class Pair
{
private:
	T first;
	T second;

public:
	Pair();
	Pair(T F, T S);

	void setFirst(T val_f);
	void setSecond(T val_s);

	T getFirst() const;
	T getSecond() const;

};
/*
Function: Pair
Author: John Barbonio
Date: 6/11/2020
Desc: This function is the default constructor, sets the two parameters T first and T second to an uninitialized garbage var
of type specified for the object via the Pair constructor that takes two parameters
I: n/a
O: n/a
*/
template <class T>
Pair<T>::Pair()
{
	Pair(T(), T());
}
/*
Function: Pair(T F, T S)
Author: John Barbonio
Date: 6/11/2020
Desc: This function is a constructor, it sets the two parameters T first and T second to whatever is passed to it via the setFirst and setSecond functions.
Template data type is defined in main.
I: template var, template var
O: n/a
*/
template <class T>
Pair<T>::Pair(T F, T S) 
{
	this->setFirst(F);
	this->setSecond(S);
}
/*
Function: setFirst(T val_f)
Author: John Barbonio
Date: 6/11/2020
Desc: This function sets the template variable first to the parameter passed to it
I: template var
O: n/a
*/
template <class T>
void Pair<T>::setFirst(T val_f) 
{
	this->first = val_f;
}
/*
Function: setSecond(T val_s)
Author : John Barbonio
Date : 6/11/2020
Desc : This function sets the template variable second to the parameter passed to it
I : template var
O : n/a
*/
template <class T>
void Pair<T>::setSecond(T val_s) 
{
	this->second = val_s;
}
/*
Function: getFirst() const
Author: John Barbonio
Date: 6/11/2020
Desc: This function returns the first variable, is const because there is no reassignment as it is only a getter
I : n/a
O : T this->first
*/
template <class T>
T Pair<T>::getFirst() const
{
	return this->first;
}
/*
Function: getSecond() const
Author: John Barbonio
Date: 6/11/2020
Desc: This function returns the second variable, is const because there is no reassignment as it is only a getter
I : n/a
O : T this-first
*/
template <class T>
T Pair<T>::getSecond() const 
{
	return this->second;
}