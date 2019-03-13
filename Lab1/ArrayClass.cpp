// ArrayClass.cpp
//  array class code
//  Jim Bailey C++ solution


#include "ArrayClass.h"


ArrayClass::ArrayClass(int sz){
	arr = new int[sz];
	curSize = sz;
	numElems = 0;
}

ArrayClass::~ArrayClass(){
	delete [] arr;
}

	// adds element to array
	// returns true if success
	// returns false if full
bool ArrayClass::addElem(int val){
	if ( numElems < curSize )
	{
		arr[numElems++] = val;
		return true;
	}
	return false;
}

	// deletes the last added
	// element of the array
	// true if array non empty
	// false if empty
bool ArrayClass::delElem(){
	if ( numElems > 0 )
	{
		numElems--;
		return true;
	}
	return false;
}

	// returns how many elements
	// currently in array
int ArrayClass::howMany(){
	return numElems;
}

	// returns a string containing
	// the elements of the array
	// ten per row
std::string ArrayClass::curElems(){
	const int maxRow = 10;
	std::stringstream ss;
	int numOnRow = 0;
	for ( int i = 0; i < numElems; i++ )
	{
		ss << std::setw(6) << arr[i];
		numOnRow++;
		if ( numOnRow >= maxRow ){
			numOnRow = 0;
			ss << "\n";
		}
	}
	ss << "\n";
	return ss.str();
}

	// returns the largest element
	// and deletes it from array
	// if duplicate, returns first
	// assumes array non empty
int ArrayClass::getLargest(){
	int index = 0;
	int largest = arr[index];
	for (int i = 1; i < numElems; i++ )
	{
		if ( arr[i] > arr[index] )
		{
			index = i;
		}
	}
	largest = arr[index];
	arr[index] = arr[--numElems];
	return largest;

}

	// delete dupliate entries
void ArrayClass::deleteDups(){
		// do not bother with empty array
	if ( numElems == 0)
		return;

	for ( int i = 0; i < numElems; i++ )
	{

		for ( int j = i+1; j < numElems; j++ )
		{
			if ( arr[i] == arr[j] )
				arr[j] = arr[--numElems];
		}
	}
}

	// built in sorting, using the getLargest method
void ArrayClass::sortBigSmall(){
		// do not bother with empty array
	if ( numElems == 0)
		return;

	int * tempArray = new int[curSize];
	int saveNumber = numElems;

	for ( int i = 0; i < saveNumber; i++ )
	{
		tempArray[i] = getLargest();
	}
	delete [] arr;
	arr = tempArray;
	numElems = saveNumber;

}

	// built in sorting, using the getLargest method
void ArrayClass::sortSmallBig(){
		// do not bother with empty array
	if ( numElems == 0)
		return;

	int * tempArray = new int[curSize];
	int saveNumber = numElems;

	for ( int i = saveNumber; i>= 0; i-- )
	{
		tempArray[i] = getLargest();
	}
	delete [] arr;
	arr = tempArray;
	numElems = saveNumber;

}
