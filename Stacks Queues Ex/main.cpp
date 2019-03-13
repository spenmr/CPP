#include <iostream>
#include <iomanip>
#include <stdexcept>

#include "Stack.h"
#include "Queue.h"

using namespace std;

int main()
{

    const int SIZE = 10;

            // Stack tests
    cout << "Stack Tests" << endl;
    Stack theStack(SIZE/2);

        // test overloading stack
    for(int i = 0; i < SIZE; i++)
        theStack.push(i*i);

        //Check isFull and isEmpty
    cout << "The Stack" << (theStack.isFull() ? " is " : " is not ") << "full" << endl;
    cout << "The Stack" << (theStack.isEmpty() ? " is " : " is not ") << "empty" << endl;

        //Display the contents
    for(int i = 0; i < SIZE; i++)
        cout << setw(4) << theStack.pop();
    cout << endl;

            //Check isFull and isEmpty
    cout << "The Stack" << (theStack.isFull() ? " is " : " is not ") << "full" << endl;
    cout << "The Stack" << (theStack.isEmpty() ? " is " : " is not ") << "empty" << endl;


        // test taking too many
    try {
        cout << theStack.pop() << endl;
    }
    catch(underflow_error & e)
    {
        cout << "Exception caught: " << e.what() << endl;
    }

        // Test Queue
    cout << "\n\nQueue Tests" << endl;
    Queue theQueue(SIZE/2);

        // test overloading stack
    for(int i = 0; i < SIZE; i++)
        theQueue.addTail(i*i);

        //Check isFull and isEmpty
    cout << "The Queue" << (theQueue.isFull() ? " is " : " is not ") << "full" << endl;
    cout << "The Queue" << (theQueue.isEmpty() ? " is " : " is not ") << "empty" << endl;

        //Display the contents
    for(int i = 0; i < 3; i++)
        cout << setw(4) << theQueue.removeHead();
    cout << endl;

    for(int i = 0; i < 2; i++)
        theQueue.addTail(2*i + 1);

    while ( !theQueue.isEmpty() )
            cout << setw(4) << theQueue.removeHead();
    cout << endl;

            //Check isFull and isEmpty
    cout << "The Queue" << (theQueue.isFull() ? " is " : " is not ") << "full" << endl;
    cout << "The Queue" << (theQueue.isEmpty() ? " is " : " is not ") << "empty" << endl;

        // test taking too many
    try {
        cout << theQueue.removeHead() << endl;
    }
    catch(QueueEmpty & e)
    {
        cout << "Exception caught: " << e.what() << endl;
    }

    return 0;
}
