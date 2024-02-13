
#include<iostream>
#include<stdlib.h>
#include<fstream>
#include"stack.h"  // ** can be removed
#include<vector>
#include<string>
using namespace std;

//---------------------------------------
// CS421 File ll1.cpp for HW3A LL1 Table-Driven Parser
// Your name: John Barbonio
//---------------------------------------

// Complete this to fit the HW3A specification - look for **
// Must have the same types of tracing couts as my demo program.

// Feel free to use a stack class or use a vector
// to implement your stack.  The stack will contain characters.

vector<char> M[3][2];  // the table of rules 
                       // 3 rows for S, A, B
                       // 2 rows for 2, 3
       // Each slot contains a rule's right side
       // which is a vector of characters

stack stck;     // using stack.h from CS 311 Yoshii

//  ------- conversion functions ------------------------


// to convert non-terms S, A, B to table rows 0, 1, 2
int toRow(char C)
{
  //**  bunch of if then else
    if (C == 'S')
    {
        return 0;
    }
    else if (C == 'A')
    {
        return 1;
    }
    else if (C == 'B')
    {
        return 2;
    }
}

// to convert '2' and '3' to table columns 0 and 1 
int toCol(char c)
{
  // ** bunch of if then else
  // when c is 2 return a 0
    if (c == '2')
    {
        return 0;
    }
  // when c is 3 return a 1
    else if (c == '3')
    {
        return 1;
    }
}

// to convert row 0, 1, 2 to non-terms S, A and B
char toNonterm(int r)
{
  // ** bunch of if then else
    if (r == 0) 
    {
        return 'S';
    }
    else if (r == 1)
    {
        return 'A';
    }
    else if (r == 2) 
    {
        return 'B';
    }
}


// ** Then complete the following functions.-----------------------------

// to display a rule's rhs which is in vector V
void displayVector(vector<char> V) 
{
  // ** display V horizontally e.g. 2 A 2
    vector<char>::iterator i;

    for (i = V.begin(); i < V.end(); ++i) 
    {
        cout << *i;
    }
    cout << "\t";
}

// to read in the rules into M, make sure ; is not stored
void readrules()
{ 
  ifstream fin ("rules", ios::in);

  // For each line of "rules" (e.g. S  2 A 2 ;) 
  // The first char of a line determines the row of M
  // The second char of a line determine the column of M  
  // Note that each entry of M (the second char up to ;)
  // will be a vector representing 
  // the right hand side of a rule (rhs)

    int s = 0;      // state for each elem in line
    char c;          // char from fin
    int row = 0;          // row
    int col = 0;          // col

    while (!fin.eof())
    {
        fin >> c;
        if (s == 0)     // if column is greater than zero, then label should've already been set
        {
            if (c == 'S' || c == 'A' || c == 'B')
            {
                row = toRow(c);
                s++;        // advance state after getting row index
            }
        }
        else if (s == 1)
        {
            if (c == '2' || c == '3')
            {
                col = toCol(c);
                M[row][col].push_back(c);
                s++;        // advance state after getting col index
            }
        }
        else if (s == 2 && c != ';')    // state 3, getting row col index is complete by this point
        {
            if (isalnum(c)) 
            {
                M[row][col].push_back(c);
            }
        }
        else if (c == ';')      // end of line, show filled vector rule
        {
            s = 0;  // reset state at end of line/for newline
        }
    }

  // ** Display the table nicely  
  //    use toNonterm to show row labels (S, A, B)
  //    use displayVector for each content 
    for (int i = 0; i < 3; i++)     // row 
    {

        cout << toNonterm(i) << ": ";
        for (int j = 0; j < 2; j++)     // col
        {
            if (M[i][j].empty()) 
            {
                cout << "";
            }
            else 
            {
                displayVector(M[i][j]);
            }
        }
        cout << endl;
    }

}

//  pushes V contents to the stack 
void addtostack(vector<char> V)
{
    cout << "Pushing rhs of a rule to the stack." << endl;
    // **  be careful of the order
     // because 3 2 2 means 3 will be at the top of the stack
    std::vector<char>::iterator i;
    char t;
    stck.pop(t); // pop char that invoked rule as it is expanded into the rule

    for (i = V.begin(); i < V.end(); ++i)       // you want the front chars to be at the top of the stack, so reverse read 
    {
        stck.push(*i);      // push whatever is in i
    }
}

int main()
{ 
  readrules();  // M is filled and displayed 

  string ss;
  cout << "Enter a string made of 2's and/or 3's: ";
  cin >> ss;

  // ** push 'S' onto the stack to start

  cout << "Stack:";
  stck.push('S');
  // ** display the stack vertically from top to bottom
    stck.displayAll();
  int i = 0;  // index for ss
  while (ss[i] != '\0')  // for each char of ss
  {
      // Based on ss[i] and 
      //    the top of stack, update the stack: 
      // ** note that empty stack will cause immediate failure  
      // ** note that top of stack terminal and ss[i] mismatching
      //    will cause immediate failure 
      // ** note that no entry in M for the top of stack (non-terminal)
      //    and ss[i] will cause immediate
      //    failure  (use toRow and toCol to look up M)
      // ** otherwise, addtoStack the M entry based on ss[i] and the top of stack
        char tc = 0;
        int rw = 0;
        int cl = toCol(ss[i]);
        if (!stck.isEmpty())
        {
            stck.topElem(tc);
            rw = toRow(tc);
        }
        char t; // t serves no purpose but to fill needed param for pass by ref in topElem
        cout << "Current char from string is: " << ss[i] << endl;

        if (isdigit(tc) && ss[i] == tc)
        {
            cout << "MATCH!" << endl;
            stck.pop(t);
            i++;        // move to next char in string as prev char has been handled
        }
        else if (isalpha(tc) && !M[rw][cl].empty())     // if there is a rule that matches the char at the index
        {
            addtostack(M[rw][cl]);
        }
        // avoid recursion by breaking if char does not match rule
        else
        {
            i = ss.size(); // breakout by going to end of string which has failed a char
        }
        stck.displayAll();
        
    } // end of string


  // ** Here, check for success for failure based on stack empty or not
  if (stck.isEmpty())     // stack is empty and all chars were handled
  {
      cout << "ACCEPTED. STR EMPTIED" << endl;
  }
  else if (!stck.isEmpty())    // stack is empty but not all chars were handled
  {
      cout << "REJECTED. NO RULE FOR CHAR" << endl;
  }
  else 
  {
      cout << "REJECTED. MISMATCH OR MISSING RULE HANDLE." << endl;
  }

}// end of main
