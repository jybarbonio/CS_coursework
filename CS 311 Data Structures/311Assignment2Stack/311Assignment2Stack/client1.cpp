//CS311 Yoshii
//INSTRUCTION:
//Look for ** to complete this program (Use control-S)
//The output should match my hw1stackDemo.out 

//=========================================================
//HW#: HW1P1 stack application (post-fix evaluation)
//Your name: John Barbonio
//Complier:  gcc
//File type: client program client1.cpp
//===========================================================

using namespace std;
#include <iostream>
#include <stdlib.h>
#include <string>
#include "stack.h"

//Purpose of the program: main method to insert math expressions to stack to test stack class
//Algorithm: LIFO stack where integers are input, chars 0 to 9 are converted to integers,
//			 
int main()
{
	stack postfixstack;  // integer stack
	string expression;   // user entered expression

	cout << "type a postfix expression: ";
	cin >> expression;

	int i = 0;  // character position within expression
	char item;  // one char out of the expression

	int box1;  // receive things from pop
	int box2;  // receive things from pop

	while (expression[i] != '\0')
	{
		try
		{
			item = expression[i];  // current char

			// ** do all the steps in the algorithm given in Notes-2
			if (isdigit(item))
			{	
				// one line conversion from int to char
				postfixstack.push((int)item - (int)'0');
			}
			else if (item == 43) // if item char is operator, pop the two operands
			{
				int result;		//  used to store addition result
				int temp;		//	variable used to get popped elem by reference
								//	variables to box1, box2

				postfixstack.pop(temp);
				int box1 = temp;
				postfixstack.pop(temp);
				int box2 = temp;

				result = (box2  + box1);	// addition of box2 and box1 ints
				postfixstack.push(result);	// pushes char on stack
														//		char conversions are used in respect to client1
			}											//		but stacktest.cpp uses strictly int so header typedef is int
			else if (item == 45)
			{
				int result;		// used to store addition result
				int temp;		// temp variable used to get popped elem by reference
								//		passes variables to box1, box2

				postfixstack.pop(temp);
				int box1 = temp;
				postfixstack.pop(temp);
				int box2 = temp;

				result = (box2 - box1);
				postfixstack.push(result);
			}
			else if (item == 42)
			{
				int result;		// used to store addition result
				int temp;		// temp variable used to get popped elem by reference
								//		passes variables to box1, box2

				postfixstack.pop(temp);
				int box1 = temp;
				postfixstack.pop(temp);
				int box2 = temp;

				result = (box2 * box1);
				postfixstack.push(result);
			}
			else if (item == 47)
			{
				int result;		// used to store addition result
				int temp;		// temp variable used to get popped elem by reference
								//		passes variables to box1, box2

				postfixstack.pop(temp);
				int box1 = temp;
				postfixstack.pop(temp);
				int box2 = temp;

				result = box2 / box1;
				postfixstack.push(result);
			}
			else
			{
				throw "An unknown error has occurred. Check for invalid characters";
			}
			// end of if
		} // this closes try
	   // Catch exceptions and report problems and quit the program now (exit(1)). 
	   // Error messages describe what is wrong with the expression.
		catch (stack::Overflow o)
		{
			cerr << o.getOverflowError() << endl;
			exit(1);
		}
		catch (stack::Underflow u)
		{
			cerr << u.getUnderflowError() << endl;
			exit(1);
		}
		catch (char const* errormsg) // for invalid item case
		{
			cerr << errormsg << endl;
			exit(1);
		}

		// go back to the loop after incrementing i
		i++;
	}// end of while

 // After the loop successfully completes: 
 // Pop the result and show it.
	int result;
	postfixstack.pop(result);
	std::cout << result << std::endl;
	// If anything is left on the stack, an incomplete expression 
	// was found so inform the user.
	if (postfixstack.isEmpty() == false)
	{
		std::cout << "Attention: The stack was not fully emptied. The expression is incomplete." << std::endl;
	}

}// end of the program
