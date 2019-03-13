#include <iostream>

#include "DList.h"

using namespace std;

int main()
{
    DList theList;

    // Test it as a stack from head
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
    
    //Now test add tail
    theList.addTail(7);
    theList.addTail(11);
    theList.addTail(13);
    
    //should act as queue
    cout << endl << endl << "Testing queue output" << endl;
    cout << "Should be 7, is " << theList.removeHead() << endl;
    cout << "Should be 11, is " << theList.removeHead() << endl;
    cout << "Should be 13, is " << theList.removeHead() << endl;
    
    //Now test stack on add/remove tail
    theList.addTail(77);
    theList.addTail(88);
    theList.addTail(99);
    
    //should act as stack
    cout << endl << endl << "Testing tail stack output" << endl;
    cout << "Should be 99, is " << theList.removeTail() << endl;
    cout << "Should be 88, is " << theList.removeTail() << endl;
    cout << "Should be 77, is " << theList.removeTail() << endl;
    
    
    //Now test queue on addhead/remove tail
    theList.addHead(2);
    theList.addHead(4);
    theList.addHead(6);
    
    //should act as stack
    cout << endl << endl << "Testing head added tail remove queue output" << endl;
    cout << "Should be 2, is " << theList.removeTail() << endl;
    cout << "Should be 4, is " << theList.removeTail() << endl;
    cout << "Should be 6, is " << theList.removeTail() << endl;
    
    return 0;
}
