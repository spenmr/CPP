#include <iostream>
#include "List.h"

using namespace std;

int main()
{
    List theList;

        // Test it as a stack
        // Push on three values
    theList.addHead(3);
    theList.addHead(5);
    theList.addHead(12);

        // Should get back in reverse order
    cout << "Stack output " << endl;
    cout << "Should be 12, is " << theList.removeHead() << endl;
    cout << "Should be 5, is " << theList.removeHead() << endl;
    cout << "Should be 3, is " << theList.removeHead() << endl;
    
        //Now test find
    theList.addHead(10);
    theList.addHead(20);
    theList.addHead(30);
    theList.addHead(40);
    theList.addHead(50);
    
    cout << endl << endl << "Testing find: ";
    cout << "Should get 10 found, 5 not found" << endl;
    cout << "10 " << (theList.findValue(10)? "is": "is not") << " there" << endl;
    cout << "5 " << (theList.findValue(5)? "is": "is not") << " there" << endl;

        //Now test findRemove on first, middle, and last
    cout << endl << endl << "Testing findRemove" << endl;
    theList.findRemove(10);
    theList.findRemove(30);
    theList.findRemove(50);

    cout << "Should be 40, is " << theList.removeHead() << endl;
    cout << "Should be 20, is " << theList.removeHead() << endl;
    
        //Now test removing from empty list
    cout << endl << endl << "Testing remove on empty list" << endl;
    try {
        theList.removeHead();
    } catch (underflow_error &e ) {
        cout << "Exception caught: " << e.what() << endl;
    }



    return 0;
}
