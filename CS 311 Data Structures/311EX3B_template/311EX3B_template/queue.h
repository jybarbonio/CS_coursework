//CS311 Yoshii
//INSTRUCTION:
// QUEUE class - header file template based on Notes-2A
// Look for ** and complete them 

// =====================================================
// HW#: HW1P2 queue
// Your name: John Barbonio
// Compiler:  g++ compiler
// File type: queue header file queue.h
//=====================================================

using namespace std;
#include<string>

//----- Globally setting up the aliases ----------------

// typedef string el_t;          // el_t is an alias for the data type
// el_t is unknown to the client  

const int MAX_SIZE = 10;  // this is the max number of elements - need to change it to 50 for client2.
// MAX_SIZE is unknown to the client
//-------------------------------------------------------

template<class T>
class queue
{
  private:
  // Data members are:
  T el[MAX_SIZE]; // an array called el.
                     // Elements will be found between front and rear but
                     // front may be behind rear since the queue wraps around
  int  count;          // how many elements do we have right now?
  int  front;          // where the front element of the queue is.
  int  rear;           // where the rear element of the queue is.

  public:    // prototypes to be used by the client
  // Note that no parameter variables are given

  //add exception handling classes here with comments
  class Overflow { public: char const* errorOverflow = "Attention: the stack is full. Too many elements provided."; char const* getOverflowError() { return errorOverflow; } };
  class Underflow { public: char const* errorUnderflow = "Attention: no more elements can be removed. Queue is empty."; char const* getUnderflowError() { return errorUnderflow; } };



   queue();   // constructor to create an object 
   ~queue();  //destructor to destroy an object

   // PURPOSE: returns true if queue is empty, otherwise false
   bool isEmpty();

   // PURPOSE: returns true if queue is full, otherwise false
   bool isFull();
   
   // PURPOSE: if full, throws an exception Overflow
   // if not full, enters an element at the rear 
   // PRAMETER: provide the element to be added
   void add(T);

   // PURPOSE: if empty, throws an exception Underflow
   // if not empty, removes the front element to give it back 
   // PRAMETER: provide a holder for the element removed (pass by ref)
   void remove(T&);

   // PURPOSE: if empty, throws an exception Underflow
   // if not empty, give back the front element (but does not remove it)
   // PARAMETER: provide a holder for the element (pass by ref)
   void frontElem(T&);

   // PURPOSE: returns the current size to make it 
   // accessible to the client caller
   int getSize();

   // PURPOSE: display everything in the queue from front to rear
   //  enclosed in []
   // if empty, displays [ empty ]
   void displayAll();

   // PURPOSE: if empty, throws an exception Underflow
   //if queue has just 1 element, does nothing
   //if queue has more than 1 element, moves the front one to the rear
   void goToBack();


};           
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
    {
        return true;
    }
    else { return false; }
}

// PURPOSE: returns true if queue is full, otherwise false - checks count
template<class T>
bool queue<T>::isFull()
{
    if (this->count == MAX_SIZE)
    {
        return true;
    }
    else { return false; }
}

// PURPOSE: if full, throws an exception Overflow
// if not full, enters an element at the rear 
// PAREMETER: provide the element (newElem) to be added
template<class T>
void queue<T>::add(T newElem)
{
    if (this->isFull())
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
    if (this->isEmpty())
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
    if (this->isEmpty())
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
{
    if (this->isEmpty()) { cout << "[ empty ]" << endl; }
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
    if (this->isEmpty())
    {
        throw Overflow();
    }
    else if (this->count == 1)
    {
    }
    else
    {
        this->remove(tmpFront);
        this->add(tmpFront);
    }
}
