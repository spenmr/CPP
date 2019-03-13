//main.cpp
// testing driver
#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "ArrayClass.h"


using namespace std;

	// local helper functions
void fillAndShow(ArrayClass &arr);


int main()
{
	int numDeleted;
	srand (time(NULL));
		// test default constructor
	cout << "\ntesting default Constructor" << endl;
	ArrayClass arrayOne;
	fillAndShow(arrayOne);

		// test overloaded constructro
	cout << "testing overloaded Constructor" << endl;
	ArrayClass arrayTwo(42);
	fillAndShow(arrayTwo);

		// delete all
	cout << "testing deleting all elements" << endl;
	numDeleted = 0;
	while ( arrayTwo.delElem() ){
		numDeleted++;
	}
	cout << "deleted " << numDeleted << " and now there are " << arrayTwo.howMany() << endl;
	cout << "they are:\n";
	cout << arrayTwo.curElems() << endl;

		// show that delete largest works
		// fill array with random numbers
	cout << "testing removing largest elements" << endl;
	fillAndShow(arrayTwo);

		// delete five largest
	for ( int i = 0; i < 5; i++ )
	{
		cout << "removed " << arrayTwo.getLargest() << endl;
	}

	cout << "now there are " << arrayTwo.howMany() << " elements " << endl;
	cout << "they are:\n";
	cout << arrayTwo.curElems() << endl;

		// show that remove duplicates works
		// start with new array with known values
	cout << "testing remove duplicates" << endl;
	ArrayClass arrayThree(15);
	arrayThree.addElem(10);
	arrayThree.addElem(12);
	arrayThree.addElem(22);
	arrayThree.addElem(10);
	arrayThree.addElem(22);
	arrayThree.addElem(22);
	arrayThree.addElem(23);
	arrayThree.addElem(45);
	arrayThree.addElem(47);
	arrayThree.addElem(5);
	arrayThree.addElem(22);
	arrayThree.addElem(21);
	arrayThree.addElem(37);
	arrayThree.addElem(33);
	arrayThree.addElem(6);

	cout << " starts with " << endl;
	cout << arrayThree.curElems();

	arrayThree.deleteDups();

	cout << " ends with " << endl;
	cout << arrayThree.curElems();

		// testing sorting array
	cout << "Now testing sorting in main" << endl;
	ArrayClass arrayFour(55);
	fillAndShow(arrayFour);

	ArrayClass arrayFive(arrayFour.howMany());
	while ( arrayFour.howMany() > 0 )
	{
		arrayFive.addElem(arrayFour.getLargest());
	}
	cout << " starting array has now " << arrayFour.howMany() << " elements " << endl;
	cout << " ending array now has " << arrayFive.howMany() << " elements " << endl;
	cout << " they are: " << endl;
	cout << arrayFive.curElems() << endl;

	cout << "Now testing class sort method big to small" << std::endl;
	ArrayClass arraySix(55);
	fillAndShow(arraySix);
	cout << " after sorting they are " << endl;
	arraySix.sortBigSmall();
	cout << arraySix.curElems() << endl;


	cout << "Now testing class sort method small to big" << std::endl;
	ArrayClass arraySeven(55);
	fillAndShow(arraySeven);
	cout << " after sorting they are " << endl;
	arraySeven.sortSmallBig();
	cout << arraySeven.curElems() << endl;
	return 0;
}

void fillAndShow(ArrayClass &arr){

	int value;

	cout << "starts with " << arr.howMany() << endl;

	do {
		value = rand() % 1000;
	} while ( arr.addElem( value) );

	cout << "ends with " << arr.howMany() << endl;
	cout << "they are:\n";
	cout << arr.curElems() << endl;
}
