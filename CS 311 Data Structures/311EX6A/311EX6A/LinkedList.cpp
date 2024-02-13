#include <iostream>
using namespace std;

struct Node
{
public:
	int Elem;	// elements in each node are integers
	Node* Next;
	Node* Prev;
};
struct LinkedList 
{
public:
	Node* Front;		// use of front to keep track of front, avoids dangling pointer
	Node* Rear;			// use of front to keep track of front, avoids dangling pointer

	LinkedList() 
	{
		Front = new Node;
		Front->Elem = 0;
		Rear = Front;
		Rear->Next = NULL;
	}
	void addRear(int elem) 
	{
		Node* t = Rear;
		Rear->Prev = t;
		Rear->Next = new Node;
		Rear = Rear->Next;
		Rear->Elem = elem;
		Rear->Next = NULL;
	}
	void addFront(int elem)
	{
		Node* t = new Node;
		t->Elem = elem;		// set element
		t->Next = Front;	// Front is no longer actually front, t is front, so t->Next = front
		Front = t;			// shifts front to T itself
	}
	void deleteRear() 
	{
		Node* p = Front;
		while (p->Next != Rear)	// when P->Next is the same as the Rear, stop
		{
			p = p->Next;
		}
		Node* deletePtr = p->Next;
		p = Rear->Prev;
		delete deletePtr;
		Rear = p;
	}
};
int main() 
{
	LinkedList LL;
	LL.addRear(3);
	LL.addFront(1);
	LL.deleteRear();
	LL.deleteRear();
	LL.deleteRear();
}