//CS311 Yoshii 
//INSTRUCTION:
// Look for ** to complete the program (do control-S)
// Update the comments using the HOW TO COMMENT file, 
// When done, compile stack.cpp to make sure there are no syntax errors.
// NOTE: functions are called instead of repeating
// the same lines of code.

//=========================================================
//HW#: HW1P1 stack
//Your name: John Barbonio
//Complier:  gcc
//File type: stack implementation file stack.cpp
//=========================================================

using namespace std;
#include <iostream>
#include "stack.h"

//PURPOSE:  Constructor to create object. Must initialize top to be -1 to begin with.
stack::stack()
{
    top = -1; // indicate an empty stack }
}
//PURPOSE:  Destructor to destroy object. Does not have to do anything since this is a static array.
stack::~stack()
{ // nothing 
}

//PURPOSE: if stack is empty, returns true, if stack is populated, returns false
bool stack::isEmpty()
{
    if (top == -1) return true; else return false;
}

//PURPOSE: if stack is full, returns true, if stack is empty, returns false
bool stack::isFull()
{
    if (top == MAX - 1) return true; else return false;
}

// PURPOSE: if not full, enters an element at the top;
//      otherwise throws an exception - Overflow
// PARAMETER: pass the element to be pushed
void stack::push(el_t elem)
{
    if (isFull())
        throw Overflow();
    else { this->el.push_back(elem); elem = this->el.back(); }
}

// PURPOSE: if not empty, removes and gives back the top element;
//      otherwise throws an exception - Underflow
// PARAMETER: provide variable to receive the popped element (by ref)
void stack::pop(el_t& elem)
{
    if (isEmpty())
        throw Underflow();
    else { elem = this->el.back(); this->el.pop_back(); }   // pops the back of vector
}

// PURPOSE: if not empty, gives the top element without removing it;
//      otherwise, throws an exception - Underflow
// PARAMETER: provides holding variables for element at top of stack by reference address
void stack::topElem(el_t& elem)
{
    if (isEmpty()) throw Underflow();
    else { elem = this->el.back(); }
}

//PURPOSE: loops through stack to print/list all elements within it
//         Otherwise, diplays the elements vertically.
void stack::displayAll()
{
    cout << "STACK:---------" << endl;
    if (isEmpty()) cout << "[ empty ]" << endl;
    else for (int i = top; i > -1; i--)
    {
        cout << el.at(i) << endl;
    }
    cout << "--------------" << endl;
}


//PURPOSE: using the pop method, recursively pops stack until isEmpty
// it is empty 
void stack::clearIt()
{
    el_t temp;  // ** comment a local variable here
    while (this->isEmpty() == false)
    {
        this->pop(temp);
    }    // do not do top = -1, use a loop
}
