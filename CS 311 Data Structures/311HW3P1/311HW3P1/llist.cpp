//CS311 Yoshii Linked List class

//INSTRUCTION:
//Must use the provided HW3P1_help.doc to create llist.cpp
//It helps to first create if-then-else structure to fill in later.
//- Make sure PURPOSE and PARAMETER comments are given in detail
//  You can copy from a Word document to emacs (contrl-right click)
//  Highly recommended to copy HW3P1-help as PURPOSE of each function.
//
//- Make sure all if-then-else are commented describing which case it is
//- Make sure all local variables are described fully with their purposes

//EMACS HINT:
//  cntr-K cuts and cntr-Y pastes. 
//  Esc x replace-str does string replacements
//  Esc > goes to the end of the file; Esc < to the beginning
//  Tab on each line will indent perfectly for C++

// ====================================================
//HW#: HW3P1 llist
//Your name: John Barbonio
//Complier:  g++
//File type: llist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"llist.h" 

llist::llist()
{
	cout << "... in llist constructor..." << endl;
	Count = 0;		// intialize counter to 0
	Front = NULL;	// Front ptr set to null
	Rear = NULL;	// Rear ptr set to null
}

llist::~llist()
{
	cout << ".... in llist destructor..." << endl;

	while (!isEmpty()) 
	{
		el_t t;		// temp el_t used to fill func param
		deleteFront(t);		// deleteFront until empty
		// cout << "destructor has deleted " << t << endl;
	}
}

//PURPOSE:	gives a boolean on whether llist is empty, useful to prevent fatal errors by throwing exceptions in event isEmpty is true
//PARAMETER: void pass param, bool return
bool llist::isEmpty()
{	// be sure to check all 3 data members
	if (Front == NULL && Rear == NULL && Count == 0) { return true; }
	else { return false; }
}

//PURPOSE:	Displays all contents of the llist from front to end
//PARAMETER: void pass param, void return
void llist::displayAll()
// be sure to display horizontally in [  ] with
// blanks between elements e.g. [ 1 2 3 4 ]
// You MUST use while (P != NULL) loop or you will not get the credit!
{
	if (isEmpty())		// special case: llist is empty and prints empty
	{
		cout << "[ empty ]" << endl;
	}
	else 
	{
		Node* P = this->Front;		// set P to front/beginning of llist

		cout << "[";
		while (P != NULL)		// P starts with Front element, goes to back until it nexts the Rear->Next node and drops out the end and loop stops
		{
			cout << " " << P->Elem << " ";	// print elem with spaces to distinguish read
			P = P->Next;		// point to next element
		}
		cout << "]\n";			// close out set	
	}
}
//PURPOSE: adds a new node and element assigned to it to the rear of the llist
//PARAMETER: el_t variable (typedef int) pass param, void return
void llist::addRear(el_t NewNum)
{	// comment the 2 cases
	if (isEmpty())			// SPECIAL CASE: if front is null (if llist is empty), create new node, load it with passed elem, and link it up with ptrs 
	{
		Front = new Node;		// sets front as the new add Node
		Front->Elem = NewNum;	// assigns node the passed elem
		Rear = Front;			// sets rear and front ptrs as theres only one element
		Rear->Next = NULL;		// rear->next now points to null (or future llist node addition)
		Count++;
	}
	else						// REGULAR CASE: otherwise, create a new node, assign elem with passed param, and link to rear and repoint rear ptr
	{
		Node* P = Rear;			// set local ptr to rear, saving soon-to-be-former rear to assign to 
		Rear->Next = new Node;
		Rear = Rear->Next;
		Rear->Elem = NewNum;
		Rear->Next = NULL;
		Count++;
	}
}

//PURPOSE: adds new node and element assigned to it to the front of the llist
//PARAMETER: el_t (typedef int) pass param, void return
void llist::addFront(el_t NewNum)
{	// comment the 2 cases
	if (isEmpty())			// SPECIAL CASE: if llist is empty, need to establish, link, and load elem into a new node first and set next to NULL
	{
		Front = new Node;
		Front->Elem = NewNum;
		Rear = Front;
		Rear->Next = NULL;
		Count++;
	}
	else						// REGULAR CASE: otherwise, create a new node and link it to the existing chain, loading it with the passed element
	{
		Node* P = new Node;
		P->Elem = NewNum;		// set element
		P->Next = Front;		// Front is no longer actually front, t is front, so t->Next = front
		Front = P;				// shifts front to T itself
		Count++;
	}
}

//PURPOSE: deletes a node from the front of the llist, passes by reference back the elem from the removed node
//PARAMETER: pass by reference el_t address, void return ("return" by reference not value)
void llist::deleteFront(el_t& OldNum)
{	// comment the 3 cases
	if (isEmpty())						// ERROR CASE: if llist is empty, do nothing
	{
		// cout << "There is nothing to front delete. isEmpty is " << isEmpty() << " (0 is false and 1 is true)" << endl;
		throw Underflow();
	}
	else if (Front == Rear)				// SPECIAL CASE: if there is only one node, delete the one node
	{
		OldNum = Front->Elem;
		delete Front;
		Front = NULL;
		Rear = NULL;
		Count--;
	}
	else if (Front->Next != NULL)		// REGULAR CASE: if front contains an element and theres more than one elem, delete and re-link ptrs
	{
		Node* P = Front->Next;
		OldNum = Front->Elem;;
		delete Front;
		Front = P;
		Count--;
	}
}

