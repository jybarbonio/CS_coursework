//INSTRUCTION:
//Look for ** using control-S
//Then, fill in the function body
//When done, compile queue.cpp to make sure it has no syntax errors

//=========================================================
//HW#: HW1P2 queue
//Your name: John Barbonio
//Complier:  gcc
//File type: queue.h  queue.cpp
//===========================================================

using namespace std;
#include <iostream>
#include "queue.h"  

// constructor
template<class T>
queue<T>::queue()
{  // initialize data members as in the notes
    this->count = 0;
    this->front = 0;    // initialize value
    this->rear = -1;     // initialize value
}

//destructor
template<class T>
queue<T>::~queue()
{ // nothing
}

// PURPOSE: returns true if queue is empty, otherwise false - checks count
template<class T>
bool queue<T>::isEmpty()
{
    if (this->count == 0)
    { return true; } else { return false; }
}

// PURPOSE: returns true if queue is full, otherwise false - checks count
template<class T>
bool queue<T>::isFull()
{
    if(this->count == MAX_SIZE)
    { return true; } else { return false; }
}

// PURPOSE: if full, throws an exception Overflow
// if not full, enters an element at the rear 
// PAREMETER: provide the element (newElem) to be added
template<class T>
void queue<T>::add(T newElem)
{
    if(this->isFull())
    {
        throw Overflow();
    }
    else 
    {
        this->rear = (this->rear + 1) % MAX_SIZE;
        this->el[this->rear] = newElem;
        this->count++;
    }
}

// PURPOSE: if empty, throw Underflow
// if not empty, removes the front element to give it back 
// PARAMETER: provide a holder (removedElem) for the element removed (pass by ref)
template<class T>
void queue<T>::remove(T& removedElem)
{
    if(this->isEmpty())
    {
        throw Underflow();
    }
    else 
    {
        removedElem = this->el[this->front];
        this->el[this->front] = "";
        this->front = (this->front + 1) % MAX_SIZE;
        this->count--;
    }
}

// PURPOSE: if empty, throws an exception Underflow
// if not empty, give back the front element (but does not remove it)
//PARAMETER: provide a holder (theElem) for the element (pass by ref)
template<class T>
void queue<T>::frontElem(T& theElem)
{
    if(this->isEmpty())
    {
        throw Underflow();
    }
    else
    {
        theElem = this->el[this->front];  // copies, does not remove from front
    }
}

// PURPOSE: returns the current size to make it 
// accessible to the client caller
template<class T>
int queue<T>::getSize()
{
    return this->count;
}

// PURPOSE: display everything in the queue horizontally
// from front to rear enclosed in [   ]
// if empty, displays [ empty ]
template<class T>
void queue<T>::displayAll()
{  if (this->isEmpty()) { cout << "[ empty ]" << endl;}
  else
    {
      int j = front;
      cout << "[";
      for (int i = 1; i <= this->count; i++)
      {
          if (((j + i) - 1) > this->count - 1)
          {
                std::cout << this->el[((j + i) - 1) % MAX_SIZE] << ", ";     // print elemnts of el array, no endl
          }
          else
          {
                std::cout << this->el[((j + i) - 1) % MAX_SIZE] << ", ";     // print elemnts of el array, no endl
          }
    }
      cout << "]" << endl;   
    }  
}

// PURPOSE: if empty, throws an exception Underflow
//if queue has just 1 element, does nothing
//if queue has more than 1 element, moves the front one to the rear by
//calling remove followed by add.
template<class T>
void queue<T>::goToBack()
{           
    T tmpFront; // ** comment a local variable
    if(this->isEmpty())
    {
        throw Overflow();
    }
    else if(this->count == 1)
    {
    }
    else
    {
        this->remove(tmpFront);
        this->add(tmpFront);
    }
}