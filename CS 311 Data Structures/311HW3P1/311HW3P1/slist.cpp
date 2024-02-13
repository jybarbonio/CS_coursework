// CS311 Yoshii Complete all functions with their comments

// ====================================================
//HW#: HW3P1 slist  inheriting from llist
//Your name: John Barbonio
//Complier:  g++
//File type: slist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"slist.h" 

// ** Make sure llist constructor and destructors have couts in them


// do not change this one
slist::slist()
{ cout << "slist constructor:" << endl; }

// positions always start at 1
// in words, start by comparing from first position on the list, comparing each element until rear
int slist::search(el_t key)
{
    if (isEmpty())  // if array is empty, toss 
    {
        throw Underflow();
        return 0;
    }
    else 
    {
        Node* temp;
        for (int i = 1; i <= Count; i++) 
        {
            moveTo(i, temp);        // moveTo through all Nodes and if elem matches key, then ref return index i
            if (temp->Elem == key)
            {
                return i;
            }
        }
        return 0;       // return 0 if elem is not found in list
    }
}

// don't forget to throw OutOfRange for bad pos 
// You must use moveTo to go to the pos
void slist::replace(el_t element, int pos)  // int pos (as in notes) or int I?
{
    if (pos > Count)    // you can't replace an element that doesn't exist (OutOfRange)
    {
        throw OutOfRange();     // toss error if desired pos is out of range of index count
    }
    else 
    {
        Node* t = new Node;
        moveTo(pos, t);     // replace Node with t Node carrying new elem
        t->Elem = element;
    }
}
// operator overload is equal
bool slist::operator==(const slist& OtherOne)
{
  // if not the same length, return false immediately
    if (Count != OtherOne.Count) 
    {
        return false;       // llists are not equal, thus cannot be the same in any case
    }
    // if the same lengths
    else
    {
        Node* t1;        // used for comparing this llist elem to param llist elem
        Node* t2;
        slist s1 = OtherOne;
        for (int i = 1; i <= Count; i++)
        {
            moveTo(i, t1);
            s1.moveTo(i, t2);
            if (t2->Elem != t1->Elem)
            {
                return false;
            }
            else    // I like explicitly putting else even if there is nothing, is this wrong?
            {
            }
        }
        return true;
    }
}
