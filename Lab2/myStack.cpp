#include "mystack.h"
#include <iostream>

myStack::myStack(){
    theQueue = new dequeue;
}

myStack::myStack(int size){
    theQueue = new dequeue(size);
    theQueue->zeroOut();
}

void myStack::push(int value){
    if ( theQueue->isFull() ){
        // do something about it
    }
    theQueue->addLeft(value);
}

int myStack::pop(){
    if ( theQueue->isEmpty() ){
        // do someting about it
    }
    return theQueue->getLeft();
}

int myStack::peek(){
    if ( theQueue->isEmpty() ){
        //do something about it
    }
    int temp = theQueue->getLeft();
    theQueue->addLeft(temp);
    return temp;
}

std::string myStack::dumpIt(){
    return theQueue->dumpArray();
}
