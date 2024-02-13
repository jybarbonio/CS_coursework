//CS311 Yoshii
//INSTRUCTION:
//Llist class - header file template 
//You must complete the ** parts and then complete llist.cpp
//Don't forget PURPOSE and PARAMETERS 

// =======================================================
// HW#: HW3P1 llist
// Your name: John Barbonio
// Compiler:  g++ 
// File type: headher file  llist.h
//=======================================================

// alias el_t : element type definition
typedef int el_t;  // int for now but can change later

//a list node is defined here as a struct Node for now
struct Node
{
public:
  el_t Elem;   // elem is the element stored
  Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist
{
 private:
     Node* Front;       // pointer to the front node
     Node* Rear;        // pointer to the rear node
 protected:
     int  Count;        // counter for the number of nodes:

     // untility function to move to a specified node position
     void moveTo(int, Node*&);
  
 public:

  // Exception handling classes 
  class Underflow
  { // underflow error msg
    public:
      char const* errorUnderflow = "ERROR: llist is empty. No more elements to remove.";
      char const* getUnderflowError() { return errorUnderflow; }
  };
  class OutOfRange      // thrown when the specified Node is out of range// thrown when the specified Node is out of range
  { // outofrange error msg
    public:
      char const* errorOutOfRange = "ERROR: The Node index you specified is beyond the range of the llist.";
      char const* getOutOfRangeError() { return errorOutOfRange; }
  };

  llist ();     // constructor to create a list object
  ~llist();     // destructor to destroy all nodes
  
  // checks if llist is empty, returns a boolean
  bool isEmpty();
    
  // display all elements of llist
  void displayAll();

  // add new node and element to the front of the llist, elem is param
  void addFront(el_t);
    
  // add new node and element to the end of the llist, elem is param
  void addRear(el_t);

  // delete element at front of llist, passing by ref back the deleted node's elem value
  void deleteFront(el_t&);
  
  //---------------------------------------
    
  // delete element at rear of llist, passing by ref back the deleted node's elem value
  void deleteRear(el_t&);
    
  // delete element at specified node index of llist, pass by ref back the deleted node's elem
  void deleteIth(int, el_t&);  // calls moveTo

  // add element at specified node index of llist, passing index and elem
  void insertIth(int, el_t);   // calls moveTo

  //Copy Constructor to allow pass by value and return by value of a llist
  llist(const llist&);
  
  //Overloading of = (returns a reference to a llist)
  llist& operator=(const llist&); 

};
