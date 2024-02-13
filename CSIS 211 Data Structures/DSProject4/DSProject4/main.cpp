/*
main.cpp
John Barbonio
6/27/2020
: This is main where LinkList.h and its various derivatives are tested for their compatibility with each other and to do assigned operations,
and this main tests the functionality of double linked lists
*/
#include "PairList.h"
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "RPN.h"
#include "InfixNotation.h"

int main() 
{
// stage 1: DblLinkedList test
    /*
    try 
    {
        LinkedList<std::string> s_list;

        s_list.addToEnd("B");
        s_list.addToEnd("C");
        s_list.addToEnd("D");
        s_list.addToEnd("E");
        s_list.printList();

        std::cout << std::endl;

        s_list.addToFront("A");
        s_list.printList();
        std::cout << std::endl;

        //s_list.insert("O", "PLUG0", false);   // will throw an exception as element will not be found in stack
        //s_list.insert("O", "PLUG0", true);   // will throw an exception as element will not be found in stack

        s_list.insert("A", "BEFORE PLUG A", true);
        s_list.insert("A", "AFTER PLUG A", false);

        s_list.insert("E", "BEFORE PLUG E", true);
        s_list.insert("E", "AFTER PLUG E", false);

        s_list.printList();
        std::cout << std::endl;

        std::cout << s_list.contains("A") << std::endl;
        std::cout << s_list.contains("AFTER PLUG E") << std::endl;
        // std::cout << s_list.contains("Z") << std::endl; // will cause an exception to be thrown

        s_list.deleteNode("AFTER PLUG A");
        s_list.deleteNode("BEFORE PLUG A");
        s_list.deleteNode("AFTER PLUG E");
        s_list.deleteNode("BEFORE PLUG E");
        // s_list.deleteNode("Unavailable");    // will cause an exception to be thrown

        s_list.printList();



    }
    catch(LinkedListException e) 
    {
        std::cout << e.query() << std::endl;
    }
    */


// stage 2: Stack test
    /*
    try
    {
        Stack<int> st;
        st.push(5);
        st.push(10);
        int test = st.peek();

        std::cout << "result 1: " << test << std::endl;

        int i1 = st.pop();
        int i2 = st.pop();
        std::cout << "Popped: " << i1 << std::endl;
        std::cout << "Popped: " << i2 << std::endl;

        //st.pop(); // causes exception because it's empty after the first two pops

        ///int test2 = st.peek();   // causes exception because it's looking at an empty stack
        //std::cout << "result 2: " << test2 << std::endl;

        st.push(15);
        st.push(25);
        st.push(30);
        std::cout << "Is it full? " << st.full() << std::endl;
        std::cout << "Is it empty? " << st.empty() << std::endl;

        int s1 = st.pop();
        int s2 = st.pop();
        int s3 = st.pop();
        std::cout << "Popped: " << s1 << std::endl;
        std::cout << "Popped: " << s2 << std::endl;
        std::cout << "Popped: " << s3 << std::endl;


        std::cout << "Is it full? " << st.full() << std::endl;
        std::cout << "Is it empty? " << st.empty() << std::endl;


        int test3 = st.peek();
        std::cout << "result 3: " << test3 << std::endl;


    }
    catch (LinkedListException e) 
    {
        std::cout << e.query() << std::endl;
    }
    */

// stage 3: Queue test
    /*
    Queue<int> q;

    q.enqueue(5);
    std::cout << q.peek() << std::endl;

    q.dequeue();
    std::cout << q.isEmpty() << std::endl;
    std::cout << q.isFull() << std::endl;
    */

// stage 4: RPN test
    /*
    try 
    {
        RPN rpn("3            2     5             *     +");
        rpn.printList();

        rpn.clear();

        rpn.solve("3 2 5 * +");
        rpn.printList();

        rpn.clear();
        rpn.clear(); // <-- causes exception, here for exception testing

    }
    catch(LinkedListException e) 
    {
        std::cout << e.query() << std::endl;
    }
    */
    
// stage 5: infix calculator test

    try 
    {
        InfixNotation in;
        //std::string output = in.infixToPostfix("3 + 2 * 5");
        std::string output = in.infixToPostfix("A * ( B + C * D ) + E");


        std::cout << "Result: " << output << std::endl;

        in.solve(output);
        in.printList();


        /*
            RPN rpn2;
            rpn2.solve(output);
            rpn2.printList();
            rpn2.clear();
        */
    }
    catch(LinkedListException e) 
    {
        std::cout << e.query() << std::endl;
    }

}