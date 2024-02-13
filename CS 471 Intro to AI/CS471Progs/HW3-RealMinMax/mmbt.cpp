#include "mmbt.h"
#include <math.h>
#include <iostream>
using namespace std;

// Yoshii - Min Max BST implementation file
// You must complete all ** lines
// Use ident() to indent as I did in my output
// Check your output against mine


// ======== Utility Functions for Min Max ==============

int maxof(int A, int B)
{ if (A>B) return A;
  else return B;
}

int minof(int A, int B)
{ if (A<B) return A;
  else return B;
}

// We need to know even level or not to determine whether
// it is for MAX or MIN
bool iseven(int L)
{ if ( (L%2) == 0)
     return true; else return false; } 


// indents L amount to show level changes in display
void indent(int L)
{ for (int i = 1; i <= L; i++)
    cout << " ";
}

//===== Public Functions ===============

// constructor  initializes Root and Bottom
MMBT::MMBT()
{
   Root = NULL;   // This is an empty tree
   cout << "Bottom Level is? " ; cin >> Bottom;
}

// destructor must completely destroy the tree
MMBT::~MMBT()
{
   dtraverse(Root); // traverse to delete all vertices in post order
   Root = NULL;
}

// traverse the MM tree in depth first for 3 different reasons
void MMBT::Traverse(int mode)
{
  string P = "-"; // opeator path begins with -

  // pass -1 as the level built/processed so far
  if (mode == 1)  // to build the tree and assign scores to leaves 
    { Root = new Vertex; 
      DFS(Root, 0, P); }
  if (mode == 2)  // to display the tree
      DFS2(Root, 0); 
  if (mode == 3)  // to do MIMMAX
    {
      DFS3(Root, 0); 
      cout << "Root Value is: "<< Root->Value << endl;     
      cout << "You can make a move now to ";
      if (Root->Left->Value == Root->Value) cout << "the left" << endl;
      else cout << "the right" << endl; }
}//end

// traverse depth first to build the tree and assign values to leaves
void MMBT::DFS(Vertex *V, int L, string Path)
{ 
  // V is at level L
  
  **  // store the operator path so far
  **  // display the path to show what node we are at


  if (L == Bottom)
	  { // at bottom level 
            ** // display the level
            ** // display whether it is for MIN or MAX
            ** // ask the user to enter the score/value
            return;}
	else // not a leaf so need to go down
	  {
            ** // V->Left node should be created
            ** // V->Right node should be created
	    **  // recursively down to left with its level and path
	    ** // recursively down to right with its level and path
          }   
}// end

// traverse depth first to show initial MM tree with paths and leaf values
void MMBT::DFS2(Vertex *V, int L)
{   
  // V is at level L

  **  // display the level and operator path 

  if (L == Bottom)
      cout << "with value " << V->Value << endl;
  else{ // go down to the next level
      **  // recursively down to left with its level to display
      **  // recursively down to right with its level to display 
      }
}//end


// traverse depth first to do MM to assign values to internal nodes 
int MMBT::DFS3(Vertex *V, int L)
{   
  // V is at level L
  int VL, VR;  // child values

  if (L != Bottom ) // for an internal node
      { 
	**  // recursively get the left value and assign it to VL
	** // recursively get the right value and assign it to VR
        ** // Figure out V's value based on VL and VR
           // but it depends on whether you are at MAX or MIN
        ** // Display the level, MAX or MIN, operator path and leaf value
        ** // so that the user can see how MINMAX is working
       return V->Value;
    } 
    return V->Value;  // leaf is reached
}//end

// PURPOSE: Does Post Order traversal of the tree and deletes each vertex
// PARAM:  pointer to the vertex to be deleted
void MMBT::dtraverse(Vertex *V)  // post order traversal
{
  if (V != NULL)
    {
      dtraverse(V->Left);         // visit left sub tree of V
      dtraverse(V->Right);       // visit right sub tree of V
      delete V;                  // deletes V
    }
}//end

