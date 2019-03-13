// ArrayClass.h
//  array class definition
//  Jim Bailey C++ solution


#ifndef ARRAYCLASS_H
#define ARRAYCLASS_H


#include <string>
#include <sstream>
#include <iomanip>

class ArrayClass {

	private:
		static const int DEFSIZE = 100;
		int numElems;
		int curSize;
		int * arr;

	public:
		ArrayClass(int sz = DEFSIZE);
		~ArrayClass();
		bool addElem(int val);
		bool delElem();
		int howMany();
		std::string curElems();
		int getLargest();
		void deleteDups();
		void sortBigSmall();
		void sortSmallBig();
};


#endif
