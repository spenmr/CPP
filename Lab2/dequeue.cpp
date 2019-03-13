#include "dequeue.h"
#include <iomanip>
#include <sstream>


dequeue::dequeue(){
        dequeue(SIZE);
}

dequeue::dequeue(int size){
    theArray = new int[size];
    theSize = size;
    numElements = 0;
    right = theSize;
    left = -1;
}

dequeue::~dequeue(){
    delete [] theArray;
}

void dequeue::addRight(int value){
    if ( numElements == theSize ){
        // do something about it
    }
    if ( right  == 0 ){
        right = theSize;
    }
    theArray[--right] = value;
    numElements++;
}

void dequeue::addLeft(int value){
    if ( numElements == theSize ) {
        // do someting about it
    }
    if ( left == theSize - 1 ){
        left = -1;
    }
    theArray[++left] = value;
    numElements++;
}

int dequeue::getRight(){
    if ( numElements == 0 ){
        // do something about it
    }
    numElements--;
	if ( right == theSize ){
        right = 0;
    }
    int temp = theArray[right++];
    return temp;
}

int dequeue::getLeft(){
    if ( numElements == 0 ){
        // do something about it
    }
    numElements--;
	if ( left == -1 ){
        left = theSize - 1;
    }
    int temp = theArray[left--];
    return temp;
}


bool dequeue::isEmpty(){
    return numElements == 0;

}

bool dequeue::isFull(){
    return numElements == theSize;
}

std::string dequeue::listRightLeft(){
    std::string output = "";
    int lineCount = 0;
    int current = right;
    for ( int i = 0; i < numElements; i++ ){
        std::stringstream outString;
        outString << std::setw(6) << theArray[current];
        output += outString.str();
        lineCount++;
        if ( lineCount >= NumPerLine ){
            lineCount = 0;
            output += "\n";
        }
        current++;
        if ( current == theSize ){
            current = 0;
        }
    }
    output += "\n";
    return output;
}


std::string dequeue::listLeftRight(){
    std::string output = "";
    int lineCount = 0;
    int current = left;
    for ( int i = 0; i < numElements; i++ ){
        std::stringstream outString;
        outString << std::setw(6) << theArray[current];
        output += outString.str();
        lineCount++;
        if ( lineCount >= NumPerLine ){
            lineCount = 0;
            output += "\n";
        }
        current--;
        if ( current == -1 ){
            current = theSize - 1;
        }
    }
    output += "\n";
    return output;
}

std::string dequeue::dumpArray(){
    std::string output = "[";
    int lineCount = 0;
    for ( int i = 0; i < theSize; i++ ){
        std::stringstream outString;
        outString << std::setw(3) << theArray[i];
        output += outString.str();
        lineCount++;
        if ( lineCount >= NumPerLine ){
            lineCount = 0;
            output += "\n";
        }
    }
    output += "]\n";
    return output;
}

void dequeue::zeroOut(){
    for ( int i = 0; i < theSize; i++ ){
        theArray[i] = 0;
    }
}