//PURPOSE: deletes a node from the rear of the llist, pass by ref back the element of the deleted node
//PARAMETER: el_t address, void return (pass by reference not return by value)
void llist::deleteRear(el_t& OldNum)
{	// comment the 3 cases
	if (isEmpty())					// ERROR CASE: if llist is empty, do nothing
	{
		// cout << "There is nothing to rear delete. isEmpty is " << isEmpty() << " (0 is false and 1 is true)" << endl;
		throw Underflow();
	}
	else if (Front == Rear)		   // SPECIAL CASE: if there is only one node, delete the one node, thus llist becomes empty
	{
		OldNum = Front->Elem;
		delete Front;
		Front = NULL;
		Rear = NULL;
		Count--;
	}
	else if (Front->Next != NULL)	// REGULAR CASE: if there is more than one element, delete the Rear (p->Next)
	{
		Node* P = Front;
		while (P->Next != Rear)		// when P->Next is the same as the Rear, stop
		{
			P = P->Next;
		}
		OldNum = Rear->Elem;

		Node* deletePtr = P->Next;
		delete deletePtr;
		Rear = P;
		P->Next = NULL;
		Count--;
	}
} 
/* --- harder ones follow -- */

// Utility Function to move a local pointer to the Jth node
void llist::moveTo(int J, Node*& temp)
// moves temp J-1 times to go to the Jth node  
// for ( int K = ... ) temp = temp->Next;
{
	if (J > Count)
	{
		throw OutOfRange();
	}
	else 
	{
		Node* P = Front;
		for (int K = 1; K <= J - 1; K++)		// move P to J - 1th node for easier P->Next manipulation
		{
			P = P->Next;
		}
		temp = P;
	}
}

//PURPOSE: deletes an element at a specified index (node) of the llist
//PARAMETER: I index param, void return (passed by ref the deleted node elem)
void llist::deleteIth(int I, el_t& OldNum)
// must use moveTo to move local pointers. Be sure to comment to which node you are moving them. Do not forget to set OldNum.  
{
	if (I < 1 || I > Count)
	{
		throw OutOfRange();
	}
	else if (I == 1) 
	{
		this->deleteFront(OldNum);
	}
	else if (I == Count) 
	{
		this->deleteRear(OldNum);
	}
	else 
	{
		Node* P = Front;			// start ptr to go through all nodes J - 1th node index
		moveTo(I - 1, P);			// NOTE: MoveTo stops ptr I - 1th node
		Node* deletePtr = P->Next;	// created new ptr deletePtr that points to Jth node
		P->Next = deletePtr->Next;	// link elem chain before elem to be deleted with elem chain after elem to be deleted
		OldNum = deletePtr->Elem;

		delete deletePtr;			// delete the now isolated elem
		Count--;
	}
}

//PURPOSE: adds a new node and elem immediately ahead of the index, between two other nodes
//PARAMETER: int index for where, el_t newNum for new elem to be assigned to new node 
void llist::insertIth(int I, el_t newNum)
// must use moveTo to move local pointers. Be sure to comment to which node you are moving them.
{
	if (I > Count + 1 || I < 1)
	{
		throw OutOfRange();
	}
	else if(I == 1)		// special case
	{
		this->addFront(newNum);
	}
	else if (I == Count + 1)
	{
		this->addRear(newNum);
	}
	else 
	{
		Node* P = Front;
		moveTo(I - 1, P);	// I - 1 is done here instead of adding more cases to moveTo
		Node* N = new Node;
		N->Elem = newNum;	// load new element into new node
		N->Next = P->Next;	// link N->Next to 
		P->Next = N;		// configure P->Next to point to N, N->Next then pointing to rest of chain
		Count++;
	}
}
//PURPOSE: copy constructor for copying one llist to this llist
//PARAMETER: llist address param, no return as its a constructor
llist::llist(const llist& Original)
{
	//  this->'s data members need to be initialized here first
	Front = NULL; Rear = NULL; Count = 0;
	//  this-> object has to be built up by allocating new cells
	//  and copying the values from Original into each cell as we did with 
	//  operator= above. To do this,
// this-> object has to be built up by allocating new cells with OtherOne elements (**)
	Node* P;  // local pointer for OtherOne
	P = Original.Front;
	while (P != NULL)  // a loop which repeats until you reach the end of OtherOne. 
	{
		this->addRear(P->Elem);    //P’s element is added to this->
		P = P->Next;                         // Go to the next node in OtherOne   
	}        
		//  Nothing to return because this is a constructor.
}


//PURPOSE: operator overload to use = symbol to copy llist to another llist
//PARAMETER: llist& param, no return as its a constructor
llist& llist::operator=(const llist& OtherOne)
// use my code
{
	el_t x;
	// First make sure this-> and OtherOne are not the same object.
	// To do this, compare the pointers to the objects .
	if (&OtherOne != this)  // if not the same
	{
		// this-> object has to be emptied first.
		while (!this->isEmpty())
			this->deleteRear(x);
		// this-> object has to be built up by allocating new cells with OtherOne elements (**)
		Node* P;  // local pointer for OtherOne
		P = OtherOne.Front;
		while (P != NULL)  // a loop which repeats until you reach the end of OtherOne. 
		{
			this->addRear(P->Elem);    //P’s element is added to this->
			P = P->Next;                         // Go to the next node in OtherOne   
		}
	}// end of if              
	return *this;    // return the result unconditionally.  Note that the result is returned by reference.
}


