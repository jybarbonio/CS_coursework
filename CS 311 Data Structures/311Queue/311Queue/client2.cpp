//CS311 Yoshii
//INSTRUCTION:
//Look for ** to complete this program 
//The string output should match my hw1queueDemo.out 

//=========================================================
//HW#: HW1P2 queue application (generate all strings)
//Your name: John Barbonio
//Complier:  gcc
//File type: client program client2.cpp
//===========================================================

using namespace std;
#include <iostream>
#include <stdlib.h>
#include <string>
#include "queue.h"

//Purpose of the program: To test queue program by filling with 50 items, followed by
//      proper error handling once Queue is overflowed by client
//Algorithm: uses a queue FIFO data structure, where elements are added at the top of the array
//      and lower elements are processed first. For client2.cpp, adds three elements at start
//      then prints removed front elements, and adds three new elements with letters appended. loops forever
int main()
{ // ** "A", "B", "C" in the queue
    queue Q;
    Q.add("A");
    Q.add("B");
    Q.add("C");
  // ** while loop -- indefinitely while(true)
    while (true)    // infinite loop, like while(1)
    {
        try
        {
            el_t temp;      // temp variable to hold removed element for print before deletion

            Q.remove(temp);     // remove element, pass by ref to temp
            cout << temp << endl;   // print removed or popped element
            Q.add(temp + "A");      // append "A" to temp str
            Q.add(temp + "B");      // append "B" to temp str
            Q.add(temp + "C");      // append "C" to temp str
        }
        // catch overflow error if array is full
        catch (queue::Overflow o)
        {
            cerr << o.getOverflowError() << endl;
            exit(1);
        }
        // catch underflow error if array is empty
        catch (queue::Underflow u)
        {
            cerr << u.getUnderflowError() << endl;
            exit(1);
        }
        // for other errors that are not an Overflow or Underflow, just in case
        catch (char const* errmsg)  
        {
            cerr << errmsg << endl;
            exit(1);
        }
        // end of loop
    }

}

