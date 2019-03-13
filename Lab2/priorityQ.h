#ifndef PRIORITYQ_H
#define PRIORITYQ_H

#include <string>

class priorityQueue {
	private:
        static const int SIZE = 100;
        static const int NumPerLine = 10;
        int * theArray;
        int theSize;
        int numElements;
    public:
        priorityQueue();
        priorityQueue(int size);
        ~priorityQueue();
		void addValue(int value);
		int getSmallest();
		int getLargest();
		bool isEmpty();
		bool isFull();
        std::string dumpArray();
        void zeroOut();
};


#endif // PRIORITYQ_H
