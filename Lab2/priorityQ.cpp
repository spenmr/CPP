#include "priorityQ.h"
#include <iomanip>
#include <sstream>

priorityQueue::priorityQueue(){
        priorityQueue(SIZE);
}

priorityQueue::priorityQueue(int size){
    theArray = new int[size];
    theSize = size;
    numElements = 0;
}

priorityQueue::~priorityQueue(){
    delete [] theArray;
}

void priorityQueue::addValue(int value){
	if ( isFull() ){
		// take care of the problem
	}
	theArray[numElements++] = value;
}

int priorityQueue::getSmallest(){
	if ( isEmpty() ){
		// take care of the problem
	}
	int small = theArray[0];
	int index = 0;
	for ( int i = 1; i < numElements; i++ ) {
		if ( theArray[i] < small ) {
			small = theArray[i];
			index = i;
		}
	}
	theArray[index] = theArray[--numElements];
	return small;
}

int priorityQueue::getLargest(){
	if ( isEmpty() ){
		// take care of the problem
	}
	int big = theArray[0];
	int index = 0;
	for ( int i = 1; i < numElements; i++ ) {
		if ( theArray[i] > big ) {
			big = theArray[i];
			index = i;
		}
	}
	theArray[index] = theArray[--numElements];
	return big;
}

bool priorityQueue::isEmpty(){
	return numElements == 0;
}

bool priorityQueue::isFull(){
	return numElements == theSize;
}

std::string priorityQueue::dumpArray(){
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

void priorityQueue::zeroOut(){
    for ( int i = 0; i < theSize; i++ ){
        theArray[i] = 0;
    }
}
