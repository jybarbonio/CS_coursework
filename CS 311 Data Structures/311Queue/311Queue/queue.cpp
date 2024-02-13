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
queue::queue()
{  // initialize data members as in the notes
    this->count = 0;        // initialize count is zero
    this->front = 0;    // initialize value
    this->rear = -1;     // initialize value
}

//destructor
queue::~queue()
{ // nothing
}

// PURPOSE: returns true if queue is empty, otherwise false - checks count
bool queue::isEmpty()
{
    if (this->count == 0)
    { return true; } else { return false; }
}

// PURPOSE: returns true if queue is full, otherwise false - checks count
bool queue::isFull()
{
    if(this->count == MAX_SIZE)
    { return true; } else { return false; }
}

// PURPOSE: if full, throws an exception Overflow
// if not full, enters an element at the rear 
// PAREMETER: provide the element (newElem) to be added
void queue::add(el_t newElem)
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
void queue::remove(el_t& removedElem)
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
void queue::frontElem(el_t& theElem)
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
int queue::getSize()
{
    return this->count;
}

// PURPOSE: display everything in the queue horizontally
// from front to rear enclosed in [   ]
// if empty, displays [ empty ]
void queue::displayAll()
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
    }
      cout << "]" << endl;   
    }  
}

// PURPOSE: if empty, throws an exception Underflow
//if queue has just 1 element, does nothing
//if queue has more than 1 element, moves the front one to the rear by
//calling remove followed by add.
void queue::goToBack()
{           
    el_t tmpFront; // el_t string variable
    if(this->isEmpty())
    {
        throw Overflow();
    }
    else if(this->count == 1)
    {
        // nothing
    }
    else
    {
        this->remove(tmpFront);
        this->add(tmpFront);
    }
}