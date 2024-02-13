//CS311 Yoshii 
//INSTRUCTION:
//Stack class header file template based on Notes-1
//You must complete the ** parts and then complete stack.cpp
//EMACS HINT:
//  control-S does searches
//  Tab on each line will indent perfectly for C++

// =======================================================
// HW#: HW1P1 stack
// Your name: John Barbonio
// Compiler:  gcc 
// File type: headher file stack.h
//=======================================================
#include <vector>     // include vector class
//----- Globally setting up the aliases ----------------

const int MAX = 10;   // The MAX number of elements for the stack
                      // MAX is unknown to the client

typedef int el_t;     // the el_t type was **, is now int
                      // el_t is unknown to the client
//-------------------------------------------------------


class stack
{

private: // to be hidden from the client

    std::vector<el_t>el;    // el is  an array (now vector) of el_t's
    int      top;           // top is index to the top of stack

public:  // available to the client

    // Overflow exception msg, denotes if an addition to stack results in exceeding in stack size
class Overflow { public: char const* errorOverflow = "Attention: the stack is full. Too many elements have been provided."; char const* getOverflowError() { return errorOverflow; } };
    // Underflow exception msg, denotes if deletion of element results in an empty stack or underflow
class Underflow { public: char const* errorUnderflow = "Attention: no more elements can be removed. There are too few elements."; char const* getUnderflowError() { return errorUnderflow; } };

// prototypes to be used by the client
// Note that no parameter variables are given

stack();   // constructor to create an object
~stack();  // destructor  to destroy an object

// PURPOSE: if not full, enters an element at the top;
//          otherwise throws an exception - Overflow
// PARAMETER: pass the element to be pushed
void push(el_t);

// PURPOSE: if not empty, removes and gives back the top element;
//          otherwise throws an exception - Underflow
// PARAMETER: provide variable to receive the popped element (by ref)
void pop(el_t&);

// PURPOSE: if not empty, gives the top element without removing it;
//          otherwise, throws an exception - Underflow
// PARAMETER: provides holding variables for element at top of stack by reference address
void topElem(el_t&);

//PURPOSE: if stack is empty, returns true, if stack is populated, returns false
bool isEmpty();

//PURPOSE: if stack is full, returns true, if stack is empty, returns false
bool isFull();

//PURPOSE: loops through stack to print/list all elements within it
void displayAll();

//PURPOSE: using the pop method, recursively pops stack until isEmpty
void clearIt();

};

// Note: semicolon is needed at the end of the header file

